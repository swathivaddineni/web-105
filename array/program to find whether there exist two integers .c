#include <stdio.h>
#include <stdlib.h>
int hasPairWithSum(int arr[], int n, int X) 
{
qsort(arr, n, sizeof(int), cmp);
int left = 0;
int right = n - 1;
while (left < right) 
{
int sum = arr[left] + arr[right];
if (sum == X) 
{
return 1; 
} 
else if (sum < X) 
{
left++;
}
else 
{
right--;
}
}

return 0; 
}
int cmp(const void *a, const void *b) 
{
return (*(int *)a - *(int *)b);
}

int main() 
{
int arr[] = {1, 4, 6, 8, 10};
int n = sizeof(arr) / sizeof(arr[0]);
int X = 10;

if (hasPairWithSum(arr, n, X)) 
{
printf("There exist two integers whose sum is %d.\n", X);
} 
else 
{
printf("No such pair found.\n");
}

return 0;
}
