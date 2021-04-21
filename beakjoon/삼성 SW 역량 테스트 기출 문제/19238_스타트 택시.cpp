#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 21;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct passenger
{
    int sx, sy, tx, ty, d;

    passenger(int _sx, int _sy, int _tx, int _ty, int _d) : sx(_sx), sy(_sy), tx(_tx), ty(_ty) {};

    bool operator<(const passenger p) const
    {
        if (d != p.d) return d < p.d;
        else if (sx != p.sx) return sx < p.sx;
        return sy < p.sy;
    }
};

int N, M, F;
bool A[MAX][MAX], possible = true;
int X, Y, dist[MAX][MAX];
vector<passenger> v;

void calculate_distance(int X, int Y);
passenger get_passenger(int dist[MAX][MAX], vector<passenger> &v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> F;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    
    cin >> X >> Y;
    X -= 1, Y -= 1;

    while (M--)
    {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        v.push_back(passenger(sx - 1, sy - 1, tx - 1, ty - 1, 0));
    }

    while (!v.empty())
    {
        calculate_distance(X, Y);
        passenger p = get_passenger(dist, v);

        if (p.d == -1 || p.d > F)
        {
            possible = false;
            break;
        }

        F -= p.d, X = p.sx, Y = p.sy;
        calculate_distance(X, Y);

        if (dist[p.tx][p.ty] > F)
        {
            possible = false;
            break;
        }

        F += dist[p.tx][p.ty], X = p.tx, Y = p.ty;
    }

    if (possible)
        cout << F << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void calculate_distance(int X, int Y)
{
    fill_n(&dist[0][0], MAX * MAX, -1);
    queue< pair<int, int> > q;
    dist[X][Y] = 0;
    q.push(make_pair(X, Y));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (dist[nx][ny] != -1 || A[nx][ny] != 0)
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

passenger get_passenger(int dist[MAX][MAX], vector<passenger> &v)
{
    for (vector<passenger>::iterator i = v.begin(); i != v.end(); i++)
        (*i).d = dist[(*i).sx][(*i).sy];

    sort(v.begin(), v.end());
    passenger p = v[0];
    v.erase(v.begin());

    return p;
}