#ifndef _CTL_STACK_HPP_
#define _CTL_STACK_HPP_

#include<CTL/collection.hpp> 

#include <stdlib.h>
namespace CTL {

template <class T>
class Stack{
public  :
  // @overload
  bool  isEmpty();
  // @overload
  bool  contains(const T element);
  // @overload
  T *   toArray();
  // @overload
  bool  add(const T element);
  
  bool  pop();
  bool  push(const T element);
  // T     top(); not clear, should return a iterator
   
  // @overload destructor
  ~Stack();

  Stack(size_t size  = 20);
  Stack(const T * const array, const size_t size);
  Stack<T>& operator=(const Stack<T> origin);


private :
  T     * head;
  size_t  length;
  size_t  size;
};

} // end of namespace CTL

#endif

