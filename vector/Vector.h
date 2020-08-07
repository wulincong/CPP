typedef int Rank;
#define DEFAULT_CAPACITY 3 //默认的初始容量

template <typename T> class Vector{
protected:
    Rank _size; int _capacity;T* _elem; //规模 容量 数据区
    void copyFrom(T const* A, Rank lo, Rank hi);
public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
        {_elem = new T[_capacity = c];_size = 0;} // 容量为c 规模为s，所有元素初始为v
    Vector(T const* A,Rank n){copyFrom(A,0,n);}
    ~Vector(){delete [] _elem;} //释放内部空间

};
