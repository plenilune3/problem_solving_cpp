#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4001;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0, 0 };

struct atom
{
    int x, y, d, e;
};

int board[MAX][MAX];
int T, N;
vector< atom > a;

bool all_die()
{
    for (int i = 0; i < a.size(); i++)
        if (a[i].e != 0)
            return false;
    
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        a.clear();
        int answer = 0;

        cin >> N;

        for (int i = 0; i < N; i++)
        {
            int x, y, d, e;
            cin >> x >> y >> d >> e;
            x = (x + 1000) * 2, y = (y + 1000) * 2;
            atom c = { x, y, d, e };
            a.push_back(c);
        }

        while (true)
        {
            if (all_die())
                break;
            
            int size = a.size();

            for (int i = 0; i < size; i++)
            {
                if (a[i].e == 0)
                    continue;

                int x = a[i].x, y = a[i].y, dir = a[i].d;
                board[x][y] = 0;

                int nx = x + dx[dir], ny = y + dy[dir];

                if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
                {
                    a[i].e = 0;
                    continue;
                }

                a[i].x = nx, a[i].y = ny, board[nx][ny] += a[i].e;
            }

            for (int i = 0; i < size; i++)
            {
                if (a[i].e == 0)
                    continue;
                
                int x = a[i].x , y = a[i].y;

                if (board[x][y] != a[i].e)
                {
                    answer += board[x][y];
                    board[x][y] = 0;
                    a[i].e = 0;
                }
            }
        }

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
