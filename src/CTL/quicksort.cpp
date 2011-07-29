#include <CTL/quicksort.hpp>


namespace CTL {

template <class T>
int partition(T * const array, const int begin, const int end){
  int partition = begin + 1;
  T   temp      = array[begin];
  for (int i =  begin + 1; i < end; ++i){
    if(array[i] < temp) 
      swap(array[partition++], array[i]);
  }
  swap(array[begin], array[partition-1]);
  return partition - 1;
}

template <class T>
void quicksort(T * const array, const int begin, const int end){
  if (begin >= end) return;
  int partition = partition(array, begin, end);
  quicksort(array, begin, partition - 1);
  quicksort(array, partition + 1, end);
}

}
