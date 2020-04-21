#include "SequenceArray.h"

Status InitArray(Array *A, int dim, ...) {
    int elemtotal; //统计数组中总元素个数
    va_list ap;
    int i;
    if( dim<1 || dim>MAX_ARRAY ) return ERROR;
    A->dim = dim; //维度
    A->bounds = (int *)malloc(dim*sizeof(int));
    if( !A->bounds ) return OVERFLOW;

    elemtotal = 1;
    
    va_start(ap, dim);
    for(i=0;i<A->dim;i++){
        A->bounds[i] = va_arg(ap, int);
        if(A->bounds[i] <= 0) return UNDERFLOW;
        elemtotal *= A->bounds[i];
    }
    va_end(ap);
    
    A->base = (AElemType *)malloc(sizeof(AElemType)*elemtotal);
    if(!A->base) return OVERFLOW;

    A->constants = (int *)malloc(sizeof(int)*dim);
    if(!A->constants) return OVERFLOW;

    A->constants[dim-1] = 1;
    for(i = dim-2;i >= 0;i--){
        A->constants[i] = A->constants[i+1] * A->constants[i+1];
    }
    return OK;

}


