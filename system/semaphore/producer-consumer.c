#define N 100 //缓冲区中的槽数目
typedef int semaphore;    //信号量是一种整形数据
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

void producer(void){
    int item;
    while(1){
        item = produce_item();
    }
}