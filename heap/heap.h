#ifndef HEAP_H
#define HEAP_H

//Defintion of a heap.
typedef struct {
    int arrayLength; //total size of the complete array
    int arraySize; //total amount of elements in the array
    int *array; //represents the actual heap
} Heap;

//all basic functions needed when working with heaps.
Heap createHeap(int size);
int getRoot(Heap *tree);
int getParent(Heap *tree, int index);
int getLeftChild(Heap *tree, int index);
int getRightChild(Heap *tree, int index);
void swapValues(Heap *tree, int index1, int index2);
void maxHeapify(Heap *tree, int index);
void minHeapify(Heap *tree, int index);
void buildMaxHeap(Heap *tree);
void buildMinHeap(Heap *tree);
void heapSortAscending(Heap *tree);
void heapSortDescending(Heap *tree);
void freeHeap(Heap *heap);
void increaseHeapSize(Heap *tree);
void insertIntoHeap(Heap *tree, int value);

#endif