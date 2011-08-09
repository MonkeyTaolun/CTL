#ifndef _CTL_QUEUE_HPP_
#define _CTL_QUEUE_HPP_

#include <CTL/collection.hpp>

namespace CTL {

template <class T>
class Queue : public Collection<T> {
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
  bool    push(const T element);
  // @overload
  bool    pop();
  // @overload
  void    clear();

  Queue(const size_t max_size = 20);
  Queue(const T * const array, const size_t size);
  Queue<T>& operator= (const Queue<T> origin);

  ~Queue();

private:
  size_t    max_size;
  T       * array;
  size_t    size;
  size_t    head;
};

} // end of namespace CTL

#endif
