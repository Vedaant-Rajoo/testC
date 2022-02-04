#include <stdio.h>
#include <stdlib.h>
#define LENGTH  100

_Array_ptr<int> slice(_Array_ptr<int> arr : count(end), int start, int end);
void merge(_Array_ptr<int> result, _Array_ptr<int> left : count(leftLen), _Array_ptr<int> right : count(rightLen), int leftLen, int rightLen);
void mergeSort(_Array_ptr<int> arr : count(len), int len);
void printArray(_Array_ptr<int> arr : count(len), int len);


_Array_ptr<int> slice(_Array_ptr<int> arr : count(end), int start, int end)
{
    _Array_ptr<int> result = (_Array_ptr<int>) malloc<int>((end - start) * sizeof(int));
    int i;
    for (i = start; i < end; i++)
    _Checked {
        result[i - start] = arr[i];
    }
    return result;
}

/** Merge left and right into result, overwriting everything in result. */
void merge(_Array_ptr<int> result, _Array_ptr<int> left : count(leftLen), _Array_ptr<int> right : count(rightLen), int leftLen, int rightLen)
_Checked {
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

    free<int>(left);
    free<int>(right);
}

// in-place merge sort
void mergeSort(_Array_ptr<int> arr : count(len), int len)
_Checked {
    if (len <= 1)
    {
        return;
    }
    _Array_ptr<int> left = slice(arr, 0, len / 2 + 1);
    _Array_ptr<int> right = slice(arr, len / 2, len);

    _Unchecked { printf("left: "); };
    printArray(left, len / 2);
    _Unchecked { printf("right: "); };
    printArray(right, len - (len / 2));

    mergeSort(left, len / 2);
    mergeSort(right, len - (len / 2));

    merge(arr, left, right, len / 2, len - (len / 2));
}

/** Print an array of ints */
void printArray(_Array_ptr<int> arr : count(len), int len)
_Checked {
    int i = 0;
    _Unchecked { printf("["); };
    for(; i < len; i++)
    _Unchecked {
        printf("%d, ", arr[i]);
    }
    _Unchecked { printf("]\n"); };
}

int main(void)
_Checked {
    int lis _Checked[LENGTH] = {48, 54, 92, 36, 13, 8, 92, 91, 53, 100, 39, 64, 58, 5, 95, 70, 21, 64, 16, 60, 7, 97, 66, 91, 43, 62, 59, 59, 13, 60, 31, 69, 15, 41, 54, 57, 71, 63, 57, 55, 95, 59, 1, 16, 92, 33, 12, 33, 67, 3, 89, 91, 62, 43, 62, 66, 11, 46, 59, 82, 72, 90, 65, 24, 18, 78, 45, 77, 58, 96, 78, 51, 64, 28, 89, 23, 4, 18, 66, 32, 39, 9, 67, 54, 98, 42, 19, 43, 42, 87, 13, 12, 57, 82, 39, 30, 8, 21, 60, 67};
    mergeSort(lis, LENGTH);
    printArray(lis, LENGTH);

    return 0;
}