#ifndef _CTL_LINKEDLIST_HPP_
#define _CTL_LINKEDLIST_HPP_

#include <CTL/collection.hpp>

namespace CTL {
  
template <class T>
struct node {
  T   value;
  struct node * next;
};

template <class T>
class LinkedList : public Collection {
public:
  struct node * getHead();
  struct node * getTail();
  bool          remove(const T element);
  bool          removeAll(const T element);
  // @overload
  bool          contains(const T element) const;
  // @overload
  bool          isEmpty() const;
  // @overload
  int           getSize() const;
  // @overload
  T           * toArray() const;
  // @overload
  bool          add(const T element);
  
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