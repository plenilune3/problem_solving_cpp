#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    char A[1000], B[1000];
    int A_count[26] = {0};
    int B_count[26] = {0};
    int count = 0;

    scanf("%s", A);
    scanf("%s", B);

    for (int i = 0; i < strlen(A); i++)
        A_count[A[i] - 'a'] += 1;
    for (int i = 0; i < strlen(B); i++)
        B_count[B[i] - 'a'] += 1;

    for (int i = 0; i < 26; i++)
        count += abs(A_count[i] - B_count[i]);
    
    printf("%d\n", count);

    return 0;
}
