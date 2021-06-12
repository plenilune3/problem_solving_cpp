#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 102;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer = MAX * MAX;
int visited[MAX][MAX];
int prev_[MAX * MAX];

int find_path_ab(int ax, int ay, int bx, int by, int cx, int cy, int rx, int ry);
int find_path(int ax, int ay, int bx, int by);
void draw_line(int bx, int by);
int ctoi(int x, int y);
pair<int, int> itoc(int p);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int ax, ay, bx, by, cx, cy, rx, ry;
    
    cin >> M >> N;
    N += 1, M += 1;

    cin >> ay >> ax >> by >> bx;
    cin >> cy >> cx >> ry >> rx;

    int A = find_path_ab(ax, ay, bx, by, cx, cy, rx, ry);
    int B = find_path_ab(cx, cy, rx, ry, ax, ay, bx, by);

    if (A == -1 && B == -1)
        cout << "IMPOSSIBLE" << "\n";
    else if (A == -1)
        cout << B << "\n";
    else if (B == -1)
        cout << A << "\n";
    else
        cout << min(A, B) << "\n";

    return 0;
}

int find_path_ab(int ax, int ay, int bx, int by, int cx, int cy, int rx, int ry)
{
    fill_n(&visited[0][0], MAX * MAX, -1);
    fill_n(&prev_[0], MAX * MAX, -1);
    visited[cx][cy] = 0;
    visited[rx][ry] = 0;
    int dist_a = find_path(ax, ay, bx, by);

    fill_n(&visited[0][0], MAX * MAX, -1);
    visited[ax][ay] = 0;
    visited[bx][by] = 0;
    draw_line(bx, by);
    int dist_b = find_path(cx, cy, rx, ry);

    if (dist_a == -1 || dist_b == -1)
        return -1;
    else
        return dist_a + dist_b;
}

int find_path(int ax, int ay, int bx, int by)
{
    queue< pair<int, int> > q;

    visited[ax][ay] = 0;
    q.push(make_pair(ax, ay));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == bx && y == by)
            return visited[x][y];

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if (visited[nx][ny] != -1)
                continue;
               
            prev_[ctoi(nx, ny)] = ctoi(x, y);
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return -1;
}

void draw_line(int bx, int by)
{
    int p = ctoi(bx, by);

    while (prev_[p] != -1)
    {
        pair<int, int> c = itoc(p);
        visited[c.first][c.second] = 0;
        p = prev_[p];
    }
}

int ctoi(int x, int y)
{
    return x * M + y;
}

pair<int, int> itoc(int p)
{
    return make_pair(p / M, p % M);
}
