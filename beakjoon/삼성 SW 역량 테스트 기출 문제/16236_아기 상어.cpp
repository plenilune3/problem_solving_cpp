#include <iostream>
#include <queue>

using namespace std;

struct shark
{
    int x, y, d;

    bool operator< (const shark &s) const
    {
        if (d != s.d) return d > s.d;
        else if (x != s.x) return x > s.x;
        else return y > s.y;
    }
};


const int MAX = 21;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N;
int board[MAX][MAX];
int dist[MAX][MAX];

shark get_next(int size);
void find_distance(int sx, int sy, int size);
shark make_shark(int x, int y, int d);

int main(int argc, char const *argv[])
{
    int answer = 0, eating = 0;
    int sx, sy, size = 2;

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 9)
                sx = i, sy = j;
        }
    
    while (true)
    {
        find_distance(sx, sy, size);
        shark s = get_next(size);

        if (s.x == -1 && s.y == -1 && s.d == -1)
            break;
        
        board[sx][sy] = 0;
        sx = s.x, sy = s.y;
        board[sx][sy] = 9;
       
        eating += 1;

        if (eating == size)
            size += 1, eating = 0;

        answer += s.d;
    }

    cout << answer << "\n";
    
    return 0;
}

shark get_next(int size)
{
    priority_queue<shark> pq;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 9 || dist[i][j] == -1)
                continue;

            if (board[i][j] != 0 && size > board[i][j])
                pq.push(make_shark(i, j, dist[i][j]));
        }
                
    if (!pq.empty()) return pq.top();
    else return make_shark(-1, -1, -1);
}

void find_distance(int sx, int sy, int size)
{
    fill_n(&dist[0][0], MAX * MAX, -1);
    queue< pair<int, int> > q;
    dist[sx][sy] = 0;
    q.push(make_pair(sx, sy));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (dist[nx][ny] != -1 || board[nx][ny] > size)
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

shark make_shark(int x, int y, int d)
{
    shark s = { x, y, d };
    return s;
}
