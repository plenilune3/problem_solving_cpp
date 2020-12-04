#include <iostream>

using namespace std;

const int MAX = 500;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int N;
int board[MAX][MAX], answer;
double S[5][5] = {
    { 0, 0, 0.02, 0, 0 },
    { 0, 0.1, 0.07, 0.01, 0 },
    { 0.05, 0, 0, 0, 0 },
    { 0, 0.1, 0.07, 0.01, 0 },
    { 0, 0, 0.02, 0, 0 }
};

void spread(int x, int y, int dir);
void rotate_(double S[5][5]);
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
        
    int x = N / 2, y = N / 2;
    int k = 1, dir = 0, dist = 0, sw = -1;

    while (true)
    {
        dist += 1;

        for (int i = 0; i < dist; i++)
        {
            y += sw, k += 1;
            spread(x, y, dir);

            if (k >= N * N) break;
        }

        dir = (dir + 1) % 4; rotate_(S);

        if (k >= N * N) break;

        for (int i = 0; i < dist; i++)
        {
            x -= sw, k += 1;
            spread(x, y, dir);
        }

        dir = (dir + 1) % 4; rotate_(S); 

        sw *= -1;
    }

    cout << answer << "\n";

    return 0;
}

void spread(int x, int y, int dir)
{
    int sum_ = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (S[i][j] == 0)
                continue;

            int temp = board[x][y] * S[i][j];
            sum_ += temp;
            int nx = x + i - 2, ny = y + j - 2;

            if (is_out_of_range(nx, ny)) answer += temp;
            else board[nx][ny] += temp;
        }
    
    board[x][y] -= sum_;
    int nx = x + dx[dir], ny = y + dy[dir];

    if (is_out_of_range(nx, ny)) answer += board[x][y];
    else board[nx][ny] += board[x][y];
    
    board[x][y] = 0;
}

void rotate_(double S[5][5])
{
    double S_copy[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            S_copy[i][j] = S[j][5 - 1 - i];
    
    copy(&S_copy[0][0], &S_copy[0][0] + 5 * 5, &S[0][0]);
}

bool is_out_of_range(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return true;
    
    return false;
}
