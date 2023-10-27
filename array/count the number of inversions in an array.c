#include <stdio.h>
#include <stdlib.h>
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) 
{
int i = left;
int j = mid + 1;
int k = left;
long long inversionCount = 0;

while (i <= mid && j <= right) 
{
if (arr[i] <= arr[j]) 
{
temp[k++] = arr[i++];
} 
else 
{
temp[k++] = arr[j++];
inversionCount += (mid - i + 1);
}
}

while (i <= mid) 
{
temp[k++] = arr[i++];
}

while (j <= right) 
{
temp[k++] = arr[j++];
}

for (i = left; i <= right; i++) 
{
arr[i] = temp[i];
}

return inversionCount;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) 
{
long long inversionCount = 0;
if (left < right) {
int mid = left + (right - left) / 2;
inversionCount += mergeSortAndCount(arr, temp, left, mid);
inversionCount += mergeSortAndCount(arr, temp, mid + 1, right);
inversionCount += mergeAndCount(arr, temp, left, mid, right);
}
return inversionCount;
}

long long countInversions(int arr[], int n) {
int* temp = (int*)malloc(sizeof(int) * n);
long long inversionCount = mergeSortAndCount(arr, temp, 0, n - 1);
free(temp);
return inversionCount;
}

int main() {
int arr[] = {8, 4, 2, 1};
int n = sizeof(arr) / sizeof(arr[0]);

long long inversions = countInversions(arr, n);

printf("Number of inversions: %lld\n", inversions);

return 0;
}
