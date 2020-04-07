#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    char A[1002];
    char B[1002];
    int arr[26] = {0};

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", A);
        scanf("%s", B);
        
        bool is_possible = true;

        if (strlen(A) == strlen(B))
        {
            for (int i = 0; i < strlen(A); i++)
                arr[A[i] - 'a'] += 1;
            
            for (int i = 0; i < strlen(B); i++)
            {
                if (arr[B[i] - 'a'] == 0)
                {
                    is_possible = false;
                    break;
                }
                else
                    arr[B[i] - 'a'] -= 1;
            }
        } 
        else
            is_possible = false;
        
        if (is_possible)
            printf("Possible\n");
        else
            printf("Impossible\n");
        
        fill(arr, arr+26, 0);
    }
    
    return 0;
}
