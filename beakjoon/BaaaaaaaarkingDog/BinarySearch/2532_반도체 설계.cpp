#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4e4;

int N;
int port[MAX], L[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> port[i];
    
    int length = 0;
    L[length++] = 0;

    for (int i = 0; i < N; i++)
    {
        if (L[length-1] < port[i])
            L[length++] = port[i];
        else
        {
            int *index = lower_bound(&L[0], &L[0] + length, port[i]);
            *index = port[i];
        }
    }

    cout << length - 1 << "\n";
    
    return 0;
}
