#include <iostream>
#include <queue>

using namespace std;

const int MAX = 102;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int N, K, L;
bool board[MAX][MAX];
bool visited[MAX][MAX];
queue< pair<int, int > > q;
queue< pair<int, char> > d;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> K;

    while (K--)
    {
        int x, y; cin >> x >> y;
        board[x][y] = true;
    }

    cin >> L;

    while (L--)
    {
        int x; char c; cin >> x >> c;
        d.push(make_pair(x, c));
    }

    q.push(make_pair(1, 1));
    visited[1][1] = true;
    int x = 1, y = 1, dir = 0, answer = 0;

    while (true)
    {
        if (answer == d.front().first)
        {
            if (d.front().second == 'D')
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4;
            d.pop();
        }
        
        x = x + dx[dir], y = y + dy[dir];

        if (x < 1 || x > N || y < 1 || y > N)
            break;
        
        if (visited[x][y])
            break;
        
        if (board[x][y] == false)
        {
            int tx = q.front().first, ty = q.front().second;
            visited[tx][ty] = false;
            q.pop();
        }

        board[x][y] = false;
        visited[x][y] = true;
        q.push(make_pair(x, y));

        answer += 1;
    }

    cout << answer + 1 << "\n";

    return 0;
}
