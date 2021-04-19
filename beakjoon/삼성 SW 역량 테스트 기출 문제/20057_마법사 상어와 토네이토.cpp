#include <iostream>

using namespace std;

const int MAX = 500;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int N, A[MAX][MAX], answer;
double S[5][5] = {
    { 0, 0, 0.02, 0, 0 },
    { 0, 0.1, 0.07, 0.01, 0 },
    { 0.05, 0, 0, 0, 0 },
    { 0, 0.1, 0.07, 0.01, 0},
    { 0, 0, 0.02, 0, 0}
};

void spread(int x, int y, int dir);
void rotate(double S[5][5]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    
    int x = N / 2, y = N / 2;
    int dist = 0, dir = 0, k = 1, sw = -1;

    while (true)
    {
        dist += 1;

        for (int i = 0; i < dist; i++)
        {
            y += sw, k += 1;
            spread(x, y, dir);
        }

        if (k >= N * N)
            break;
        
        dir = (dir + 1) % 4; rotate(S);
        
        for (int i = 0; i < dist; i++)
        {
            x -= sw, k += 1;
            spread(x, y, dir);
        }

        dir = (dir + 1) % 4; rotate(S);

        sw *= -1;
    }

    cout << answer << "\n";

    return 0;
}

void spread(int x, int y, int dir)
{
    int sum = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (S[i][j] == 0)
                continue;
            
            int temp = A[x][y] * S[i][j];
            sum += temp;

            int nx = x + (i - 2), ny = y + (j - 2);

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                answer += temp;
            else
                A[nx][ny] += temp;
        }
    
    A[x][y] -= sum;
    int nx = x + dx[dir], ny = y + dy[dir];

    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
        answer += A[x][y];
    else
        A[nx][ny] += A[x][y];
    
    A[x][y] = 0;
}

void rotate(double S[5][5])
{
    double C[5][5];
    copy(&S[0][0], &S[0][0] + 5 * 5, &C[0][0]);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            S[i][j] = C[j][5 - 1 - i];
}
