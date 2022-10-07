#pragma once 

namespace learn
{

template <typename DataType> 
class rbtree
{
public: 
  

private:
  enum class color
  {
    red,
    black
  };

  struct node
  {
    DataType data;
    node* left;
    node* right;
    node* parent;
    color c;

    node()
      : left{nullptr}
      , right{nullptr}
      , parent{nullptr}
      , c{color::red}
    {}
  };
};

} // namespace learn