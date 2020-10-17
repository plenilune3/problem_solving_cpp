#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, K, answer;
int board[MAX][MAX];
bool visited[MAX][MAX];
bool selected[MAX * MAX];
vector< pair<int, int> > c;

void combinations(int depth, int index);
int play();
int dfs(int x, int y, bool &possible);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                c.push_back(make_pair(i, j));
        }
    
    K = (int) c.size();

    combinations(0, 0);

    cout << answer << "\n";

    return 0;
}

void combinations(int depth, int index)
{
    if (depth == 2)
    {
        answer = max(answer, play());
        return;
    }

    for (int i = index; i < K; i++)
    {
        if (selected[i]) continue;

        int x = c[i].first, y = c[i].second;
        selected[i] = true;
        board[x][y] = 1;
        combinations(depth + 1, i);
        selected[i] = false;
        board[x][y] = 0;
    }
}

int play()
{
    fill_n(&visited[0][0], MAX * MAX, false);

    int result = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 2 && visited[i][j] == false)
            {
                bool possible = true;

                int temp = dfs(i, j, possible);

                if (possible)
                    result += temp;
            }
    
    return result;
}

int dfs(int x, int y, bool &possible)
{
    visited[x][y] = true;

    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (visited[nx][ny] || board[nx][ny] == 1)
            continue;
        
        if (board[nx][ny] == 0)
            possible = false;

        ret += dfs(nx, ny, possible);
    }

    return ret;
}
