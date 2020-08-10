#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 50;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

class virus
{
public:
    int x, y, time;

    virus(int _x, int _y, int _time)
    {
        x = _x, y = _y, time = _time;
    }
};

int N, M, K, answer = MAX*MAX;
int lab[MAX][MAX];
bool visited[MAX][MAX];
vector< pair<int, int> > virus_point;

void bfs()
{
    queue<virus> q;
    int dist[MAX][MAX];
    fill_n(&dist[0][0], MAX*MAX, -1);

    vector< pair<int, int> >::iterator iter;
    for (iter = virus_point.begin(); iter != virus_point.end(); iter++)
    {
        virus init((*iter).first, (*iter).second, 0);
        dist[init.x][init.y] = 0;
        q.push(init);
    }

    int time;
    int infect = 0;

    while (!q.empty())
    {
        virus c = q.front();
        q.pop();

        time = c.time;

        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (lab[nx][ny] != 1 && dist[nx][ny] == -1)
            {
                dist[nx][ny] = c.time + 1;
                virus nc(nx, ny, c.time + 1);
                q.push(nc);
                infect += 1;
            }
        }
    }

    if (infect == K)
        answer = min(time, answer);
}

void backtracking(int depth, int x, int y)
{
    if (depth == M)
    {
        bfs();
        return;
    }

    for (int i = x; i < N; i++)
        for (int j = 0; j < N; j++)
            if (lab[i][j] == 2 && visited[i][j] == false)
            {
                visited[i][j] = true;
                virus_point.push_back(make_pair(i, j));
                backtracking(depth + 1, i, j);
                visited[i][j] = false;
                virus_point.pop_back();
            }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> lab[i][j];
            
            if (lab[i][j] == 0 || lab[i][j] == 2)
                K += 1;
        }
    
    K -= M;

    backtracking(0, 0, 0);

    if (answer == MAX*MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}
