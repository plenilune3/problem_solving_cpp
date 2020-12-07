#include <iostream>

using namespace std;

const int MAX = 65;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, Q, L;
int A[MAX][MAX];
bool visited[MAX][MAX];

void find_(int x, int y, int l);
void melt_(int l);
void rotate_(int x, int y, int l);
int dfs(int x, int y, int l);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;

    int l = (1 << N);

    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
            cin >> A[i][j];
    
    while (Q--)
    {
        cin >> L;

        if (L != 0)
            find_(0, 0, l);

        melt_(l);
    }

    int sum_ = 0, result = 0;

    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
        {
            sum_ += A[i][j];

            if (visited[i][j] || A[i][j] == 0)
                continue;
            
            result = max(result, dfs(i, j, l));
        }
    
    cout << sum_ << "\n";
    cout << result << "\n";

    return 0;
}

void find_(int x, int y, int l)
{
    if (l == (1 << L))
    {
        rotate_(x, y, l);
        return;
    }

    find_(x, y, l / 2);
    find_(x + l / 2, y, l / 2);
    find_(x, y + l / 2, l / 2);
    find_(x + l / 2, y + l / 2, l / 2);
}

void melt_(int l)
{
    int A_copy[MAX][MAX];
    copy(&A[0][0], &A[0][0] + MAX * MAX, &A_copy[0][0]);

    for (int x = 0; x < l; x++)
        for (int y = 0; y < l; y++)
        {
            if (A[x][y] == 0)
                continue;

            int count_ = 0;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;
                
                if (A[nx][ny] != 0)
                    count_ += 1;
            }

            if (count_ < 3)
                A_copy[x][y] -= 1;
        }
    
    copy(&A_copy[0][0], &A_copy[0][0] + MAX * MAX, &A[0][0]);
}

void rotate_(int x, int y, int l)
{
    int A_copy[l][l];
    
    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
            A_copy[i][j] = A[i + x][j + y];

    for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
            A[i + x][j + y] = A_copy[l - 1 - j][i];
}

int dfs(int x, int y, int l)
{
    visited[x][y] = true;
    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= l || ny < 0 || ny >= l)
            continue;
        
        if (visited[nx][ny] || A[nx][ny] == 0)
            continue;
        
        ret += dfs(nx, ny, l);
    }

    return ret;
}

