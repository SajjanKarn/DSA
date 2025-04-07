#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        int tmp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = tmp;

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(int arr[], int totalLength)
{
    for (int i = 0; i < totalLength; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int totalLength = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, totalLength - 1);

    printArr(arr, totalLength);
    return 0;
}
