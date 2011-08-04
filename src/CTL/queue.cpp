#include <CTL/queue.hpp>

#include <new>

namespace CTL {

template <class T>
bool Queue<T>::isEmpty() const{
  return this->size == 0;
}

template <class T>
bool Queue<T>::contains(const T element) const {
  for(size_t i = 0; i < this->size; ++i){
    if(element == this->array[i]) return true;
  }
  return false;
}

template <class T>
T * Queue<T>::toArray() const{
  T * copy = new T [this->size];
  for(size_t i = 0; i < this->size; ++i){
    copy[i] = this->array[(this->head + i) % this->max_size];
  }
  return copy;
}

template <class T>
size_t getSize() const {
  return this->size;
}

template <class T>
size_t Queue<T>::getSize() const{
  return this->size;
}

template <class T>
bool Queue<T>::pop() {
  if(this->size != 0) {
    this->size--;
    this->head = (this->head+1) % this->max_size;
    return true;
  }
  return false;
}

template <class T>
bool Queue<T>::push(const T element){
  if(this->size == this->max_size) {
    T * morespace = (T * )realloc(this->array, 
      this->max_size * 2 *sizeof(T) );
    if(morespace != NULL){
      this->array = morespace;
      this->max_size *= 2;
    }
    else {
      free(this->array);
      throw std::bad_alloc();
    }
  }
  this->array[(this->head + (this->size++)) % this->max_size] = element;
  return true;
}

template <class T>
void Queue<T>::clear(){
  this->size  = 0;
  this->head  = 0;
}

template <class T>
Queue<T>::Queue(const size_t max_size)
  : max_size(max_size),
    array((T *) malloc(max_size * sizeof(T))),
    size(0),
    head(0)
{
  // give a shot about inization list
  // this->array   = (T *) malloc(size * sizeof(T));
  // this->length  = 0;
}

template <class T>
Queue<T>::Queue(const T * const array, const size_t size)
  : max_size(size * 2),
    array((T *) malloc(size * 2 * sizeof(T))),
    size(size),
    head(0)

{ 
  for(size_t i = 0; i < size; ++i){
    this->array[i]  = array[i];
  }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> origin){
  if(this->array) free(this->array);
  this->array     = (T *) malloc(origin.max_size * sizeof(T));
  memcpy(this->array, origin.array, origin.max_size);
  this->max_size  = origin.max_size;
  this->size      = origin.size;
  this->head      = origin.head;
}

template <class T>
Queue<T>::~Queue(){
  free(this->array);
}

} // end of namespace CTL
