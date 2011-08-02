#ifndef _CTL_QUEUE_HPP_
#define _CTL_QUEUE_HPP_

#include <CTL/collection.hpp>

#include <stdlib.h>

namespace CTL {

template <class T>
class Queue : public Collection {
public:
  // @overload
  bool    isEmpty()                 const;
  // @overload
  bool    contains(const T element) const;
  // @overload
  T     * toArray()                 const;
  // @overload 
  size_t  getSize()                 const; 
  // @overload
  bool    add(const T element);
  
  bool    push(const T element);

  bool    pop();


  Queue(const size_t size = 20);
  Queue(const T * const array, const size_t size);
  Queue<T>& operator= (const Queue<T> origin);

  ~Queue();

private:
  size_t    size;
  T       * array;
  size_t    length;
  size_t    head;
};

} // end of namespace CTL

#endif
