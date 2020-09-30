#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M;
bool is_finished;
char board[MAX][MAX];
bool visited[MAX * MAX];
vector< pair<int, int> > v;
vector< pair<int, int> > e;

void combinations(int depth, int index);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < N + 2; j++)
        {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
            {
                board[i][j] = 'O';
                continue;
            }

            cin >> board[i][j];

            if (board[i][j] == 'X')
                e.push_back(make_pair(i, j));
            else if (board[i][j] == 'T')
                v.push_back(make_pair(i, j));
        }
    
    M = e.size();
    combinations(0, 0);

    if (is_finished)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    return 0;
}

bool is_watched(int x, int y, int d)
{
    bool watched = false;

    while (true)
    {
        if (board[x + dx[d]][y + dy[d]] == 'O')
            break;
        
        if (board[x + dx[d]][y + dy[d]] == 'S')
        {
            watched = true;
            break;
        }

        x += dx[d], y += dy[d];
    }

    return watched;
}

bool is_possible()
{
    bool possible = false;

    for (vector< pair<int, int> >::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        int x = (*iter).first, y = (*iter).second;

        for (int i = 0; i < 4; i++)
            possible |= is_watched(x, y, i);
        
        if (possible)
            break;
    }

    return !possible;
}

void combinations(int depth, int index)
{
    if (is_finished)
        return;

    if (depth == 3)
    {
        if (is_possible())
            is_finished = true;
        return;
    }

    for (int i = index; i < M; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        board[e[i].first][e[i].second] = 'O';
        combinations(depth + 1, i);
        visited[i] = false;
        board[e[i].first][e[i].second] = 'X';
    }
}

