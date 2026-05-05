#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* i1 = *(int**)a;
    int* i2 = *(int**)b;
    return i1[0] - i2[0];
}

int** merge(int** intervals, int intervalsSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) return NULL;

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;
    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];
    (*returnColumnSizes)[idx] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            if (intervals[i][1] > result[idx][1])
                result[idx][1] = intervals[i][1];
        } else {
            idx++;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return result;
}