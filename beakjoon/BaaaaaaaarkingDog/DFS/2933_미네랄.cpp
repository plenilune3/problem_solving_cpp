#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int MAX = 100;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C, N;
char mineral[MAX][MAX];
bool visited[MAX][MAX];
vector< pair<int, int> > a;
vector< pair<int, int> > b;

void dfs(int x, int y, vector< pair<int, int> >& v)
{
    visited[x][y] = true;
    v.push_back(make_pair(x, y));

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        
        if (mineral[nx][ny] == 'x' && visited[nx][ny] == false)
            dfs(nx, ny, v);
    }
}


void throw_stick(int height, bool direction)
{
    if (direction)
    {
        for (int i = 0; i < C; i++)
            if (mineral[height][i] == 'x')
            {
                mineral[height][i] = '.';
                break;
            }
    }
    else
    {
        for (int i = C - 1; i >= 0; i--)
            if (mineral[height][i] == 'x')
            {
                mineral[height][i] = '.';
                break;
            }
    }
}

void down()
{
    char mineral_copy[MAX][MAX];
    fill_n(&mineral_copy[0][0], MAX * MAX, '.');
    vector< pair<int, int> >::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++)
        mineral_copy[(*iter).first][(*iter).second] = 'x';
    
    int move_cnt = INT_MAX;
    for (iter = b.begin(); iter != b.end(); iter++)
    {
        int x = (*iter).first;
        int y = (*iter).second;
        int cnt = 1;

        while (true)
        {
            if (x + cnt >= R)
            {
                cnt -= 1;
                break;
            }

            if (mineral_copy[x + cnt][y] == 'x')
            {
                cnt -= 1;
                break;
            }

            cnt += 1;
        }

        move_cnt = min(move_cnt, cnt);
    }

    for (iter = b.begin(); iter != b.end(); iter++)
    {
        int x = (*iter).first;
        int y = (*iter).second;

        mineral_copy[x + move_cnt][y] = 'x';
    }

    copy(&mineral_copy[0][0], &mineral_copy[0][0] + MAX * MAX, &mineral[0][0]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> mineral[i][j];
    
    cin >> N;

    bool direction = true;

    while (N--)
    {
        fill_n(&visited[0][0], MAX*MAX, false);
        a.clear();
        b.clear(); 

        int height;
        cin >> height;
        height = R - height;

        throw_stick(height, direction);
        direction = !direction;
        
        for (int i = 0; i < C; i++)
            if (mineral[R - 1][i] == 'x' && visited[R - 1][i] == false)
                dfs(R - 1, i, a);
        
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (mineral[i][j] == 'x' && visited[i][j] == false)
                    dfs(i, j, b);
        
        if (b.size() > 0)
            down();
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << mineral[i][j];
        cout << "\n";
    }

    return 0;
}