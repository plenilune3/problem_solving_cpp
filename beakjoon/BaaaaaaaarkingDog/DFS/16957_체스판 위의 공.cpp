#include <iostream>
#include <queue>

using namespace std;

const int MAX = 500;
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

struct candidate
{
    int x, y, d;

    bool operator< (const candidate &c) const
    {
        return d > c.d;
    }
};

int R, C;
bool visited[MAX][MAX];
pair<int, int> dp[MAX][MAX];
int board[MAX][MAX], answer[MAX][MAX];

pair<int, int> play(int x, int y);
candidate make_candidate(int x, int y, int d);
candidate get_next(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];
    
    fill_n(&dp[0][0], MAX * MAX, pair<int, int> (-1, -1));

    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
            if (dp[x][y].first == -1)
                play(x, y);
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            answer[dp[i][j].first][dp[i][j].second] += 1;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << answer[i][j] <<  " ";
        cout << "\n";
    }

    return 0;
}

pair<int, int> play(int x, int y)
{
    if (dp[x][y].first != -1)
        return dp[x][y];
    
    candidate c = get_next(x, y);

    if (board[x][y] < c.d)
    {
        dp[x][y].first = x;
        dp[x][y].second = y;
        return dp[x][y];
    }

    return dp[x][y] = play(c.x, c.y);
}

candidate get_next(int x, int y)
{
    priority_queue<candidate> pq;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        
        pq.push(make_candidate(nx, ny, board[nx][ny]));
    }

    return pq.top();
}

candidate make_candidate(int x, int y, int d)
{
    candidate c = { x, y, d };
    return c;
}
