typedef int Rank; //秩
#define DEFAULT_CAPACITY 3 //默认的初始容量

template <typename T> class Vector{
protected:
    Rank _size; int _capacity;T* _elem; //规模 容量 数据区
    void copyFrom(T const* A, Rank lo, Rank hi);
    void expand();
    void shrink(); //装填因子过小时压缩
    bool bubble(Rank lo, Rank hi); //扫描交换
    void bubbleSort(Rank lo, Rank hi); //起泡排序算法
    Rank max(Rank lo, Rank hi);
    void selectionSort(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi,Rank hi); // 归并算法
    void mergeSort(Rank lo, Rank hi); // 归并排序算法
    void heapSort(Rank lo, Rank hi); // 堆排序
    Rank partition(Rank lo, Rank hi); //轴点构造
    void quickSort(Rank lo, Rank hi); //快速排序
    void shellSort(Rank lo, Rank hi); //希尔排序
public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
        {_elem = new T[_capacity = c];_size = 0;} // 容量为c 规模为s，所有元素初始为v
    Vector(T const* A,Rank n){copyFrom(A,0,n);}
    Vector(T const* A,Rank lo, Rank hi){copyFrom(A,lo,hi);}
    Vector(Vector<T> const& V){copyFrom(V._elem,0,V.size);}
    Vector(Vector<T> const& A, Rank lo, Rank hi){copyFrom(A._elem,lo,hi);}
    //析构函数
    ~Vector(){delete [] _elem;} //释放内部空间
    //只读访问接口
    Rank size() const {return _size;}
    bool empty() const {return !_size;}
    Rank find(T const& e) const {return find(e,0,_size);}
    Rank find(T const& e,Rank lo, Rank hi) const;
};
