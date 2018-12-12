/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int printArray(int * array, int num) {
    int i;
    printf("[");
    for(i=0;i<num;i++){
        if(i != num-1){
            printf("%d, ", array[i]);
        } else {
            printf("%d]\n", array[i]);
        }
    }
    return 0;
}

/* method mormal */
int* productExceptSelfOne(int* nums, int numsSize, int* returnSize) {
    int i;
    int * returnArray = (int *)malloc(sizeof(int) * numsSize);

    for(i=0;i<numsSize;i++){
            returnArray[i] = nums[i];
    }
    for(i=1;i<numsSize;i++) {
        nums[i] = nums[i-1] * nums[i];
    }
    for(i=numsSize-1;i>0;i--) {
        nums[i] = nums[i-1];
    }
    nums[0] = 1;
    for(i=numsSize-2;i>=0;i--) {
        returnArray[i] = returnArray[i] * returnArray[i+1];
    }
    for(i=0;i<numsSize-1;i++){
        returnArray[i] = returnArray[i+1];
    }
    returnArray[numsSize-1] = 1;
    for(i=0;i<numsSize;i++) {
        returnArray[i] = returnArray[i] * nums[i];
    }  
    * returnSize = numsSize;
    return  returnArray;
}

/* method simple but the run time is longer, don't know why */
int* productExceptSelfTwo(int* nums, int numsSize, int* returnSize) {
    int i, back=1;
    int * returnArray = (int *)malloc(sizeof(int) * numsSize);
    returnArray[0] = 1;
    for(i=1;i<numsSize;i++){
        returnArray[i] = returnArray[i-1] * nums[i-1];
    }
    for(i=numsSize-1;i>=0;i--){
        returnArray[i] *= back;
        back *= nums[i]; 
    } 
    * returnSize = numsSize;
    return  returnArray;
}


int main(int argc, char ** argv) {
    int i;
    int testNums[6] = {1, 2, 3, 4, 5, 6};
    int * result;
    int num = 6;
    int * returnSize;
    returnSize = &num;
    resultOne = productExceptSelfOne(testNums, num, returnSize);
    resultTwo = productExceptSelfTwo(testNums, num, returnSize);
    i = printArray(resultOne, num);
    i = printArray(resultTwo, num);
    return 0;
}