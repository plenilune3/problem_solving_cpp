#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct cross
{
    int x, y, l;

    cross(int _x, int _y, int _l) : x(_x), y(_y), l(_l) {}
};

int N, M;
char A[MAX][MAX];
bool visited[MAX][MAX];
vector<cross> v;

bool check_cross(int x, int y, int k);
void draw_cross(int x, int y);
bool is_possible(bool visited[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
            if (A[x][y] == '*')
                draw_cross(x, y);
    
    if (is_possible(visited))
    {
        cout << v.size() << "\n";

        for (vector<cross>::iterator i = v.begin(); i != v.end(); i++)
            cout << (*i).x + 1 << " " << (*i).y + 1 << " " << (*i).l << "\n";
    }
    else
        cout << -1 << "\n";
    
    return 0;
}

bool check_cross(int x, int y, int k)
{
    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d] * k, ny = y + dy[d] * k;

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            return false;

        if (A[nx][ny] == '.')
            return false;
    }

    return true;
}

void draw_cross(int x, int y)
{
    int max_length = min(N, M);

    for (int k = 1; k <= max_length; k++)
    {
        bool possible = check_cross(x, y, k);

        if (possible)
        {
            visited[x][y] = true;

            for (int d = 0; d < 4; d++)
                visited[x + dx[d] * k][y + dy[d] * k] = true;

            v.push_back(cross(x, y, k));
        }
        else
            break;
    }
}

bool is_possible(bool visited[MAX][MAX])
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
            if (A[x][y] == '*' && !visited[x][y])
                return false;
    
    return true;
}
