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

} // end of namespace CTL
