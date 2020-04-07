#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    char room_number[7];
    int numbers[10] = {0};
    int number = 0;

    scanf("%s", room_number);

    for (int i = 0; i < strlen(room_number); i++)
        numbers[room_number[i] - '0'] += 1;

    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] > numbers[number])
            number = i;
    }

    if (number == 6 || number == 9)
        printf("%d\n", ((numbers[6] + numbers[9] - 1) / 2) + 1);
    else
        printf("%d\n", numbers[number]);

    return 0;
}
