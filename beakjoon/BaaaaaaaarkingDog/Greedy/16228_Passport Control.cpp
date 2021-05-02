#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 101;

int N, K, A[MAX], B[MAX];
bool answer = true;

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    fill_n(&B[0], MAX, 101);
    reverse(&A[0], &A[0] + N);
    
    for (int i = 0; i < N; i++)
    {
        bool possible = false;

        for (int j = 0; j < K; j++)
            if (B[j] > A[i])
            {
                possible = true;
                B[j] = A[i];
                break;
            }
        
        if (!possible)
        {
            answer = false;
            break;
        }
    }

    if (answer)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    return 0;
}
