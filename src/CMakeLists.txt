SET(CTL_LIB_SRC CTL/quicksort CTL/mergesort CTL/stack 
  CTL/insertsort CTL/queue CTL/linkedlist)
ADD_LIBRARY(CTL SHARED ${CTL_LIB_SRC})
