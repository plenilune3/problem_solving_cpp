#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1000;
char building[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct info
{
    int x;
    int y;
    int depth;
};

int W, H;
queue< info > p;
queue< pair <int, int> > f;

int bfs()
{
    while (!p.empty())
    {
        int length_fire = f.size();
        for (int k = 0; k < length_fire; k++)
        {
            pair<int, int> c = f.front();
            f.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = c.first + dx[i];
                int ny = c.second + dy[i];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                
                if (building[nx][ny] == '.')
                {
                    building[nx][ny] = '*';
                    f.push(make_pair(nx, ny));
                }
            }
        }
        
        int length_person = p.size();
        for (int k = 0; k < length_person; k++)
        {
            info c = p.front();
            p.pop();

            if (c.x == 0 || c.x == H - 1 || c.y == 0 || c.y == W - 1)
                return c.depth + 1;

            for (int i = 0; i < 4; i++)
            {
                int nx = c.x + dx[i];
                int ny = c.y + dy[i];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                
                if (visited[nx][ny] == false && building[nx][ny] != '#' && building[nx][ny] != '*')
                {
                    visited[nx][ny] = true; 
                    p.push({nx, ny, c.depth + 1});
                }
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        while (!p.empty())
            p.pop();
        while (!f.empty())
            f.pop();
            
        fill_n(&visited[0][0], MAX*MAX, 0);

        cin >> W >> H;

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> building[i][j];
                
                if (building[i][j] == '@')
                {
                    p.push({i, j, 0});
                    visited[i][j] = true;
                }
                else if (building[i][j] == '*')
                    f.push(make_pair(i, j));
            }
        }

        int answer = bfs();

        if (answer == -1)
            cout << "IMPOSSIBLE" << "\n";
        else
            cout << answer << "\n";

    }

    return 0;
}
