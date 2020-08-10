#include <iostream>
#include <vector>

using namespace std;

const int MAX = 21;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
 
int N, M, answer;
int board[MAX][MAX];
vector< pair<int ,int> > blank;
bool seleted[MAX * MAX];
vector< pair<int, int> > v;
bool visited[MAX][MAX];

int dfs(int depth, int x, int y, bool &possible)
{
    int ret = 1;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (board[nx][ny] == 0)
            possible = false;
        
        if (visited[nx][ny] == false && board[nx][ny] == 2)
            ret += dfs(depth + 1, nx, ny, possible);
    }

    return ret;
}

void play()
{
    vector< pair<int, int> >::iterator iter;
    int temp = 0;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (visited[i][j] == false && board[i][j] == 2)
            {
                bool possible = true;
                int cnt = dfs(0, i, j, possible);

                if (possible)
                    temp += cnt;
            }
   
    answer = max(answer, temp);
}

void combinations(int depth, int length, int index)
{
    if (depth == 2)
    {
        vector< pair<int, int> >::iterator iter;
        for (iter = v.begin(); iter != v.end(); iter++)
            board[(*iter).first][(*iter).second] = 1;
        
        fill_n(&visited[0][0], MAX * MAX, false);
        play();

        for (iter = v.begin(); iter != v.end(); iter++)
            board[(*iter).first][(*iter).second] = 0;

        return; 
    }

    for (int i = index; i < length; i++)
        if (seleted[i] == false)
        {
            seleted[i] = true;
            v.push_back(blank[i]);
            combinations(depth + 1, length, i);
            seleted[i] = false;
            v.pop_back();
        }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                blank.push_back(make_pair(i, j));
        }
    
    combinations(0, blank.size(), 0);

    cout << answer << "\n";

    return 0;
}