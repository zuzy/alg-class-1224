#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if 0
void moveZeroes(int* nums, int numsSize)
{
    int tmp, i, j;
    for(i = 0, j = 0; i < numsSize; ++i) {
        if(!nums[i]) {
            for(j = i > j ? i : j; j < numsSize; ++j) {
                if(nums[j]) {
                    tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    goto Conti;
                }
            }
            return;
            Conti:
            continue;
        }
    }
}
#else
#define INT_SIZE	(sizeof(int))
void moveZeroes(int* nums, int numsSize) {
    int i, *p, *re;
    
    for(i = 0, re = p = nums; i < numsSize; ++i, ++p) {
        if(*p == 0) continue;
        *re++ = *p;
    }
    memset(re, 0, (nums + numsSize - re) * INT_SIZE);
}
#endif


int main(int argc, char *argv[])
{
    // int a[] = {1,1,2,2};
    // int a[] = {0,0,1,1,1,2,2,3,3,4,5,6,7,8,9,10,11,12,12,13,13,13,14,14,14,15,15,16,17,17,17,17,18,18,19,19,20,20,21,22,23,24,25,26,27};
    int a[] = {0,1,0,3,12};
    // int a[] = {1};
    int *target = (int *)malloc(sizeof(a));
    memcpy(target, a, sizeof(a));
    int len = sizeof(a) / sizeof(a[0]);
    moveZeroes(target, len);
    printf("len: %d\n", len);
    int i = 0;
    for(; i < len; ++i) {
        printf("\t%d", target[i]);
    }
    printf("\n");

    return 0;
}