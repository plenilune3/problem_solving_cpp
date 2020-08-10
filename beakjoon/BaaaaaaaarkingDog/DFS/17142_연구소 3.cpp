#include <iostream>
#include <queue>

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

int N, M, K, answer = MAX * MAX;
bool selected[10];
int lab[MAX][MAX];
vector< pair<int, int> > virus_point;
vector< pair<int, int> > activate;

void bfs()
{
    bool visited[MAX][MAX];
    fill_n(&visited[0][0], MAX*MAX, false);
    queue<virus> q;

    vector< pair<int, int> >::iterator iter;
    for (iter = activate.begin(); iter != activate.end(); iter++)
    {
        virus init((*iter).first, (*iter).second, 0);
        visited[init.x][init.y] = true;
        q.push(init);
    }

    int time = 0, infected = 0;
    while (!q.empty())
    {
        virus c = q.front();
        q.pop();

        if (lab[c.x][c.y] == 0)
        {
            infected += 1;
            time = c.time;
        }

        for (int i = 0; i < 4 ; i++)
        {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
                continue;
            
            if (lab[nx][ny] != 1)
            {
                visited[nx][ny] = true;
                virus nc(nx, ny, c.time + 1);
                q.push(nc);
            }
        }
    }

    if (infected == K)
        answer = min(answer, time);
}

void combinations(int depth, int length, int index)
{
    if (depth == M)
    {
        bfs();
        return;
    }

    for (int i = index; i < length; i++)
    {
        if (selected[i] == false)
        {
            selected[i] = true;
            activate.push_back(virus_point[i]);
            combinations(depth + 1, length, i);
            selected[i] = false;
            activate.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> lab[i][j];

            if (lab[i][j] == 2)
                virus_point.push_back(make_pair(i, j));
            if (lab[i][j] == 0)
                K += 1;
        }
    
    combinations(0, virus_point.size(), 0);

    if (answer == MAX * MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";
    
    return 0;
}
