#include <CTL/linkedlist.hpp>

namespace CTL {

template <class T>
bool LinkedList<T>::contains(const T element) const{
  struct node<T> * temp = this->head;
  while(temp){
    if(element == temp->value) return true;
    temp = temp->next;
  }
  return false;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
  return this->size != 0;
}

template <class T>
T * LinkedList::toArray() const {
  T * copy = new T [this->size];
  struct node<T> * temp = this->head;
  for(size_t i = 0; i < size; ++i){
    copy[i] = temp->value;
    temp    = temp->next;
  }
  return copy;
}

template <class T>
size_t LinkedList<T>::getSize() const {
  return this->size;
}

template <class T>
bool LinkedList<T>::push(const T element) {
  struct node<T> * a_node = new node<T>(element);
  this->tail->next  = a_node;
  this->tail        = a_node;
  this->size++;
  return true;
}

template <class T>
bool LinkedList<T>::pop(){
  if(!this->size) return false;
  struct node<T> * temp  = this->head;
  this->head = this->head->next;
  delete temp;
  tihs->size--;
  return true;
}

template <class T>
struct node<T> * const LinkedList<T>::getHead() const {
  return this->head;
}

template <class T>
struct node<T> * const LinkedList<T>::getTail() const {
  return this->tail;
}

template <class T>
bool LinkedList<T>::remove(const T element){
  if(!this->head) return false;
  if(element == this->head->value){
    this->head = this->head->next;
    size--;
    return true;
  }
  struct node<T> * temp1  = this->head;
  struct node<T> * temp2  = this->head->next;
  while(temp2){
    if(element == temp2->value) {
      temp1->next = temp2->next;
      delete temp2;
      size--;
      return true;
    }
    temp1 = temp2;
    temp2 = temp1->next;
  }
  return false;
}

template <class T>
size_t LinkedList<T>::removeAll(const T element) {

}

} // end of namespace CTL
