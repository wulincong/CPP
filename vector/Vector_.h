#include "Vector.h"
#define exch(x,y) \
    T temp = _elem[x]; \
    _elem[x] = _elem[y]; \
    _elem[y] = temp

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



// template <typename T>
// bool Vector<T>::Random(T (*Rand) ()){
//     int i;
//     _size = _capacity;
//     for(i = 0;i < _size;i++){
//         _elem[i] = Rand();
//         //std::cout << _elem[i] <<std::endl;
//     }
//     return 1;
// }




template <typename T>
void Vector<T>::swap(Rank lo, Rank hi){
    T temp = _elem[lo];
    _elem[lo] = _elem[hi];
    _elem[hi] = temp;
}



//template <typename T> //向量的起泡排序（基本版）
//void Vector<T>::bubbleSort( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
//   while( lo < --hi ) //反复起泡扫描
//      for( Rank i = lo; i < hi; i++ ) //逐个检查相邻元素
//         if( _elem[i] > _elem[i + 1] ) //若逆序，则
//            swap( i, i + 1 ); //经交换使局部有序
//}






template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){
    int max;
    int current_max;
    int j;
    for(int i=--hi; lo < i; i--){
        current_max = lo;
        for(j = lo; j < i; j++){
            if(_elem[j+1] < _elem[j]) {
                int tmp = _elem[j];
                //printf("tmp = %d",tmp);
                _elem[j] = _elem[j+1];
                _elem[j+1] = tmp;

            }// swap(max, max+1); 
        }
    }
}


    


template <typename T>
void Vector<T>::selectionSort(Rank lo,Rank hi){//选择排序
    int min,j,i;
    for(i = lo; i < hi ; i++){
        min = i ;
        for( j = i; j < hi; j++){
            if(_elem[j] < _elem[min]){
                min = j;
            }
        }
        exch(min,i);
        //T temp = _elem[min];
        //_elem[min] = _elem[i];
        //_elem[i] = temp;
    }
}

template <typename T>
void Vector<T>::insertSort(Rank lo,Rank hi){//插入排序
    int i, j;
    T temp;
    for(i = lo+1;i < hi; i++){
        j = i;
        temp = _elem[i];
        while(lo<j && temp < _elem[j-1]){
            _elem[j] = _elem[j-1]; //如果大于temp，就把这个元素往后挪
            j--;
        }
        _elem[j] = temp; //插入位置为j
    }

}


template <typename T>
void Vector<T>::shellSort(Rank lo,Rank hi){
    int len = hi-lo;
    int h = 1;
    while(h<len/3)h = h*3 + 1;
    while(h>=1){
        for(int i = h;i < hi;i++){
            for(int j = i; j >= h  ;j-=h){
                if(_elem[j] < _elem[j-h]){
                    T tmp = _elem[j];
                    _elem[j] = _elem[j-h];
                    _elem[j-h] = tmp;
                }//if-swap
            }//向前插入
        }//h -> hi
        h = h/3;
    }
}



template <typename T> //有序向量（区间）的归并
void Vector<T>::merge ( Rank lo, Rank mi, Rank hi ) { //[lo, mi)和[mi, hi)各自有序，lo < mi < hi
   Rank i = 0; T* A = _elem + lo; //合并后的有序向量A[0, hi - lo) = _elem[lo, hi)，就地
   Rank j = 0, lb = mi - lo; T* B = new T[lb]; //前子向量B[0, lb) <-- _elem[lo, mi)
   for ( Rank i = 0; i < lb; i++ ) B[i] = A[i]; //复制自A的前缀
   Rank k = 0, lc = hi - mi; T* C = _elem + mi; //后子向量C[0, lc) = _elem[mi, hi)，就地
   while ( ( j < lb ) && ( k < lc ) ) //反复地比较B、C的首元素
      A[i++] = ( B[j] <= C[k] ) ? B[j++] : C[k++]; //将更小者归入A中
   while ( j < lb ) //若C先耗尽，则
      A[i++] = B[j++]; //将B残余的后缀归入A中——若B先耗尽呢？
   delete [] B; //释放临时空间：mergeSort()过程中，如何避免此类反复的new/delete？
}


