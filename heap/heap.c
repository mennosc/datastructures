#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "heap.h"

/**
 * Returns the root of a given heap
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 * @param tree tree that needs to be examined
 * @returns value of the root of the tree
 */

int getRoot(Heap *tree) {
    return tree->array[0];
}

/**
 * Returns the parent of a particular node in the tree
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 * @param tree tree that needs to be examined.
 * @param index index in the tree that needs to be examined.
 * @returns index of the parent in the array.
 */

int getParent(Heap *tree, int index) {
    return index / 2;
}

/**
 * Returns the left child of a given node.
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 * @param tree tree that needs to be examined.
 * @param index index in the tree that needs to be examined.
 * @returns indes of the left child in the array.
 */
int getLeftChild(Heap *tree, int index) {
    return 2 * index + 1;
}

/**
 * Returns the right child of a given node.
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 * @param tree tree that needs to be examined.
 * @param index index that needs to be examined.
 * @returns index of the right child in the array.
 */ 
int getRightChild(Heap *tree, int index) {
    return 2 * index + 2;
}

/**
 * Swap the values of two indeces in a heap.
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 * @param tree tree that has indeces that need to be swapped.
 * @param index1 first index to be swapped.
 * @param index2 second index to be swapped.
 */ 
void swapValues(Heap *tree, int index1, int index2) {
    int temp = tree->array[index1];
    tree->array[index1] = tree->array[index2];
    tree->array[index2] = temp;
}

/**
 * Makes sure that the heap satisfies the heap properties after having inserted at index index.
 * this function assumes that left(index) and right(index) both satisfy the heap property.
 * Time Complexity:  O(log(n))
 * Space Complexity: O(1)
 * @param tree tree that needs to be heapified.
 * @param index the index that was last added.
 */ 
void maxHeapify(Heap *tree, int index) {
    int leftIndex = getLeftChild(tree, index);
    int rightIndex = getRightChild(tree, index);
    int largestIndex = index;

    if(leftIndex < tree->arraySize && tree->array[leftIndex] > tree->array[largestIndex]) {
        largestIndex = leftIndex;
    } 

    if(rightIndex < tree->arraySize && tree->array[rightIndex] > tree->array[largestIndex]) {
        largestIndex = rightIndex;
    }

    if(largestIndex != index) {
        swapValues(tree, index, largestIndex);
        maxHeapify(tree, largestIndex);
    }
} 

void minHeapify(Heap *tree, int index) {
    int leftIndex = getLeftChild(tree, index);
    int rightIndex = getRightChild(tree, index);
    int smallestIndex = index;

    if(leftIndex < tree->arraySize && tree->array[leftIndex] < tree->array[index]) {
        smallestIndex = leftIndex;
    }

    if(rightIndex < tree->arraySize && tree->array[rightIndex] < tree->array[smallestIndex]) {
        smallestIndex = rightIndex;
    }

    if(smallestIndex != index) {
        swapValues(tree, index, smallestIndex);
        minHeapify(tree, smallestIndex);
    }
 } 

/**
 * Builds a maxheap from an array of values.
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 * @param tree heap that needs to be formed in a heap.
 */ 
void buildMaxHeap(Heap *tree) {
    for(int i = tree->arrayLength / 2; i >= 0; i--) {
        maxHeapify(tree, i);
    }
}

/**
 * Builds a minheap from an array of values.
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 * @param tree heap that needs to be formed in a heap.
 */ 

void buildMinHeap(Heap *tree) {
    for(int i = tree->arrayLength / 2; i >= 0; i--) {
        minHeapify(tree, i);
    }
}

/**
 * Creates an instance of a heap
 * Time Complexity:  O(1)
 * Space Complexity: O(n)
 * @param size amount of elements stored in the heap.
 * @returns an instance of the newly created heap.
 */ 

Heap createHeap(int size) {
    Heap heap;
    heap.arraySize = 0;
    heap.arrayLength = size;
    heap.array = malloc(size * sizeof(int));

    return heap;
}

/**
 * Frees the created heap.
 * Time Complexity:  O(?)
 * Space Complexity: O(1)
 * @param heap heap that needs to be freed
 */

void freeHeap(Heap *heap) {
    free(heap->array);
}



/**
 * Inserts values into the heap.
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 * @param tree tree that the value needs to be stored in.
 * @param value value that needs to be added.
 */
void insertIntoHeap(Heap *tree, int value) {
    tree->array[tree->arraySize] = value;
    tree->arraySize++;
}

/**
 * Sorts the array in ascending order
 * Time complexity:  O(n lg n)
 * Space Complexity: O(1)
 * @param tree tree that needs to be sorted.
 */ 
void heapSortAscending(Heap *tree) {
    buildMaxHeap(tree);
    for(int i = tree->arraySize - 1; i >= 0; i--) {
        swapValues(tree, 0, i);
        tree->arraySize = tree->arraySize - 1;
        maxHeapify(tree, 0);
    }
}

/**
 * Sorts the array in descending order
 * Time complexity:  O(n lg n)
 * Space Complexity: O(1)
 * @param tree tree that needs to be sorted.
 */ 
void heapSortDescending(Heap *tree) {
    buildMinHeap(tree);
    for(int i = tree->arraySize - 1; i >= 0; i--) {
        swapValues(tree, 0, i);
        tree->arraySize = tree->arraySize - 1;
        minHeapify(tree, 0);
    }
}