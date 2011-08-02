#ifndef _CTL_LINKEDLIST_HPP_
#define _CTL_LINKEDLIST_HPP_

#include <CTL/collection.hpp>

namespace CTL {
  
template <class T>
struct node {
  T   value;
  struct node * next;
  struct node(const T element) : value(element), next(NULL) {} 
};

template <class T>
class LinkedList : public Collection {
public:
  // @overload
  bool          contains(const T element) const;
  // @overload
  bool          isEmpty() const;
  // @overload
  T           * toArray() const;
  // @overload
  size_t        getSize() const;
  // @overload
  bool          push(const T element);
  // @overload 
  bool          pop();
  
  struct node<T>  * const getHead() const ;
  struct node<T>  * const getTail() const ;
  bool          remove(const T element);
  size_t        removeAll(const T element);
  
  LinkedList();
  LinkedList(const T * const array, int size);
  LinkedList& operator=(const LinkedList & other);
  
  ~LinkedList();
private:
  struct node * head;
  struct node * current;
  int           size;
};

}
#endif
