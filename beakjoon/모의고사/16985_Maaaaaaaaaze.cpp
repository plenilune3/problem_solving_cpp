#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct coordinate
{
    int z, x, y;
};

const int MAX = 5;
const int dz[] = { -1, 1, 0, 0, 0, 0 };
const int dx[] = { 0, 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, 0, -1, 1 };

int answer = INT_MAX;
bool board[MAX][MAX][MAX];
bool selected[MAX];
vector<int> v;

void permutaions(int depth);
void dfs(int depth, bool board[MAX][MAX][MAX]);
int find_path(bool board[MAX][MAX][MAX]);
void rotate(bool board[MAX][MAX]);
coordinate make_coordinate(int z, int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int k = 0; k < MAX; k++)
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                cin >> board[k][i][j];
    
    permutaions(0);

    if (answer != INT_MAX)
        cout << answer << "\n";
    else
        cout << -1 << "\n";
   
    return 0;
}

void dfs(int depth, bool board[MAX][MAX][MAX])
{
    if (depth == MAX)
    {
        if (board[0][0][0] && board[4][4][4])
        {
            int dist = find_path(board);

            if (dist != -1)
                answer = min(answer, dist);
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        rotate(board[depth]);
        dfs(depth + 1, board);
    }

}

void permutaions(int depth)
{
    if (depth == MAX)
    {
        bool board_c[MAX][MAX][MAX];

        for (int i = 0; i < MAX; i++)
            copy(&board[v[i]][0][0], &board[v[i]][0][0] + MAX * MAX, &board_c[i][0][0]);

        dfs(0, board_c);
    
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (selected[i]) continue;

        selected[i] = true;
        v.push_back(i);
        permutaions(depth + 1);
        selected[i] = false;
        v.pop_back();
    }
}

int find_path(bool board[MAX][MAX][MAX])
{
    int dist[MAX][MAX][MAX];
    fill_n(&dist[0][0][0], MAX * MAX * MAX, -1);
    queue<coordinate> q;
    dist[0][0][0] = 0;
    q.push(make_coordinate(0, 0, 0));

    while (!q.empty())
    {
        int z = q.front().z, x = q.front().x, y = q.front().y;
        q.pop();

        if (z == 4 && x == 4 && y == 4)
            return dist[z][x][y];

        for (int d = 0; d < 6; d++)
        {
            int nz = z + dz[d], nx = x + dx[d], ny = y + dy[d];

            if (nz < 0 || nz >= MAX || nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
                continue;
            
            if (board[nz][nx][ny] == fals        if (dist[z][x][y] > answer)
            return -1;
e || dist[nz][nx][ny] != -1)
                continue;
            
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push(make_coordinate(nz, nx, ny));
        }
    }

    return -1;
}

void rotate(bool board[MAX][MAX])
{
    bool board_c[MAX][MAX];

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            board_c[i][j] = board[MAX - 1 - j][i];
    
    copy(&board_c[0][0], &board_c[0][0] + MAX * MAX, &board[0][0]);
}

coordinate make_coordinate(int z, int x, int y)
{
    coordinate c = { z, x, y };
    return c;
}
