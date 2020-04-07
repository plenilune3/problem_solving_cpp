#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int cards[20];
    int left, right, temp;

    for (int i = 0; i < 20; i++)
        cards[i] = i + 1;
    
    for (int i = 0; i < 10; i++)
    {
        scanf("%d %d", &left, &right);
         
        while (left <= right)
        {
           temp = cards[left-1], cards[left-1] = cards[right-1]; cards[right-1] = temp;
           left += 1;
           right -= 1;
        }
    }

    for (int i = 0; i < 20; i++)
        printf("%d ", cards[i]);

    return 0;
}

