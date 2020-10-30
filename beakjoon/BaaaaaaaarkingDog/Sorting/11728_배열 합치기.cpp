#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, M;
int A[MAX], B[MAX];
int C[MAX + MAX];

void merge();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 0; i < M; i++)
        cin >> B[i];
    
    merge();

    for (int i = 0; i < N + M; i++)
        cout << C[i] << " ";
    cout << "\n";
    
    return 0;
}

void merge()
{
    int left = 0, right = 0;
    
    for (int i = 0; i < N + M; i++)
    {
        if (left == N) C[i] = B[right++];
        else if (right == M) C[i] = A[left++];
        else if (A[left] <= B[right]) C[i] = A[left++];
        else C[i] = B[right++];
    }
}
