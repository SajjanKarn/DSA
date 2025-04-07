// Online C compiler to run C program online
#include <stdio.h>

void bubbleSort(int arr[], int totalLength)
{
    for (int i = 0; i < totalLength - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < totalLength - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if (swapped == 0)
        {
            return;
        }
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

    bubbleSort(arr, totalLength);

    printArr(arr, totalLength);
    return 0;
}