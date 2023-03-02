#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <list>

template <class T>
class Stack : private std::list<T>
{
public:
  Stack() {}

  T top() const;
  T pop();
  void push(const T& newValue);
  bool isEmpty() const;
};

#endif
