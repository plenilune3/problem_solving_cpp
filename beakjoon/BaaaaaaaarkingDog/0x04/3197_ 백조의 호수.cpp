#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1501;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

char lake[MAX][MAX];
bool visited_water[MAX][MAX], visited_swan[MAX][MAX];
int R, C, answer;
int tx, ty;
queue< pair<int, int> > wq1, wq2, sq1, sq2;

void water()
{
    while (!wq1.empty())
    {
        pair<int, int> c = wq1.front();
        wq1.pop();
        lake[c.first][c.second] = '.';

        for (int i = 0; i < 4; i++)
        {
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited_water[nx][ny])
                continue;

            visited_water[nx][ny] = true;

            if (lake[nx][ny] == '.')
                wq1.push(make_pair(nx, ny));
            else
                wq2.push(make_pair(nx, ny));
        }
    }
}

bool swan()
{
    while (!sq1.empty())
    {
        pair<int, int> c = sq1.front();
        sq1.pop();

        if (c.first == tx && c.second == ty)
            return true;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited_swan[nx][ny])
                continue;
            
            visited_swan[nx][ny] = true;

            if (lake[nx][ny] == '.')
                sq1.push(make_pair(nx, ny));
            else
                sq2.push(make_pair(nx, ny));
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            scanf("%1s", &lake[i][j]);

            if (lake[i][j] == 'L')
            {
                if (sq1.empty())
                {
                    sq1.push(make_pair(i, j));
                    visited_swan[i][j] = true;
                }
                else
                {
                    tx = i;
                    ty = j;
                }

                lake[i][j] = '.';
            }
            if (lake[i][j] == '.')
            {
                wq1.push(make_pair(i, j));
                visited_water[i][j] = true;
            }
        }
    
    while (true)
    {
        water();
        
        if (swan())
            break;
        
        answer++;

        wq1 = wq2;
        sq1 = sq2;
        wq2 = queue< pair<int, int> >();
        sq2 = queue< pair<int, int> >();
    }

    printf("%d\n", answer);
    
    return 0;
}
