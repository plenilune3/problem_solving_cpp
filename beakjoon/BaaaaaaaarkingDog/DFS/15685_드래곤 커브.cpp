#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool board[MAX][MAX] = { false };
vector<int> v;
int N, x, y, d, g;

void dragon()
{
    v.push_back(0);
    for (int i = 1; i <= 10; i++)
    {
        int k = 1 << (i - 1);
        for (int j = 0; j < k; j++)
            v.push_back((v[k-1-j] + 1) % 4);
    }
}

void curve()
{
    board[x][y] = true;
    for (int i = 0; i < (1 << g); i++)
    {
        x += dx[(v[i] + d) % 4], y += dy[(v[i] + d) % 4];
        board[x][y] = true;
    }
}

int square_count()
{
    int cnt = 0;

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                cnt++;

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dragon();
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> d >> g;
        curve();
    }

    cout << square_count() << "\n";

    return 0;
}
