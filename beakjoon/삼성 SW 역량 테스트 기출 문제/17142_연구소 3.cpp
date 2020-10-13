#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, K, counter, answer = MAX * MAX;
int board[MAX][MAX];
bool selected[MAX];
vector< pair<int, int> > virus, v;

int calculate_time(vector< pair<int, int> > &v);
void combinations(int depth, int index);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                counter += 1;
            else if (board[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    
    K = (int) virus.size();

    combinations(0, 0);

    if (answer != MAX * MAX)
        cout << answer << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}

int calculate_time(vector< pair<int, int> > &v)
{
    queue< pair<int, int> > q;
    int dist[MAX][MAX];
    fill_n(&dist[0][0], MAX * MAX, -1);

    for (vector< pair<int, int> >::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        dist[(*iter).first][(*iter).second] = 0;
        q.push((*iter));
    }

    int time = 0, infected = 0;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (board[x][y] == 0)
        {
            time = dist[x][y];
            infected += 1;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (dist[nx][ny] != -1 || board[nx][ny] == 1)
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    if (infected == counter)
        return time;
    else
        return -1;
}

void combinations(int depth, int index)
{
    if (depth == M)
    {
        int time = calculate_time(v);

        if (time != -1)
            answer = min(answer, time);

        return;
    }

    for (int i = index; i < K; i++)
    {
        if (selected[i])
            continue;
        
        selected[i] = true;
        v.push_back(virus[i]);
        combinations(depth + 1, i);
        selected[i] = false;
        v.pop_back();
    }
}
