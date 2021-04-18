#include <iostream>

using namespace std;

const int MAX = 501;

int N, D, A[MAX][MAX];

void rotate(int A[MAX][MAX], int k);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> N >> D;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];
        
        while (D != 0)
        {
            if (D > 0)
            {
                rotate(A, 45);
                D -= 45;
            }
            else
            {
                rotate(A, -45);
                D += 45;
            }
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << A[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
}

void rotate(int A[MAX][MAX], int k)
{
    int B[MAX][MAX];
    int l = N / 2;
    int x = N / 2, y = N / 2;
    copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

    while (l)
    {
        int temp = A[x - l][y - l];

        if (k == 45)
        {
            A[x - l][y - l] = A[x][y - l];
            A[x][y - l] = A[x + l][y - l];
            A[x + l][y - l] = A[x + l][y];
            A[x + l][y] = A[x + l][y + l];
            A[x + l][y + l] = A[x][y + l];
            A[x][y + l] = A[x - l][y + l];
            A[x - l][y + l] = A[x - l][y];
            A[x - l][y] = temp;
        }
        else
        {
            A[x - l][y - l] = A[x - l][y];
            A[x - l][y] = A[x - l][y + l];
            A[x - l][y + l] = A[x][y + l];
            A[x][y + l] = A[x + l][y + l];
            A[x + l][y + l] = A[x + l][y];
            A[x + l][y] = A[x + l][y - l];
            A[x + l][y - l] = A[x][y - l];
            A[x][y - l] = temp;
        }

        l -= 1;
    }
}