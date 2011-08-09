#ifndef _CTL_HEAP_HPP_
#define _CTL_HEAP_HPP_

#include <CTL/collection.hpp>

namespace CTL {

template <class T>
class Heap : public Collection<T> {
public:
  // @overload
  bool      isEmpty()                 const;
  // @overload
  bool      contains(const T element) const;
  // @overload
  T *       toArray()                 const;
  // @overload
  size_t    getSize()                 const;
  // @overload
  bool      push(const T element);
  // @overload
  bool      pop();
  // @overload
  void      clear();
  
  const T   top()                     const;

  Heap(const unsigned max_size = 100);

  Heap(const T * const array, const size_t size);
  ~Heap();

private:
  
  Heap<T>&  operator=(const Heap<T> origin);
  void      heapify(size_t index);
  bool      find(size_t index, const T element) const;
  T       * array;
  size_t    size;
  size_t    max_size;
};

}

#endif
