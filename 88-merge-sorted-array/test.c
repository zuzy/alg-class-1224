#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int tail = nums1Size - 1;
    int tmp;
    --n;
    --m;
    while(n >= 0 && m >= 0) {

        if(nums1[m] > nums2[n]) {
            tmp = nums1[m];
            nums1[m] = nums1[tail];
            nums1[tail] = tmp;
            --m;
        } else {
            nums1[tail] = nums2[n];
            --n;
        }
        --tail;
    }
    while(n >= 0) {
        nums1[tail--] = nums2[n--];
    }
}

int main(int argc, char *argv[])
{
    int a[] = {5,7,9,11,13};
    // int a[] = {0,0,1,1,1,2,2,3,3,4,5,6,7,8,9,10,11,12,12,13,13,13,14,14,14,15,15,16,17,17,17,17,18,18,19,19,20,20,21,22,23,24,25,26,27};
    // int a[] = {};
    // int a[] = {1};
    // int b[] = {1,2,3,4};
    // int b[] = {2, 4, 6};
    int b[] = {};



    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    int *target = (int *)malloc(sizeof(int) * (m + n));
    memcpy(target, a, sizeof(a));

    int *addition = (int *)malloc(sizeof(int) * n);
    memcpy(addition, b, sizeof(b));


    merge(target, m + n, m, addition, n, n);
    // int ret = removeDuplicates(target, sizeof(a)/ sizeof(a[0]));
    int ret = m + n;
    printf("len: %d\n", ret);
    int i = 0;
    for(; i < ret; ++i) {
        printf("\t%d", target[i]);
    }
    printf("\n");

    free(target);
    free(addition);

    return 0;
}