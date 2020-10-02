#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 23;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct guest
{
    int sx, sy, tx, ty;
};

struct taxi
{
    int x, y;
};

int N, M, F;
bool board[MAX][MAX];
int dist[MAX][MAX];
vector< guest > v;
taxi t;

guest make_guest(int sx, int sy, int tx, int ty);
bool compare(guest a, guest b);
bool cantGo(int x, int y);
void get_distance();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> F;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    
    cin >> t.x >> t.y;

    for (int i = 0; i < M; i++)
    {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        v.push_back(make_guest(sx, sy, tx, ty));
    }

    bool is_possible = false;
    
    while (true)
    {
        if (v.empty())
        {
            is_possible = true;
            break;
        }

        get_distance();
        sort(v.begin(), v.end(), compare);
        guest g = v[0];
        v.erase(v.begin());

        if (cantGo(g.sx, g.sy))
            break;

        F -= dist[g.sx][g.sy];
        t.x = g.sx, t.y = g.sy;

        get_distance();

        if (cantGo(g.tx, g.ty))
            break;

        F -= dist[g.tx][g.ty];
        t.x = g.tx, t.y = g.ty;

        F += dist[g.tx][g.ty] * 2;
    }

    if (is_possible)
        cout << F << "\n";
    else
        cout << "-1" << "\n";
    
    return 0;
}

guest make_guest(int sx, int sy, int tx, int ty)
{
    guest g = { sx, sy, tx, ty };
    return g;
}

bool compare(guest a, guest b)
{
    if (dist[a.sx][a.sy] != dist[b.sx][b.sy]) return dist[a.sx][a.sy] < dist[b.sx][b.sy];
    else if (a.sx != b.sx) return a.sx < b.sx;
    else return a.sy < b.sy;
}

bool cantGo(int x, int y)
{
    return dist[x][y] == -1 || F - dist[x][y] < 0;
}

void get_distance()
{
    fill_n(&dist[0][0], MAX * MAX, -1);
    queue< pair<int, int> > q;
    dist[t.x][t.y] = 0;
    q.push(make_pair(t.x, t.y));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;
            
            if (dist[nx][ny] != -1 || board[nx][ny])
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}