#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pair *L = (Pair *)malloc(n1 * sizeof(Pair));
    Pair *R = (Pair *)malloc(n2 * sizeof(Pair));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].index] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

int main() {
    int arr[] = {5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair *pairs = (Pair *)malloc(n * sizeof(Pair));
    int *count = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        pairs[i].val = arr[i];
        pairs[i].index = i;
    }

    mergeSort(pairs, 0, n - 1, count);

    printf("Counts: ");
    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    free(pairs);
    free(count);

    return 0;
}