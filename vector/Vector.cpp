#include "Vector.h"

template <typename T>
void Vector<T>::copyFrom (T const* A, Rank lo, Rank hi){
    _elem = new T[_capacity = 2*(hi-lo)];_size = 0;
    while (lo<hi) _elem[_size++] = A[lo++];
}

template <typename T>
void Vector<T>::expand(){
    if(_size< _capacity) return;
    if(_capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY;
    T* oldElems = _elem; _elem = new T[ _capacity <<= 1 ];
    for(int i=0; i< _size; i++) _elem[i] = oldElems[i];
    delete[] oldElems; //释放空间 
}
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){
    int max;
    for(int i=hi; i>lo; i--){
        current_max = lo;
        for(j = lo; j<i; j++){
            if(_elem[current_max] < _elem[current_max+1]) {
                int tmp = _elem[current_max];
                _elem[current_max] = _elem[current_max+1];
                _elem[current_max+1] = tmp;
            }// swap(max, max+1); 
        }
    }

}