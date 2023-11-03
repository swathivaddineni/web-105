#include <stdio.h>
#include <stdlib.h>
struct HeapNode 
{
int value;
int arrayIndex;
int elementIndex;
};
void swap(struct HeapNode* x, struct HeapNode* y) 
{
struct HeapNode temp = *x;
*x = *y;
*y = temp;
}
void minHeapify(struct HeapNode arr[], int size, int index) 
{
int smallest = index;
int leftChild = 2 * index + 1;
int rightChild = 2 * index + 2;

if (leftChild < size && arr[leftChild].value < arr[smallest].value)
smallest = leftChild;

if (rightChild < size && arr[rightChild].value < arr[smallest].value)
smallest = rightChild;

if (smallest != index) 
{
swap(&arr[index], &arr[smallest]);
minHeapify(arr, size, smallest);
}
}
void buildMinHeap(struct HeapNode arr[], int size) 
{
int i = (size - 1) / 2;
for (; i >= 0; i--) {
minHeapify(arr, size, i);
}
}
int* kWayMerge(int* arrays[], int k, int sizes[]) 
{
int totalElements = 0;
for (int i = 0; i < k; i++) 
{
totalElements += sizes[i];
}
struct HeapNode heap[k];
for (int i = 0; i < k; i++) 
{
heap[i].value = arrays[i][0];
heap[i].arrayIndex = i;
heap[i].elementIndex = 0;

}
buildMinHeap(heap, k);
int* result = (int*)malloc(sizeof(int) * totalElements);
int resultIndex = 0;
while (resultIndex < totalElements) 
{
struct HeapNode minNode = heap[0];
result[resultIndex++] = minNode.value;
int nextElementIndex = minNode.elementIndex + 1;
if (nextElementIndex < sizes[minNode.arrayIndex]) 
{
heap[0].value = arrays[minNode.arrayIndex][nextElementIndex];
heap[0].elementIndex = nextElementIndex;
} 
else 
{
heap[0].value = INT_MAX;
}

minHeapify(heap, k, 0);
}

return result;
}

int main() 
{
int k = 3; 
int sizes[] = {4, 3, 5}; 


int* arrays[3];
arrays[0] = (int[]){1, 3, 5, 7};
arrays[1] = (int[]){2, 4, 6};
arrays[2] = (int[]){0, 8, 9, 10, 11};

int* mergedArray = kWayMerge(arrays, k, sizes);
for (int i = 0; i < sizes[0] + sizes[1] + sizes[2]; i++) 
{
printf("%d ", mergedArray[i]);
}

free(mergedArray); 

return 0;
}
