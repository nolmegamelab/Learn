#include <mutex>
#include <thread>

#include "doctest.h"
#include "benchmark.hpp"
#include "rx/multi_thread_worker.hpp"


#define TEST_DISABLE(x) static void __ff_bm_()

TEST_CASE("benchmark timer")
{
  constexpr int test_count = 1;

  SUBCASE("steady timer")
  {
    std::thread::id tid, tid1, tid2;
    std::chrono::steady_clock::time_point tp, tp1;
    std::atomic<int> value = 0;
    std::mutex mutex;
    std::condition_variable cv;

    {
      std::lock_guard lock(mutex);
      value = 0;
    }

    auto& bm = tqa::benchmark::instance();

    bm.mark_begin("steady_timer_all");

    rx::multi_thread_worker worker(8);
    worker.start();

    tid = std::this_thread::get_id();
    tp = std::chrono::steady_clock::now();

    bm.mark_begin("steady_timer_create");

    for (int i = 0; i < test_count; ++i)
    {
      worker.steady_timer().once("test/once", i + 1, [&] {
        std::lock_guard lock(mutex);
        tid1 = std::this_thread::get_id();
        tp1 = std::chrono::steady_clock::now();
        ++value;
        }, std::chrono::milliseconds(100));
    }

    bm.mark_end("steady_timer_create");

    while (value < test_count)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    bm.mark_end("steady_timer_all", test_count);

    worker.stop();
  }

  SUBCASE("steady timer. pooling effect")
  {
    std::thread::id tid, tid1, tid2;
    std::chrono::steady_clock::time_point tp, tp1;
    std::atomic<int> value = 0;
    std::mutex mutex;
    std::condition_variable cv;

    {
      std::lock_guard lock(mutex);
      value = 0;
    }

    auto& bm = tqa::benchmark::instance();

    bm.mark_begin("steady_timer_all_pool");

    rx::multi_thread_worker worker(8);
    worker.start();

    tid = std::this_thread::get_id();
    tp = std::chrono::steady_clock::now();

    bm.mark_begin("steady_timer_create_pool");

    for (int i = 0; i < test_count; ++i)
    {
      worker.steady_timer().once("test/once", i + 1, [&] {
        std::lock_guard lock(mutex);
        tid1 = std::this_thread::get_id();
        tp1 = std::chrono::steady_clock::now();
        ++value;
        }, std::chrono::milliseconds(100));
    }

    bm.mark_end("steady_timer_create_pool");

    while (value < test_count)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    bm.mark_end("steady_timer_all_pool", test_count);

    worker.stop();
  }
}