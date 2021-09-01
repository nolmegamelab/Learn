#include "doctest.h"
#include "rx/tcp_server.hpp"
#include "rx/tcp_client.hpp"
#include "rx/multi_thread_worker.hpp"
#include "benchmark.hpp"

namespace
{
  union uint32 {
    uint32_t int_val;
    uint8_t bytes[4];
  };

  class test_server : public rx::tcp_server<>
  {
  public:
    explicit test_server(rx::worker* worker) : rx::tcp_server<>(worker) {}

    void on_receive(session_ptr session, const void* data, std::size_t size, std::uint16_t /*hint*/) override
    {
      CHECK(size == 4);

      uint32 value;
      memcpy(value.bytes, data, 4);

      ++value.int_val;
      session->send(value.bytes, 4);

      // RX_INFO_FMT("sent from server: {}", recv_count_);

      ++recv_count_;
    }

    std::size_t receive_count() const
    {
      return recv_count_;
    }

  private:
    std::atomic<std::size_t> recv_count_ = 0;
  };

  class test_client : public rx::tcp_client<>
  {
  public:
    explicit test_client(rx::worker* worker, int initial_echo_count)
      : rx::tcp_client<>(worker)
      , initial_echo_count_(initial_echo_count)
      , recv_count_(0)
    {}

    void on_connect(session_ptr session) override
    {
      uint32 value;
      value.int_val = 1;

      for (int i = 0; i < initial_echo_count_; ++i)
      {
        session->send(value.bytes, 4);
      }
    }

    void on_receive(session_ptr session, const void* data, std::size_t /* size */, std::uint16_t /*hint*/) override
    {
      // CHECK(size == 4);

      ++recv_count_;

      uint32 value;
      memcpy(value.bytes, data, 4);

      // CHECK(value.int_val == (recv_count_+1));

      // RX_INFO_FMT("recv: {}", recv_count_);

      session->send(value.bytes, 4);
    }

    std::size_t receive_count() const
    {
      return recv_count_;
    }

  private:
    int initial_echo_count_;
    std::atomic<std::size_t> recv_count_;
  };
}

TEST_CASE("benchmark tcp")
{

  SUBCASE("single session performance")
  {
    constexpr std::size_t test_count = 1;

    rx::multi_thread_worker worker1(4);
    worker1.start();

    rx::multi_thread_worker worker2(4);
    worker2.start();

    test_server server(&worker1);
    server.listen(9999);

    auto& bm = tqa::benchmark::instance();

    test_client client(&worker1, 1);

    asio::ip::tcp::endpoint endpoint(
      asio::ip::address::from_string("127.0.0.1"), 9999);

    RX_INFO("single session connect start");

    client.async_connect(endpoint);

    bm.mark_begin("single_session_benchmark");

    while (client.receive_count() < test_count)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    RX_INFO("single session test end");

    bm.mark_end("single_session_benchmark", test_count);

    worker1.stop();
    worker2.stop();
  }

  SUBCASE("single session performance - multiple echo")
  {
    constexpr std::size_t test_count = 1000;

    rx::multi_thread_worker worker1(8);
    worker1.start();

    rx::multi_thread_worker worker2(4);
    worker2.start();

    test_server server(&worker1);
    server.listen(9999);

    auto& bm = tqa::benchmark::instance();

    test_client client(&worker1, 256);

    asio::ip::tcp::endpoint endpoint(
      asio::ip::address::from_string("127.0.0.1"), 9999);

    RX_INFO("single session connect start");

    client.async_connect(endpoint);

    bm.mark_begin("single_session_benchmark_multiple_echo");

    while (client.receive_count() < test_count)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    RX_INFO("single session test end");

    bm.mark_end("single_session_benchmark_multiple_echo", test_count);

    worker1.stop();
    worker2.stop();
  }

  SUBCASE("multiple session echo")
  {
    constexpr std::size_t test_count = 1;
    const int test_duration = 1000;

    rx::multi_thread_worker worker1(8);
    worker1.start();

    test_server server(&worker1);
    server.listen(9999);

    auto& bm = tqa::benchmark::instance();

    std::vector<std::shared_ptr<test_client>> clients;

    for (std::size_t i = 0; i < test_count; ++i)
    {
      clients.push_back(std::make_shared<test_client>(&worker1, 256));
    }

    asio::ip::tcp::endpoint endpoint(
      asio::ip::address::from_string("127.0.0.1"), 9999);

    bm.mark_begin("multiple_client_echo");

    for (std::size_t i = 0; i < test_count; ++i)
    {
      clients[i]->connect(endpoint);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(test_duration));

    std::size_t total_echos = 0;

    for (std::size_t i = 0; i < test_count; ++i)
    {
      total_echos += clients[i]->receive_count();
    }

    bm.mark_end("multiple_client_echo", static_cast<int>(total_echos));

    worker1.stop();
  }
}
