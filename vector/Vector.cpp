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
void Vector<T>::shrink(){
    for(int i=_size; i < _capacity; i++)
        _elem[i] = 0;
}



template <typename T>
bool Random(T (*Rand) (void)){
    int i;
    for(i = 0;i < _sise;i++){
        _elem[i] = Rand();
    }
}


template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){
    int max;
    int current_max;
    int j;
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
    while (hi<_size) {_elem[lo++] = _elem[hi++];}  //后面的整体迁移
    _size = lo;  //改变size大小
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
int Vector<T>::deduplicate(){  //无序去重 
    int oldSize = _size;  //记录原规模
    Rank i = 1;   //从编号1开始，这是第二个元素
    while(i < _size)
        find(_elem[i],0,i) < 0 ? i++:remove(i); //从当前元素的前面元素寻找相同元素，最多有一个
    return oldSize - _size;
}

template <typename T> void Vector<T>::traverse ( void ( *visit ) ( T& ) ) //借助函数指针机制
{ for ( int i = 0; i < _size; i++ ) visit ( _elem[i] ); } //遍历向量

template <typename T> template <typename VST> //元素类型、操作器
void Vector<T>::traverse ( VST& visit ) //借助函数对象机制
{ for ( int i = 0; i < _size; i++ ) visit ( _elem[i] ); } //遍历向量




//低效版有序去重
//template <typename T>
//int Vector<T>::uniquify(){ // 有序的去重
//    int oldSize = _size;
//    for(int i = 0; i < _size-1 ;i++){   //这里的size大小是动态变化的
//        _elem[i] == _elem[i+1] ? remove(i+1) : ;  //如果后继元素相同就删除这个后继元素
//    }
//    return oldSize - _size;
//}


//高效有序去重
template <typename T>
int Vector<T>::uniquify(){
    Rank i = 0,j = 1;  //i是标记的非重复元素，j用于遍历其他元素
    for(j;j<_size;j++){
        if(_elem[i] != _elem[j]) _elem[++i] = _elem[j];//直到j遍历到相异的元素时，把它加入到前面
    }
    _size = ++i;shrink();
    return j-i;
}




template <typename T>
static Rank binSearch(T* A, T const& e,Rank lo, Rank hi){ //二分查找

    while(lo < hi){      
        Rank mi = (lo+hi)>>1;
        if      (e < A[mi]) hi =mi;  //折半查找前面
        else if (A[mi] < e) lo = mi + 1;   //折半查找后面
        else return mi;   //mi处命中
    }
    return -1;   //查找失败
}


