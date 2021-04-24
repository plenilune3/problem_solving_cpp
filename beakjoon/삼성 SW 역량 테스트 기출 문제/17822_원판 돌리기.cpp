#include <iostream>

using namespace std;

const int MAX = 51;

int N, M, T, A[MAX][MAX];

void rotate(int M, int d, int k, int *A);
bool distinct(int N, int M, int A[MAX][MAX]);
void calculate(int N, int M, int A[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> T;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    
    
    
    while (T--)
    {
        int x, d, k; cin >> x >> d >> k;

        for (int i = 0; i < N; i++)
            if ((i + 1) % x == 0)
                rotate(M, d, k, A[i]);
        
        bool is_distinct = distinct(N, M, A);

        if (!is_distinct)
            calculate(N, M, A);
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            answer += A[i][j];
    
    cout << answer << "\n";

    return 0;
}

void rotate(int M, int d, int k, int *A)
{
    int B[M];

    for (int i = 0; i < M; i++)
        B[i] = A[i];
    
    for (int i = 0; i < M; i++)
        if (d == 0)
            A[(i + k) % M] = B[i];
        else
            A[i] = B[(i + k) % M];
}

bool distinct(int N, int M, int A[MAX][MAX])
{
    int B[N][M];
    bool possible = false;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            B[i][j] = A[i][j];
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (B[i][j] == 0)
                continue;

            if (B[i][j] == B[i][(j + 1) % M])
            {
                A[i][j] = 0, A[i][(j + 1) % M] = 0;
                possible = true;
            }
            
            if (B[i][j] == B[i][(j + M - 1) % M])
            {
                A[i][j] = 0, A[i][(j + M - 1) % M] = 0;
                possible = true;
            }
            
            if (i == N - 1)
                continue;
            
            if (B[i][j] == B[i + 1][j])
            {
                A[i][j] = 0, A[i + 1][j] = 0;
                possible = true;
            }
        }
    }

    return possible;
}

void calculate(int N, int M, int A[MAX][MAX])
{
    double average = 0;
    double cnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (A[i][j] != 0)
            {
                average += A[i][j];
                cnt += 1;
            }
    
    average = average / cnt;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == 0)
                continue;

            if (A[i][j] > average)
                A[i][j] -= 1;
            else if (A[i][j] < average)
                A[i][j] += 1;
        }
}
