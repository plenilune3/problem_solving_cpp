#include <iostream>

using namespace std;

const int MAX = 101;

int N, M, R, C, A[MAX][MAX];

void reverse(int A[MAX][MAX], int d);
void rotate(int A[MAX][MAX], int d);
void move(int A[MAX][MAX], int d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    
    while (R--)
    {
        cin >> C;

        if (C == 1 || C == 2)
            reverse(A, C);
        else if (C == 3 || C == 4)
            rotate(A, C);
        else
            move(A, C);
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
}

void reverse(int A[MAX][MAX], int d)
{
    int B[MAX][MAX];
    copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (d == 1)
                A[i][j] = B[N - 1 - i][j];
            else
                A[i][j] = B[i][M - 1 - j];
}

void rotate(int A[MAX][MAX], int d)
{
    int B[MAX][MAX];
    copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (d == 3)
                A[i][j] = B[N - 1 - j][i];
            else
                A[i][j] = B[j][M - 1 - i];
    
    swap(N, M);
}

void move(int A[MAX][MAX], int d)
{
    int R = N / 2, C = M / 2;
    int B[MAX][MAX];
    copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (d == 5)
                A[i][j] = B[i + R][j];
            else
                A[i][j] = B[i][j + C];
    for (int i = 0; i < R; i++)
        for (int j = C; j < M; j++)
            if (d == 5)
                A[i][j] = B[i][j - C];
            else
                A[i][j] = B[i + R][j];
    for (int i = R; i < N; i++)
        for (int j = C; j < M; j++)
            if (d == 5)
                A[i][j] = B[i - R][j];
            else
                A[i][j] = B[i][j - C];
    for (int i = R; i < N; i++)
        for (int j = 0; j < C; j++)
            if (d == 5)
                A[i][j] = B[i][j + C];
            else
                A[i][j] = B[i - R][j];
}