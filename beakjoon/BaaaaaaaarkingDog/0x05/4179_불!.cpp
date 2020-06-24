#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1002;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C;
char board[MAX][MAX];
int dist_fire[MAX][MAX];
int dist_jihoon[MAX][MAX];
queue< pair<int, int> > jq1, fq1, jq2, fq2;

void fire()
{
    while (!fq1.empty())
    {
        int x = fq1.front().first, y = fq1.front().second; fq1.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= R + 2 || ny < 0 || ny >= C + 2 || dist_fire[nx][ny] != -1)
                continue;
            
            if (board[nx][ny] == '.')
            {
                dist_fire[nx][ny] = dist_fire[x][y] + 1;
                fq2.push(make_pair(nx, ny));
            }
        }
    }
}

int jihoon()
{
    while (!jq1.empty())
    {
        int x = jq1.front().first, y = jq1.front().second; jq1.pop();

        if (x == 0 || y == 0 || x == R + 1 || y == C + 1)
            return dist_jihoon[x][y];
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= R + 2 || ny < 0 || ny >= C + 2 || dist_jihoon[nx][ny] != -1)
                continue;
            
            if (board[nx][ny] == '.' && dist_fire[nx][ny] == -1)
            {
                dist_jihoon[nx][ny] = dist_jihoon[x][y] + 1;
                jq2.push(make_pair(nx, ny));
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> R >> C;

    fill_n(&dist_fire[0][0], MAX * MAX, -1);
    fill_n(&dist_jihoon[0][0], MAX * MAX, -1);

    for (int i = 0; i < R + 2; i++)
        for (int j = 0; j < C + 2; j++)
        {
            if (i == 0 || j == 0 || i == R + 1 || j == C + 1)
                board[i][j] = '.';
            else
            {
                cin >> board[i][j];

                if (board[i][j] == 'J')
                {
                    board[i][j] = '.';
                    dist_jihoon[i][j] = 0;
                    jq1.push(make_pair(i, j));
                }
                else if (board[i][j] == 'F')
                {
                    board[i][j] = '.';
                    dist_fire[i][j] = 0;
                    fq1.push(make_pair(i, j));
                }
            }
        }
    
    while (true)
    {
        fire();
        int temp = jihoon();

        if (temp != -1)
        {
            cout << temp << "\n";
            break;
        }

        if (jq2.empty())
        {
            cout << "IMPOSSIBLE\n";
            break;
        }

        fq1 = fq2, jq1 = jq2;
        fq2 = queue< pair<int, int> > (), jq2 = queue< pair<int, int> > ();
    }

    return 0;
}
