#include <iostream>
#include <queue>

using namespace std;

struct cell
{
    int state, life, time_active, time_unactive;
};

const int MAX = 350;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

cell board[MAX][MAX];
int T, N, M, K;

void time_count(queue< pair<int, int> > &q)
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            if (board[i][j].state == 0)
            {
                if (board[i][j].time_unactive > 0)
                    board[i][j].time_unactive -= 1;
                if (board[i][j].time_unactive == 0)
                    board[i][j].state = 1;
            }
            else if (board[i][j].state == 1)
            {
                if (board[i][j].time_active > 0)
                {
                    q.push(make_pair(i, j));
                    board[i][j].time_active -= 1;
                }
                if (board[i][j].time_active == 0)
                    board[i][j].state = 2;
            }
        }
}

void bfs(queue< pair<int, int> > &q)
{
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (board[nx][ny].state == -1)
            {
                cell c = { 0, board[x][y].life, board[x][y].life, board[x][y].life };
                board[nx][ny] = c;
            }
            else if (board[nx][ny].state == 0 && board[nx][ny].life == board[nx][ny].time_unactive)
            {
                if (board[nx][ny].life < board[x][y].life)
                {
                    board[nx][ny].life = board[x][y].life;
                    board[nx][ny].time_active = board[x][y].life;
                    board[nx][ny].time_unactive = board[x][y].life;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> N >> M >> K;

        cell init = { -1, 0, 0, 0 };

        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                board[i][j] = init;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                int life;
                cin >> life;

                if (life > 0)
                {
                    cell c = { 0, life, life, life };
                    board[i + 150][j + 150] = c;
                }
            }
        
        while(K--)
        {
            queue< pair<int, int> > q;
            time_count(q);
            bfs(q);
        }

        int cnt = 0;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                if (board[i][j].state == 0 || board[i][j].state == 1)
                    cnt += 1;
       
        cout << "#" << test_case << " " << cnt << "\n";
    }

    return 0;
}
