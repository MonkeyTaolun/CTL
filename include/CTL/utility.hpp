#ifndef _CTL_UTILITY_HPP_
#define _CTL_UTILITY_HPP_

namespace CTL {
  template <class T> 
  inline void swap(T a, T b){
    T temp  = a;
    a       = b;
    b       = temp;
  }
}

#endif
