#include <CTL/linkedlist.hpp>

namespace CTL {

template <class T>
bool LinkedList<T>::contains(const T element) const{
  ::Node<T> * temp = this->head;
  while(temp){
    if(element == temp->value) return true;
    temp = temp->next;
  }
  return false;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
  return this->head != NULL ;
}

template <class T>
T * LinkedList<T>::toArray() const {
  size_t size = this->getSize();
  T * copy = new T [this->size];
  ::Node<T> * temp = this->head;
  size_t index  = 0;
  while(temp != NULL){
    copy[index++] = temp->value;
    temp = temp->next;
  }
  return copy;
}

template <class T>
size_t LinkedList<T>::getSize() const {
  size_t size = 0;
  ::Node<T>  * node = this->head;
  while(node){
    size++;
    node  = node->next;
  }
  return size;
}

template <class T>
bool LinkedList<T>::push(const T element) {
  ::Node<T> * node_new = new ::Node<T>(element);
  if(!this->head) {
    this->head  = node_new;
    return true;
  }
  ::Node<T> * node = this->head;
  while(node->next){
    node  = node->next;
  }
  node->next = node_new;
  return true;
}

template <class T>
bool LinkedList<T>::pop(){
  if(!this->head) return false;
  ::Node<T> * node  = this->head;
  this->head = this->head->next;
  delete node;
  return true;
}

template <class T>
void LinkedList<T>::clear(){
  while(this->pop());
}

template <class T>
struct Node<T> * const LinkedList<T>::getHead() const {
  return this->head;
}

template <class T>
bool LinkedList<T>::remove(const T element){
  if(!this->head) return false;
  if(element == this->head->value){
    this->head = this->head->next;
    return true;
  }
  ::Node<T> * temp1  = this->head;
  ::Node<T> * temp2  = this->head->next;
  while(temp2){
    if(element == temp2->value) {
      temp1->next = temp2->next;
      delete temp2;
      return true;
    }
    temp1 = temp2;
    temp2 = temp1->next;
  }
  return false;
}

template <class T>
size_t LinkedList<T>::removeAll(const T element) {
  size_t counter = 0;
  while(this->remove(element)) counter++;
  return counter;
}

template <class T>
LinkedList<T>::LinkedList(): head(NULL){}

template <class T>
LinkedList<T>::LinkedList(const T * const array, size_t size){
  if(!array || !size) {
    this->head  = NULL;
    return;
  }
  this->head = new ::Node <T> (array[0]);
  ::Node <T> * node;
  for(size_t i = 1; i < size; ++i){
    node->next  = new ::Node <T> (array[i]);
    node  = node->next;
  }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList & other){
  this->clear();
  if(other->head) {
    this->head = new ::Node <T> (other->head->value);
  }
  else return;
  ::Node <T> * node1 = this->head;
  ::Node <T> * node2 = NULL;
  ::Node <T> * node3 = other->head->next;
  while(node3){
    node2 = new ::Node <T> (node1->value);
    node1->next = node2;
    node1 = node2;
    // node1 = node1->next = node2;
    node3 = node3->next;
  }
}

} // end of namespace CTL
