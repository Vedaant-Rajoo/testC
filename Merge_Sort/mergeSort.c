#include <stdio.h>
#include <stdlib.h>
#define LENGTH  100

int* slice(int *arr, int start, int end);
void merge(int *result, int *left, int *right, int leftLen, int rightLen);
void mergeSort(int *arr, int len);
void printArray(int* arr, int len);


int* slice(int *arr, int start, int end)
{
    int *result = (int *) malloc((end - start) * sizeof(int));
    int i;
    for (i = start; i < end; i++)
    {
        result[i - start] = arr[i];
    }
    return result;
}

/** Merge left and right into result, overwriting everything in result. */
void merge(int *result, int *left, int *right, int leftLen, int rightLen)
{
    int i = 0, j = 0;
    while(i < leftLen && j < rightLen)
    {
        if (left[i] < right[j])
        {
            result[i + j] = left[i];
            i++;
        }
        else
        {
            result[i + j] = right[j];
            j++;
        }
    }

    for(; i < leftLen; i++)
    {
        result[i + j] = left[i];
    }
    for(; j < rightLen; j++)
    {
        result[i + j] = right[j];
    }

    free(left);
    free(right);
}

// in-place merge sort
void mergeSort(int *arr, int len)
{
    if (len <= 1)
    {
        return;
    }
    int *left = slice(arr, 0, len / 2 + 1);
    int *right = slice(arr, len / 2, len);

    printf("left: ");
    printArray(left, len / 2);
    printf("right: ");
    printArray(right, len - (len / 2));

    mergeSort(left, len / 2);
    mergeSort(right, len - (len / 2));

    merge(arr, left, right, len / 2, len - (len / 2));
}

/** Print an array of ints */
void printArray(int* arr, int len)
{
    int i = 0;
    printf("[");
    for(; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int main(void)
{
    int lis[LENGTH] = {48, 54, 92, 36, 13, 8, 92, 91, 53, 100, 39, 64, 58, 5, 95, 70, 21, 64, 16, 60, 7, 97, 66, 91, 43, 62, 59, 59, 13, 60, 31, 69, 15, 41, 54, 57, 71, 63, 57, 55, 95, 59, 1, 16, 92, 33, 12, 33, 67, 3, 89, 91, 62, 43, 62, 66, 11, 46, 59, 82, 72, 90, 65, 24, 18, 78, 45, 77, 58, 96, 78, 51, 64, 28, 89, 23, 4, 18, 66, 32, 39, 9, 67, 54, 98, 42, 19, 43, 42, 87, 13, 12, 57, 82, 39, 30, 8, 21, 60, 67};
    mergeSort(lis, LENGTH);
    printArray(lis, LENGTH);

    return 0;
}