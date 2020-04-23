#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 12;
const int M = 6;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

char puyo[N][M];
bool visited[N][M];

void dfs(int depth, int x, int y, char c, vector< pair <int, int> >& v)
{
    visited[x][y] = true;
    v.push_back(make_pair(x, y));

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny])
            continue;
        
        if (c == puyo[nx][ny])
            dfs(depth + 1, nx, ny, c, v);
    }
}

void gravity()
{
    for (int j = 0; j < M; j++)
        for (int i = N-1; i >= 0; i--)
            if (puyo[i][j] != '.')
                for (int k = N-1; k > i; k--)
                    if (puyo[k][j] == '.')
                    {
                        swap(puyo[i][j], puyo[k][j]);
                        break;
                    }
}

bool explode()
{
    fill_n(&visited[0][0], N*M, false);
    vector< pair<int, int> > result;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (puyo[i][j] != '.' && visited[i][j] == false)
            {
                vector< pair<int, int> > v;
                vector< pair<int ,int> >::iterator iter;
                dfs(0, i, j, puyo[i][j], v);

                if (v.size() < 4)
                    continue;

                for (iter = v.begin(); iter != v.end(); iter++)
                {
                    result.push_back((*iter));
                    int x = (*iter).first;
                    int y = (*iter).second;
                    puyo[x][y] = '.';
                }
            }
    
    gravity();
    
    return result.empty();
}


int main(int argc, char const *argv[])
{

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> puyo[i][j];
    
    int answer = 0;

    while (true)
    {
        if (explode())
            break;
        answer++;
    }

    cout << answer << "\n";

    return 0;
}
