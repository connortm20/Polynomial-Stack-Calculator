#include "Stack.hpp"

using namespace std;

template <class T>
T
Stack<T>::top() const
{
  return list<T>::front();
}

template <class T>
T
Stack<T>::pop()
{
  T answer = top();
  list<T>::pop_front();
  return answer;
}

template <class T>
void
Stack<T>::push(const T &newValue)
{
  list<T>::push_front(newValue);
}

template <class T>
bool
Stack<T>::isEmpty() const
{
  return list<T>::empty(); 
}
