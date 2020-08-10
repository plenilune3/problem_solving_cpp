#include <iostream>
#include <queue>

using namespace std;

const int MAX = 102;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct hero
{
    int x, y;
    bool isWithGram;
};

int N, M, T;
int board[MAX][MAX];
int dist[MAX][MAX][2];

bool isOutOfRange(int x, int y)
{
    if (x < 1 || y < 1 || x > N || y > M)
        return true;
    
    return false;
}

hero make_hero(int x, int y, bool isWithGram)
{
    hero h = { x, y, isWithGram };
    return h;
}

int MoveToPrincess()
{
    fill_n(&dist[0][0][0], MAX * MAX * 2, -1);
    queue<hero> q;
    hero init = make_hero(1, 1, false);
    dist[1][1][0] = 0;
    q.push(init);

    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        bool isWithGram = q.front().isWithGram;
        q.pop();

        if (dist[x][y][isWithGram] > T)
            continue;
        
        if (x == N && y == M)
            return dist[x][y][isWithGram];
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            
            if (isOutOfRange(nx, ny) || dist[nx][ny][isWithGram] != -1)
                continue;
            
            if (board[nx][ny] == 0)
            {
                dist[nx][ny][isWithGram] = dist[x][y][isWithGram] + 1;
                q.push(make_hero(nx, ny, isWithGram));
            }
            
            if (board[nx][ny] == 1 && isWithGram)
            {
                dist[nx][ny][isWithGram] = dist[x][y][isWithGram] + 1;
                q.push(make_hero(nx, ny, isWithGram));
            }

            if (board[nx][ny] == 2)
            {
                dist[nx][ny][true] = dist[x][y][isWithGram] + 1;
                q.push(make_hero(nx, ny, true));
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    
    int answer = MoveToPrincess();
    (answer != -1) ? cout << answer << "\n" : cout << "Fail" << "\n";

    return 0;
}
