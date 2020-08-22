#define DEFAULT_CAPACITY 3
typedef int Rank;


template <typename T> 
class Vector{
protected:
    Rank _size;
    int _capacity;
    T *_elem; 
    void bubbleSort(Rank lo, Rank hi){
        int i,j;

        for(i = --hi; i > lo; i--){
            for(j = lo; j < i;j++){
                if(_elem[j] > _elem[j+1]){
                    T tmp = _elem[j];
                    _elem[j] = _elem[j+1];
                    _elem[j+1] = tmp;
                }
            }
        }
    }

public:
    Vector(Rank size){
        _elem = new T[size];
        _capacity = size;
        _size = 0;
    }

    void sort(){
        bubbleSort(0, _size);
    }

    void traverse(void (*visit ) ( T )){
        for(int i = 0; i < _size;i++)visit(_elem[i]);
    }

    void Random( T (*Rand) ()){
        _size = _capacity;
        for(int i = 0; i < _size;i++) _elem[i] = Rand();
    }

};
