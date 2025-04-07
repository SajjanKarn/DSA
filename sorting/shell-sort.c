#include <stdio.h>

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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

    shellSort(arr, totalLength);

    printArr(arr, totalLength);
    return 0;
}