//template <typename T>

//void Vector<T>::merge(Rank lo,Rank mi,Rank hi){  // 0 2 4
//    T* A = _elem + lo;
//    int lb = mi - lo; T* B = new T[lb];
//    for(Rank i = 0; i < lb; B[i] = A[i++]);
//    int lc = hi - mi; T* C = _elem + mi;
//    for(Rank i = 0,j = 0,k = 0;(j < lb) || (k < lc);){
//        if((j < lb) && (lc <= k || (B[j] <= C[k])) )A[i++] = B[j++];
        
//        if((k < lc) && (lb <= j || (C[k] <  B[j])) )A[i++] = C[k++];
//    }
//    delete [] B;  
//
//    for(int k = lo;k < hi; k++) aux[k] = _elem[k];      // 0 -> 3
//    Rank i = lo;  // i = 0
//    Rank j = mi+1;// j = 3
    
//    for(int k = lo;k < hi; k++){  //0 -> 3
//    if      (i > mi)        _elem[k] = aux[j++];    //
//    else if (j > hi-1)      _elem[k] = aux[i++];    //
//    else if (aux[i]<aux[j]) _elem[k] = aux[i++];    //
//    else                    _elem[k] = aux[j++];    //
//    }
//}



template <typename T>
void Vector<T>::mergeSort(Rank lo,Rank hi){ //0 -> 4
    if(hi-lo < 2) return ;
    Rank mid = (lo + hi) >> 1; // mid = 2
    mergeSort(lo,mid);     // 0 -> 2    
    mergeSort(mid,hi);   // 3 -> 4   
    merge(lo,mid,hi);  // 0 2 4    
}


template <typename T>
Rank Vector<T>::partition(Rank lo,Rank hi){
    int i = lo,j = hi;
    T v = _elem[lo];
    while(1){
        while(_elem[++i] < v) if(i == hi) break;
        while(_elem[++j] >=v) if(j == lo) break;
        if(i >= j) break;
        exch(i,j); 
    }

    exch(lo,j);
    return j;
}

template <typename T>
void Vector<T>::quickSort(Rank lo,Rank hi){
    if(hi<=lo) return;
    Rank j = partition(lo,hi);
    quickSort(lo,j);
    quickSort(j+1,hi);
}




template <typename T>
void Vector<T>::sort(Rank lo,Rank hi){
    //bubbleSort(lo,hi);
    selectionSort(lo,hi);
    //insertSort(lo,hi);
    //shellSort(lo,hi);
    //mergeSort(lo,hi);
    //quickSort(lo,hi);
}



template <typename T> T & Vector<T>::operator[]( Rank r) {return _elem[r];}
template <typename T>const T & Vector<T>::operator[]( Rank r) const{return _elem[r];}



//template <typename T> 
//Vector<T>& Vector<T>::operater= (Vector<T> const& V){
//    if(_elem) delete [] _elem;
//    copyFrom(V._elem, 0, V._size);
//    return *this;
//}






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


template <typename  T>
void Vector<T>::repeat(int repeat_[],int *j){
    Rank i = 1;
    while(i<_size)
        find(_elem[i],0,i) < 0 ? i++ : repeat_[*j++] = remove(i);
}





// template <typename T> 
// void Vector<T>::traverse ( void ( *visit ) ( T ) ) {
//     //std::cout << _elem << std::endl; 
//     for ( int i = 0; i < _size; i++ ) visit( _elem[i] );
//     } //遍历向量

//template <typename T> template <typename VST> //元素类型、操作器
//void Vector<T>::traverse ( VST& visit ) //借助函数对象机制
//{ for ( int i = 0; i < _size; i++ ) visit ( _elem[i] ); } //遍历向量




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



template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const{
    return binSearch(_elem, e, lo, hi);
}




