#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;

struct body
{
    int x, y;
};

struct direction
{
    int t;
    char d;
};

int main(int argc, char const *argv[])
{
    int board[MAX][MAX] = { 0 };
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    queue<direction> q;
    queue<body> snake;
    snake.push({1, 1});
    board[1][1] = true;

    int N, K, L;

    cin >> N;
    cin >> K;

    for (int k = 0; k < K; k++)
    {
        int x, y;
        cin >> x >> y;

        board[x][y] = 1;
    }

    cin >> L;

    for (int l = 0; l < L; l++)
    {
        int t;
        char d;
        cin >> t >> d;

        q.push({t, d});
    }

    int time = 0;
    int d = 0;
    int x = 1, y = 1;

    while(true)
    {
        direction sd = q.front();

        if (time == sd.t)
        {
            if (sd.d == 'D')
                d = (d + 1) % 4;
            else
                d = (d + 3) % 4;
            q.pop();
        }

        x = x + dx[d];
        y = y + dy[d];

        if (x < 1 || x > N || y < 1 || y > N || board[x][y] == 2)
            break;

        if (board[x][y] == 0)
        {
            int nx = snake.front().x;
            int ny = snake.front().y;
            board[nx][ny] = 0;
            snake.pop();
        }
        
        board[x][y] = 2;
        snake.push({x, y});
        
        time++;
    }

    cout << time + 1 << "\n";

    return 0;
}
