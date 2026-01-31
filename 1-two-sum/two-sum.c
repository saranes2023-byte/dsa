#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair *)a)->value - ((Pair *)b)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair *arr = malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    qsort(arr, numsSize, sizeof(Pair), cmp);

    int left = 0, right = numsSize - 1;

    while (left < right) {
        long long sum = (long long)arr[left].value + arr[right].value;
        if (sum == target) {
            int *res = malloc(2 * sizeof(int));
            res[0] = arr[left].index;
            res[1] = arr[right].index;
            *returnSize = 2;
            free(arr);
            return res;
        }
        if (sum < target)
            left++;
        else
            right--;
    }

    *returnSize = 0;
    free(arr);
    return NULL;
}