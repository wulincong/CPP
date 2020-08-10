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


template <typename T> T & Vector<T>::operator[]( Rank r) {return _elem[r];}
template <typename T>const T & Vector<T>::operator[]( Rank r) const{return _elem[r];}

template <typename T> 
Rank Vector<T>::insert ( Rank r, T const& e ){ 
    expand();
    for(int i = _size;i>r;i--)_elem[i] = _elem[i-1];
    _elem[r] = e;
    _size++;
    return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi){
    while (hi<_size) {_elem[lo++] = _elem[hi++];}
    _size = lo;
    shrink();
    return hi-lo;
}

template <typename T>
T Vector<T>::remove(Rank r){
    T e = _elem[r];
    // while(r < _size) {
    //     _elem[r] = _elem[r+1];
    //     r++;}
    remove(r,r+1);
    return e;
}

template <typename T>
Rank Vector<T>::find(T const& e,Rank lo, Rank hi) const{
    while(lo < hi){
        if(_elem[lo] == e)return lo;
        lo++;
    } 
    return -1;
}

// template <typename T>
// int Vector<T>::deduplicate(){
//     for(int i = 0; i < _size;i++){
//         for(int j = i; j < _size;j++){
//             if(_elem[j] == _elem[i])remove(j);
//         }
//     }
// }

template <typename T>
int Vector<T>::deduplicate(){
    int oldSize = _size;
    Rank i = 1;
    while(i < _size)
        find(_elem[i],0,i) < 0 ? i++:remove(i);
    return oldSize - _size;
}

template <typename T>
void Vector<T>::traverse(void (*)( T&)){
    for(int i = 0; i < _size;i++)visit(_elem[i]);
}




