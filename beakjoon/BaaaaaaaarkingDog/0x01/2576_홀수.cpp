#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[7];
    int index, sum_odd = 0;

    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 1)
            index = i;
    }

    for (int i = 0; i < 7; i++)
    {
        if (arr[i] % 2 == 1)
        {
            if (arr[i] < arr[index])
                index = i;

            sum_odd += arr[i];
        }
    }

    if (sum_odd == 0)
        printf("-1\n");
    else
    {
        printf("%d\n", sum_odd);
        printf("%d\n", arr[index]);
    }

    return 0;
}
