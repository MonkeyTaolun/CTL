#ifndef _CTL_LINKEDLIST_HPP_
#define _CTL_LINKEDLIST_HPP_

#include <CTL/collection.hpp>

template <class T>
struct Node {
  T   value;
  Node<T> * next;
  Node(const T element) : value(element), next(NULL) {} 
};


namespace CTL {
  
template <class T>
class LinkedList : public Collection<T> {
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
  // @overload 
  void          clear();

  ::Node<T>  * const getHead() const ;
  bool          remove(const T element);
  size_t        removeAll(const T element);
  
  LinkedList();
  LinkedList(const T * const array, size_t size);
  LinkedList& operator=(const LinkedList & other);
  
  ~LinkedList();
private:
  ::Node<T>  * head;
};

}
#endif
