#pragma once 

namespace Solve
{

template <typename T> // T can be compared with <
class AvlTree
{
  using ValueType = T;

  struct Node
  {
    ValueType value;
    Node* parent;
    Node* left; 
    Node* right;

    Node() 
      : parent(nullptr)
      , left(nullptr)
      , right(nullptr)
    {}

    ~Node()
    {
      delete left;
      delete right;
    }
  };

public:
  AvlTree()
  {
  }

  ~AvlTree()
  {
  }

  Node* Insert(ValueType& v)
  {
  }

  void Delete(Node* node)
  {
  }

  Node* Find(const ValueType& v)
  {
  }

private: 
  Node m_root;
};

} // namespace Solve