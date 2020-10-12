#include <iostream>
#include <stack>

using namespace std;

const int MAX = 101;
const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0 };

int N;
bool board[MAX][MAX];

void curve(int x, int y, int d, int g);
int count_square();

int main(int argc, char const *argv[])
{
    cin >> N;

    while (N--)
    {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        curve(x, y, d, g);
    }

    int answer = count_square();

    cout << answer << "\n";

    return 0;
}

void curve(int x, int y, int d, int g)
{
    stack<int> s1, s2;

    board[x][y] = true;

    int nx = x + dx[d], ny = y + dy[d];

    board[nx][ny] = true;
    x = nx, y = ny;

    s2.push(d);

    while (g--)
    {
        s1 = s2;

        while (!s1.empty())
        {
            int d = (s1.top() + 1) % 4;
            s1.pop();
            int nx = x + dx[d], ny = y + dy[d];
            board[nx][ny] = true;
            x = nx, y = ny;
            s2.push(d);
        }
    }
}

int count_square()
{
    int square = 0;

    for (int i = 0; i < MAX - 1; i++)
        for (int j = 0; j < MAX - 1; j++)
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                square += 1;

    return square;
}
