#include <iostream>

using namespace std;

const int MAX = 201;

int N, K, L, A[MAX], answer;
bool R[MAX];

void rotate(int L, int *A, int N, bool *R);
void move(int N, bool *R, int *A);
void put(int *A, bool *R);
int is_finished(int L, int *A);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    L = N * 2;

    for (int i = 0; i < L; i++)
        cin >> A[i];
    
    while (true)
    {
        answer += 1;

        if (is_finished(L, A) >= K)
            break;
        
        rotate(L, A, N, R);
        move(N, R, A);
        put(A, R);

        if (is_finished(L, A) >= K)
            break;
        
    }

    cout << answer << "\n";
   
    return 0;
}

void rotate(int L, int *A, int N, bool *R)
{
    int B[L];
    bool C[N];

    for (int i = 0; i < L; i++)
        B[i] = A[i];
    
    for (int i = 0; i < N; i++)
        C[i] = R[i];
    
    for (int i = 0; i < L; i++)
        A[(i + 1) % L] = B[i];
    
    for (int i = 0; i < N; i++)
        R[(i + 1) % N] = C[i];
    
    R[N - 1] = false;
}

void move(int N, bool *R, int *A)
{
    bool C[N];

    for (int i = N - 1; i > 0; i--)
        if (A[i] != 0 && !R[i] && R[i - 1])
        {
            A[i] -= 1;
            R[i] = true;
            R[i - 1] = false;
        }

    R[N - 1] = false;
}

void put(int *A, bool *R)
{
    if (A[0] != 0 && R[0] == false)
    {
        A[0] -= 1;
        R[0] = true;
    }
}

int is_finished(int L, int *A)
{
    int result = 0;

    for (int i = 0; i < L; i++)
        if (A[i] == 0)
            result += 1;
    
    return result;
}