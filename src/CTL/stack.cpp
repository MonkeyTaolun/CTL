#include <CTL/stack.hpp>
 
#include <new>

namespace CTL {
template <class T>
bool Stack<T>::isEmpty() const{
  return this->size == 0;
}

template <class T>
bool Stack<T>::contains(const T element) const {
  for(size_t i = 0; i < this->size; ++i){
    if(element == this->array[i]) return true;
  }
  return false;
}

template <class T>
T * Stack<T>::toArray() const {
  T * copy = new T [this->size];
  for(size_t i = 0; i < this->size; ++i){
    copy[i] = this->array[i];
  }
  return copy;
}

template <class T>
size_t Stack<T>::getSize() const {
  return this->size;
}

template <class T>
void Stack<T>::clear(){
  this->size  = 0;
}

template <class T>
bool Stack<T>::pop() {
  return this->size != 0 && this->size--;
}

template <class T>
bool Stack<T>::push(const T element) {
  if(this->length == this->max_size) {
    T * morespace = (T * )realloc(array, this->max_size * 2 *sizeof(T) );
    if(morespace != NULL){
      this->array = morespace;
      this->max_size *= 2;
    }
    else {
      free(array);
      throw std::bad_alloc();
    }
  }
  this->array[this->size++] = element;
  return true;
}
/*
T& Stack::top(){
  if(length > 0) return head[length - 1];
  else return 
}
*/
template <class T>
Stack<T>::Stack(size_t max_size){
  this->array     = new T [size];
  this->size      = 0;
  this->max_size  = max_size;
}
template <class T>
Stack<T>::Stack(const T * const array, const size_t size){
  this->array = new T [size * 2];
  for(size_t i = 0; i < size; ++i){
    this->array[i]  = array[i];
  }
  this->size      = size;
  this->max_size  = size * 2;
}
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> origin){
  if(this->array) delete [] this->array;
  this->head      = new T [origin.max_size];
  memcpy(this->head, origin.array, origin.max_size);
  this->size      = origin.size;
  this->max_size  = origin.max_size;
}
template <class T>
Stack<T>::~Stack<T>(){
  delete []this->array;
}

} // end namespace std;

