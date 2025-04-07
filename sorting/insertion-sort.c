#include <stdio.h>

void insertionSort(int arr[], int totalLength)
{
    for (int i = 0; i < totalLength; i++)
    {
        int current = arr[i];
        int previous = i - 1;

        while (previous >= 0 && arr[previous] > current)
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }

        arr[previous + 1] = current;
    }
}

void printArr(int arr[], int totalLength)
{
    for (int i = 0; i < totalLength; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};

    int totalLength = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, totalLength);

    printArr(arr, totalLength);
    return 0;
}
