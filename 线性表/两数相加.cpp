#include "stdio.h"
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    for (i = 0;i < numsSize;i++){
    	//printf("%d\n",nums[i]);
    	for (j = i+1;j<numsSize;j++){
    		if(nums[i]+nums[j] == target) {
			returnSize[0] = i;
			returnSize[1] = j;
			}//if;
	    }//for
    }//for
}

main(){
	int num[4] = {2, 7, 11, 15};
	int numSize = 4;
	int target = 9;
	int returnSize[2];
	
	twoSum(&num[0],numSize,target,&returnSize[0]);
	printf("[%d,%d]",returnSize[0],returnSize[1]);
} 

