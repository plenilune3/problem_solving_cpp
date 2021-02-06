#include <iostream>
#include <queue>

using namespace std;

const int MAX = 12;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct water
{
    int x, y, cx, cy;
    bool is_merged;

    water(int x, int y, int cx, int cy, bool is_merged) : x(x), y(y), cx(cx), cy(cy), is_merged(is_merged) {};
};

int N, answer;
char board[MAX][MAX];
bool visited[MAX][MAX];
queue<water> q1, q2;
queue<water> waters[MAX][MAX];

void spread_(queue<water> &q);
void merge_();
bool is_possible();
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'S')
            {
                board[i][j] = '.';
                visited[i][j] = true;
                q1.push(water(i, j, 0, 0, false));
            }
        }
    
    int answer = 0;

    while (true)
    {
        if (is_possible() || q1.empty())
            break;
        
        answer += 1;

        spread_(q1);
        merge_();

        swap(q1, q2);
    }

    if (is_possible())
        cout << answer << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}

void spread_(queue<water> &q)
{
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        int cx = q.front().cx, cy = q.front().cy;
        bool is_merged = q.front().is_merged;
        q.pop();

        if (is_merged)
        {
            int nx = x + cx, ny = y + cy;

            if (is_out_of_range(nx, ny) || visited[nx][ny] || board[nx][ny] != '.') 
                continue;
            
            visited[nx][ny] = true;
            waters[nx][ny].push(water(nx, ny, cx, cy, is_merged));
        }
        else
        {
            for (int d = 0; d < 4; d++)
            {
                if (dx[d] == -cx && dy[d] == -cy) continue;

                int nx = x + dx[d], ny = y + dy[d];

                if (is_out_of_range(nx, ny) || visited[nx][ny] ||board[nx][ny] != '.') continue;

                visited[nx][ny] = true;
                waters[nx][ny].push(water(nx, ny, dx[d], dy[d], false));
            }
        }
    }
}

void merge_()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
        {
            if (waters[x][y].empty()) continue;

            else if (waters[x][y].size() == 1)
            {
                q2.push(waters[x][y].front());
                waters[x][y].pop();
            }
            
            else
            {
                water w(x, y, 0, 0, true);

                while (!waters[x][y].empty())
                {
                    w.cx += waters[x][y].front().cx;
                    w.cy += waters[x][y].front().cy;
                    waters[x][y].pop();
                }

                if (w.cx != 0 || w.cy != 0) q2.push(w);
            }
        }
}

bool is_possible()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j] && board[i][j] == '.')
                return false;
    
    return true;
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= N;
}
