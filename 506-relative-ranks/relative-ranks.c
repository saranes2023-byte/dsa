typedef struct {
    int score;
    int index;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair *)b)->score - ((Pair *)a)->score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    Pair *arr = malloc(scoreSize * sizeof(Pair));
    for (int i = 0; i < scoreSize; i++) {
        arr[i].score = score[i];
        arr[i].index = i;
    }

    qsort(arr, scoreSize, sizeof(Pair), cmp);

    char **res = malloc(scoreSize * sizeof(char *));
    for (int i = 0; i < scoreSize; i++)
        res[i] = malloc(20);

    for (int i = 0; i < scoreSize; i++) {
        int idx = arr[i].index;
        if (i == 0)
            sprintf(res[idx], "Gold Medal");
        else if (i == 1)
            sprintf(res[idx], "Silver Medal");
        else if (i == 2)
            sprintf(res[idx], "Bronze Medal");
        else
            sprintf(res[idx], "%d", i + 1);
    }

    *returnSize = scoreSize;
    free(arr);
    return res;
}