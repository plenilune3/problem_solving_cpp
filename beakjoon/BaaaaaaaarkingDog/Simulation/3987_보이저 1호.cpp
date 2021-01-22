#include <iostream>

using namespace std;

const int MAX = 501;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, M;
char board[MAX][MAX];
bool visited[MAX][MAX][4];
bool is_cycle;

int calculate_signal(int x, int y, int d);
int refraction(int x, int y, int d);
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];
    
    int x, y; cin >> x >> y;

    char dir[] = { 'U', 'R', 'D', 'L' };
    int max_spread = 0;
    int idx = 0;

    for (int i = 0; i < 4; i++)
    {
        fill_n(&visited[0][0][0], MAX * MAX * 4, false);
        int spread = calculate_signal(x - 1, y - 1, i);

        if (max_spread < spread)
        {
            idx = i;
            max_spread = spread;
        }

        if (is_cycle)
        {
            idx = i;
            break;
        }
    }

    cout << dir[idx] << "\n";

    if (is_cycle)
        cout << "Voyager" <<"\n";
    else
        cout << max_spread << "\n";

    return 0;
}

int calculate_signal(int x, int y, int d)
{
    int result = 0;

    while (true)
    {
        if (is_out_of_range(x, y) || board[x][y] == 'C' || is_cycle)
            break;
        
        if (board[x][y] == '/' || board[x][y] == '\\')
        {
            if (visited[x][y][d])
            {
                is_cycle = true;
                continue;
            }

            visited[x][y][d] = true;
            d = refraction(x, y, d);
        }

        x += dx[d], y += dy[d], result += 1;
    }

    return result;
}

int refraction(int x, int y, int d)
{
    if (board[x][y] == '/')
    {
        if (d == 0) return 1;
        else if (d == 1) return 0;
        else if (d == 2) return 3;
        else return 2;
    }
    else
    {
        if (d == 0) return 3;
        else if (d == 1) return 2;
        else if (d == 2) return 1;
        else return 0;
    }
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= M;
}