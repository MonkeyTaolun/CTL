#include <CTL/mergesort.hpp>

namespace CTL {

template <class T>
void merge(T * const array, T * const helper, const int begin,
    const int end, const int start)
{
  for ( int i = begin; i <= end; ++i){
    helper[i - start] = array[i];
  }

  int mid     = (begin + end) >> 1;
  int index1  = begin;
  int index2  = mid + 1;
  for ( int i = begin; i <= end; ++i){
    if(index1 > mid || helper[index1 - start] > helper[index2 - start]) 
      array[i] = helper[index2++ - start];
    else if (index2 > end || helper[index1 - start] < helper[index2 - start])
      array[i] = helper[index1++ - start];
  }
}
template <class T>
void merge_sort(T * const array, 
    T * const helper, const int begin, 
    const int end, const int start)
{
   if( begin >= end) return;
   merge_sort(array, helper, begin, (begin + end) >> 1, start);
   merge_sort(array, helper, (begin + end)>>1 + 1, start);
   merge(array, helper, begin, end, start);
}

template <class T>
void mergesort(T * const array, const int begin, const int end){
  T * helper = new T [end - begin]; 
  merge_sort(array, helper, begin, end, begin);
  delete [] helper;
}



} // end of namespace CTL:
