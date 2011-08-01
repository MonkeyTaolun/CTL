#include <CTL/stack.hpp>
 
#include <new>

namespace CTL {
template <class T>
bool Stack<T>::isEmpty(){
  return this->length == 0;
}

template <class T>
bool Stack<T>::contains(const T element) {
  for(int i = 0; i < this->length; ++i){
    if(element == head[i]) return true;
  }
  return false;
}

template <class T>
T * Stack<T>::toArray(){
  T * copy = new T [this->length];
  for(int i = 0; i < this->length; ++i){
    copy[i] = head[i];
  }
  return copy;
}
template <class T>
bool Stack<T>::add(const T element) {
  return this->push(element);
}
template <class T>
bool Stack<T>::pop() {
  return this->length != 0 && this->length--;
}
template <class T>
bool Stack<T>::push(const T element) {
  if(length == size) {
    T * morespace = (T * )realloc(head, size * 2 *sizeof(T) );
    if(morespace != NULL){
      head = morespace;
      size *= 2;
    }
    else {
      free(head);
      throw std::bad_alloc();
    }
  }
  head[length++] = element;
  return true;
}
/*
T& Stack::top(){
  if(length > 0) return head[length - 1];
  else return 
}
*/
template <class T>
Stack<T>::Stack(size_t size){
  this->head    = (T *)malloc(size * sizeof(T));
  this->length  = 0;
  this->size    = size;
}
template <class T>
Stack<T>::Stack(const T * const array, const size_t size){
  this->head    = (T *)malloc(size * 2 * sizeof(T));
  for(size_t i = 0; i < size; ++i){
    head[i] = array[i];
  }
  this->length  = size;
  this->size    = size * 2;
}
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> origin){
  if(this->head) free(this->head);
  this->head    = (T *) malloc(origin.size * sizeof(T));
  memcpy(this->head, origin.head, origin.length);
  this->size    = origin.size;
  this->length  = origin.length;
}
template <class T>
Stack<T>::~Stack<T>(){
  free(this->head);
}

} // end namespace std;

