#include <CTL/insertsort.hpp>

namespace CTL {
template <class T>
void insertsort(T * const array, const int begin, const int end)
{
  for(int i = begin; i <= end; ++i){
    T temp = array[i];
    int j = i-1;
    while(j >=0 && temp < array[j]){
      array[j+1] = array[j];
      j--;
    } 
    array[j] = temp;
  }
}

} // end of namespace CTL
