#ifndef _CTL_COLLECTION_HPP_
#define _CTL_COLLECTION_HPP_

namespace CTL {

template <class T>
class Collection {
public:
  virtual bool isEmpty()                const = 0;
  virtual bool contains(const T element)const = 0;
  virtual T *  toArray()                const = 0;
  virtual bool add(const T element)           = 0;
  virtual ~Collection()                       = 0;
};
template <class T>
inline Collection<T>::~Collection(){}

} // end of namespace CTL

#endif
