int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        result[idx++] = nums[i];     // xi
        result[idx++] = nums[i + n]; // yi
    }
    *returnSize = numsSize;
    return result;
}
