#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 12;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer = INT_MAX;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector< pair<int, int> > v;

void get_min_cost(int depth, int index, int result);
bool is_possible(int x, int y);
int flower(int x, int y, bool b);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            v.push_back(make_pair(i, j));
        }

    M = v.size();
    get_min_cost(0, 0, 0);
    cout << answer << "\n";

    return 0;
}

void get_min_cost(int depth, int index, int result)
{
    if (depth == 3)
    {
        answer = min(answer, result);
        return;
    }

    for (int i = index; i < M; i++)
    {
        int x = v[i].first, y = v[i].second;

        if (is_possible(x, y) == false)
            continue;
        
        int cost = flower(x, y, true);
        get_min_cost(depth + 1, i, result + cost);
        flower(x, y, false);
    }
}

int flower(int x, int y, bool b)
{
    visited[x][y] = b;
    int result = board[x][y];

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        visited[nx][ny] = b;
        result += board[nx][ny];
    }

    return result;
}

bool is_possible(int x, int y)
{
    if (visited[x][y])
        return false;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            return false;
        
        if (visited[nx][ny])
            return false;
    }

    return true;
}
