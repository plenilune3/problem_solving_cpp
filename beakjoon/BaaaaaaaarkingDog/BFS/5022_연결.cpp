#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 101;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer = MAX * MAX;
int ax, ay, bx, by, cx, cy, rx, ry;
int visited[MAX][MAX];
int trace[MAX * MAX];

int convert(int x, int y);
int find_path(int ax, int ay, int bx, int by);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> M >> N;
    N += 1, M += 1;

    cin >> ay >> ax >> by >> bx;
    cin >> cy >> cx >> ry >> rx;

    fill_n(&visited[0][0], MAX * MAX, -1);
    int a = find_path(ax, ay, bx, by);

    for (int x = 0; x < M; x++)
    {
        for (int y = 0; y < N; y++)
            cout << convert(x, y) << " ";
        cout << "\n";
    }

    for (int x = 0; x < M; x++)
    {
        for (int y = 0; y < N; y++)
            cout << visited[x][y] << " ";
        cout << "\n";
    }

    int b = find_path(cx, cy, rx, ry);

    cout << a << " " << b << "\n";

    if (a == -1 || b == -1)
        answer = MAX * MAX;
    else
        answer = min(answer, a + b);

    fill_n(&visited[0][0], MAX * MAX, -1);
    int c = find_path(cx, cy, rx, ry);
    int d = find_path(ax, ay, bx, by);

    cout << c << " " << d << "\n";

    if (c == -1 || d == -1)
        answer = min(answer, MAX * MAX);
    else
        answer = min(answer, c + d);
    
    cout << answer << "\n";

    return 0;
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
               
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return -1;
}

int convert(int x, int y)
{
    return x * N + y;
}
