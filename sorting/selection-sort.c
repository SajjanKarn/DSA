#include <stdio.h>

void selectionSort(int arr[], int totalLength)
{
    for (int i = 0; i < totalLength - 1; i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < totalLength; j++)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
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

    selectionSort(arr, totalLength);

    printArr(arr, totalLength);
    return 0;
}
