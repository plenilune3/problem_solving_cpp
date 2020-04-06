#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int year, answer;

    scanf("%d", &year);

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                printf("1\n");   
            else
                printf("0\n");
        }
        else
            printf("1\n");
    }
    else
        printf("0\n");

    return 0;
}
