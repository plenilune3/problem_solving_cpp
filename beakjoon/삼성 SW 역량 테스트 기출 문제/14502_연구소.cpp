#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, K, answer, wall;
int board[MAX][MAX];
vector< pair<int, int> > v;
bool selected[MAX * MAX];
bool visited[MAX][MAX];

void combinations(int depth, int index);
int spread_the_virus(int x, int y);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                v.push_back(make_pair(i, j));
            else if (board[i][j] == 1)
                wall += 1;
        }
    
    K = (int) v.size();

    combinations(0, 0);

    cout << answer << "\n";

    return 0;
}

void combinations(int depth, int index)
{
    if (depth == 3)
    {
        fill_n(&visited[0][0], MAX * MAX, false);

        int virus = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (visited[i][j] == false && board[i][j] == 2)
                    virus += spread_the_virus(i, j);
        
        answer = max(answer, N * M - virus - wall - 3);
        return;
    }

    for (int i = index; i < K; i++)
    {
        if (selected[i]) continue;

        selected[i] = true;
        board[v[i].first][v[i].second] = 1;
        combinations(depth + 1, i);
        selected[i] = false;
        board[v[i].first][v[i].second] = 0;
    }
}

int spread_the_virus(int x, int y)
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
        
        ret += spread_the_virus(nx, ny);
    }

    return ret;
}


