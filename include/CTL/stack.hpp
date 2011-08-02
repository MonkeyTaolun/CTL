#ifndef _CTL_STACK_HPP_
#define _CTL_STACK_HPP_

#include<CTL/collection.hpp> 

#include <stdlib.h>

namespace CTL {

template <class T>
class Stack{
public  :
  // @overload
  bool    isEmpty()                 const;
  // @overload
  bool    contains(const T element) const;
  // @overload
  T *     toArray()                 const;
  // @overload
  size_t  getSize()                 const;
  // @overload
  bool    pop();
  // @overload
  bool    push(const T element);
  // T     top(); not clear, should return a iterator
   
  // @overload destructor
  ~Stack();

  Stack(size_t max_size  = 20);
  Stack(const T * const array, const size_t size);
  Stack<T>& operator=(const Stack<T> origin);


private :
  T     * array;
  size_t  size;
  size_t  max_size;
};

} // end of namespace CTL

#endif

