#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[9];
    int index = 0;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] > arr[index])
            index = i;
    }

    printf("%d\n", arr[index]);
    printf("%d\n", index + 1);

    return 0;
}
