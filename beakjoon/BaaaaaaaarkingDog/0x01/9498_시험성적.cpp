#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int score;

    scanf("%d", &score);

    if (score <= 100 && score >= 90)
        printf("A\n");
    else if (score <= 89 && score >= 80)
        printf("B\n");
    else if (score <= 79 && score >= 70)
        printf("C\n");
    else if (score <= 79 && score >= 70)
        printf("D\n");
    else
        printf("F\n");
    

    return 0;
}
