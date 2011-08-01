#include <CTL/queue.hpp>

#include <new>

namespace CTL {

template <class T>
bool Queue<T>::isEmpty() const{
  return this->length == 0;
}

template <class T>
bool Queue<T>::contains(const T element) const {
  for(size_t i = 0; i < this->length; ++i){
    if(element == array[i]) return true;
  }
  return false;
}

template <class T>
T * Queue<T>::toArray() const{
  T * copy = new T [this->length];
  for(size_t i = 0; i <= this->length; ++i){
    copy[i] = array[(head + i) % size];
  }
  return copy;
}

template <class T>
size_t Queue<T>::getSize() const{
  return this->length;
}

template <class T>
bool Queue<T>::add(const T element){
  return this->push(element);
}

template <class T>
bool Queue<T>::pop() {
  if(this->length != 0) {
    this->length--;
    head = (head+1) % size;
    return true;
  }
  return false;
}

template <class T>
bool Queue<T>::push(const T element){
  if(length == size) {
    T * morespace = (T * )realloc(array, size * 2 *sizeof(T) );
    if(morespace != NULL){
      array = morespace;
      size *= 2;
    }
    else {
      free(array);
      throw std::bad_alloc();
    }
  }
  array[(head + (length++)) % size] = element;
  return true;
}

template <class T>
Queue<T>::Queue(const size_t size)
  : size(size),
    array((T *) malloc(size * sizeof(T))),
    length(0),
    head(0)
{
  // give a shot about inization list
  // this->array   = (T *) malloc(size * sizeof(T));
  // this->length  = 0;
}

template <class T>
Queue<T>::Queue(const T * const array, const size_t size)
  : size(size * 2),
    array((T *) malloc(size * 2 * sizeof(T))),
    length(size),
    head(0)

{ 
  for(size_t i = 0; i < size; ++i){
    this->array[i]  = array[i];
  }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> origin){
  if(this->array) free(this->array);
  this->array    = (T *) malloc(origin.size * sizeof(T));
  memcpy(this->array, origin.array, origin.size);
  this->size    = origin.size;
  this->length  = origin.length;
  this->head    = origin.head;
}

template <class T>
Queue<T>::~Queue(){
  free(this->array);
}

} // end of namespace CTL
