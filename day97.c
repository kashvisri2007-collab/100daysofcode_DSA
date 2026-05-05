#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* m1 = *(int**)a;
    int* m2 = *(int**)b;
    return m1[0] - m2[0];
}

void swap(int* heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapifyUp(int* heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(heap, index, smallest);
        heapifyDown(heap, size, smallest);
    }
}

int minMeetingRooms(int** intervals, int intervalsSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int heapSize = 0;

    heap[heapSize++] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (heap[0] <= intervals[i][0]) {
            heap[0] = intervals[i][1];
            heapifyDown(heap, heapSize, 0);
        } else {
            heap[heapSize] = intervals[i][1];
            heapifyUp(heap, heapSize);
            heapSize++;
        }
    }

    int result = heapSize;
    free(heap);
    return result;
}