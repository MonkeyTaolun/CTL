#ifndef _CTL_COLLECTION_HPP_
#define _CTL_COLLECTION_HPP_

#include <string.h>

namespace CTL {

template <class T>
class Collection {
public:
  virtual bool    isEmpty()                 const = 0;
  virtual bool    contains(const T element) const = 0;
  virtual T *     toArray()                 const = 0;
  virtual size_t  getSize()                 const = 0;
  virtual bool    push(const T element)           = 0;
  virtual bool    pop()                           = 0;
  virtual void    clear()                         = 0;
  virtual ~Collection()                           = 0;
};
template <class T>
inline Collection<T>::~Collection(){}

} // end of namespace CTL

#endif
