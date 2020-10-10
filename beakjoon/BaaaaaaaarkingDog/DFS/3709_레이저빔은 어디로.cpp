#include <iostream>

using namespace std;

const int MAX = 52;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, R, lx, ly;
bool board[MAX][MAX];
pair<int, int> dp[MAX][MAX];

void get_laser(int &x, int &y, int &d);
pair<int, int> dfs(int x, int y, int d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        fill_n(&dp[0][0], MAX * MAX, make_pair(-1, -1));
        fill_n(&board[0][0], MAX * MAX, false);

        cin >> N >> R;

        while (R--)
        {
            int x, y; cin >> x >> y;
            board[x][y] = true;
        }

        cin >> lx >> ly;

        int x, y, d;
        get_laser(x, y, d);

        pair<int, int> result = dfs(x, y, d);

        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}

pair<int, int> dfs(int x, int y, int d)
{
    if (dp[x][y] != make_pair(-1, -1))
    {
        if (board[x][y]) return make_pair(0, 0);
        else return dp[x][y];
    }

    if (x == 0 || x == N + 1 || y == 0 || y == N + 1)
        return make_pair(x, y);   
   
    int nd = board[x][y] ? (d + 1) % 4 : d;
    int nx = x + dx[nd], ny = y + dy[nd];

    return dp[x][y] = dfs(nx, ny, nd);
}

void get_laser(int &x, int &y, int &d)
{
    if (ly == 0) x = lx, y = ly + 1, d = 1;
    else if (ly == N + 1) x = lx, y = ly - 1, d = 3;
    else if (lx == 0) x = lx + 1, y = ly, d = 2;
    else x = lx - 1, y = ly, d = 0;
}