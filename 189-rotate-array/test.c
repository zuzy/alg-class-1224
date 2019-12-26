#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"
#include "def.h"
#include "func.h"

#define CASE 2

#if CASE == 1
// Reverse three times;
static void reverse(int *num, int size)
{
    int h, t, m;
    h = 0;
    t = size - 1;
    while(h < t) {
        m = num[h];
        num[h] = num[t];
        num[t] = m;
        ++h;
        --t;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    if(k > numsSize) {
        k = k % numsSize;
    }
    if(!k) {
        return;
    }
    int l = numsSize - k;
    reverse(nums, l);
    reverse(nums + l, k);
    reverse(nums, numsSize);
}


#endif

#if CASE == 2
void rotate(int* nums, int numsSize, int k)
{
    if(k > numsSize) {
        k = k % numsSize;
    }
    if(!k) {
        return;
    }

    int tmp[k], l;
    l = numsSize - k;
    memcpy(tmp, nums + l, k * sizeof(int));

    int m, s, i = 0;
    s = numsSize - k - 1;
    for(i = s; i >= 0; --i) {
        m = nums[i];
        nums[i] = nums[i + k];
        nums[i + k] = m;
    }

    memcpy(nums, tmp, k * sizeof(int));
}
#endif


int main(int argc, char *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8};
    // int a[] = {0,0,1,1,1,2,2,3,3,4,5,6,7,8,9,10,11,12,12,13,13,13,14,14,14,15,15,16,17,17,17,17,18,18,19,19,20,20,21,22,23,24,25,26,27};
    // int a[] = {};
    // int a[] = {1};
    int size = sizeof(a) / sizeof(a[0]);

    int index = 0;
    for(; index < size; ++index) {
        int *target = (int *)malloc(sizeof(a));
        memcpy(target, a, sizeof(a));
        rotate(target, size, index);

        int i = 0;
        printf("testing[%d]", index);
        dump(target,size);
        free(target);
    }
    return 0;
}