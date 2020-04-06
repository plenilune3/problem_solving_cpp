#include <cstdio>

using namespace std;

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;

    while (i <= j)
    {
        while (i <= end && arr[i] <= arr[pivot])
            i++;
        while (j > start && arr[j] >= arr[pivot])
            j--;
        
        if (i > j)
        {
            temp = arr[j]; arr[j] = arr[pivot]; arr[pivot] = temp;
        }
        else
        {
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }

        quick_sort(arr, start, j - 1);
        quick_sort(arr, j + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int arr[5];
    int sum_value = 0;

    for (int i = 0; i < 5; i++)
    {
       scanf("%d", &arr[i]);
       sum_value += arr[i];
    }

    quick_sort(arr, 0, 4);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    printf("%d\n", sum_value / 5);
    printf("%d\n", arr[2]);

    return 0;
}
