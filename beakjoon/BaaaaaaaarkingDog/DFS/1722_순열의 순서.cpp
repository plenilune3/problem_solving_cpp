#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long f[21];
bool visited[21];

int main(int argc, char const *argv[])
{
    int N, cmd;

    cin >> N;

    f[0] = 1;
    for (int i = 1; i < 21; i++)
        f[i] = f[i - 1] * i;
    
    cin >> cmd;


    if (cmd == 2)
    {
        int perm[N+1];

        for (int i = 1; i < N + 1; i++)
            cin >> perm[i];
        
        long long answer = 0;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j < perm[i]; j++)
            {
                if (visited[j] == false)
                    answer += f[N - i];
            }
            visited[perm[i]] = true;
        }

        cout << answer + 1 << "\n";
    }
    else 
    {
        int perm[N+1];

        long long k;

        cin >> k;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (visited[j] == true)
                    continue;
                
                if (f[N - i] < k)
                    k -= f[N - i];
                else
                {
                    perm[i] = j;
                    visited[j] = true;
                    break;
                }
            }
        }

        for (int i = 1; i <= N; i++)
            cout << perm[i] << " ";
    }

    return 0;
}
