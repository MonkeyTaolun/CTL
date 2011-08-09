#include <CTL/heap.hpp>

namespace CTL {
template <class T>
bool Heap<T>::isEmpty() const {
  return this->size != 0;
}

template <class T>
bool Heap<T>::find(size_t index, 
  const T element) const
{
  return index < size && 
    (element == array[index] 
      || element < array[index] 
      && (this->find(index * 2 + 1, element) 
        || this->find(index * 2 + 2, element)));
}

template <class T>
bool Heap<T>::contains(const T element) const {
   return this->find(0, element); 
}

template <class T>
T * Heap<T>::toArray() const{
  T * copy = new T [this->size]; 
  for(size_t i = 0; i < this->size; ++i){
    copy[i] = array[i]; 
  }
  return copy;
}

template <class T>
size_t Heap<T>::getSize()  const{
  return size;
}

template <class T>
void Heap<T>::heapify(size_t index){
  size_t temp = index;
  if(index * 2 + 1 < size && array[index * 2 + 1] > array[index]){
    temp = index * 2 + 1;
  }
  if(index * 2 + 2 < size && array[index * 2 + 2] > array[temp]) {
    temp = index * 2 + 2;
  }
  if(temp != index) {
    T element     = array[index];
    array[index]  = array[temp];
    array[temp]   = element;
    heapify(temp);
  }
}

template <class T>
bool Heap<T>::push(const T element){
  if(size >= max_size) return false;
  int index = size++;
  array[index] = element;
  int parent = (index - 1) / 2;
  while(parent >= 0 && array[index] > array[parent]){
    array[index]  = array[parent];
    array[parent] = element;
    index         = parent;
    parent        = (index - 1) / 2;
  }
  return true;
}

template <class T>
bool Heap<T>::pop(){
  if(!this->size) return false;
  if(--this->size) {
    this->array[0] = this->array[size];
    this->heapify(this->size);
  }
  return true;
}

template <class T>
void Heap<T>::clear(){
  this->size = 0;
}

template <class T>
const T Heap<T>::top() const{
  if(size) {
    T element = array[0];
    return element;
  }
  return NULL;
}

template <class T>
Heap<T>::Heap(const unsigned max_size)
  : array(new T[max_size]),
    size(0),
    max_size(max_size){}

template <class T>
Heap<T>::Heap(const T * const array, const size_t size)
  : array(new T[size]),
    size(size),
    max_size(size)
{
  for(size_t index = 0 ; index < size; ++index){
    this->array[index] = array[index];
  }
  for(size_t index = size / 2; index >= 0; --index){
    heapify(index);
  }
}

template <class T>
Heap<T>::~Heap(){
  delete [] array;
}

}
