#include <iostream>

using namespace std;

const int MAX = (1 << 6) + 1;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, Q, L, A[MAX][MAX];
bool visited[MAX][MAX];

void rotate(int l, int A[MAX][MAX]);
void melt(int L, int A[MAX][MAX]);
int count_max_area(int L, int A[MAX][MAX]);
int count_area(int x, int y);
int sum_ice(int L, int A[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;

    L = (1 << N);

    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            cin >> A[i][j];
    
    while (Q--)
    {
        int l; cin >> l;

        l = (1 << l);

        rotate(l, A);
        melt(L, A);
    }

    cout << sum_ice(L, A) << "\n";
    cout << count_max_area(L, A) << "\n";

    return 0;
}

void rotate(int l, int A[MAX][MAX])
{
    for (int i = 0; i < L; i += l)
    {
        for (int j = 0; j < L; j += l)
        {
            int B[l][l];

            for (int x = 0; x < l; x++)
                for (int y = 0; y < l; y++)
                    B[x][y] = A[x + i][y + j];
            
            for (int x = 0; x < l; x++) 
                for (int y = 0; y < l; y++)
                    A[x + i][y + j] = B[l - 1 - y][x];
        }
    }
}

void melt(int L, int A[MAX][MAX])
{
    int B[MAX][MAX];
    copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

    for (int x = 0; x < L; x++)
        for (int y = 0; y < L; y++)
        {
            int ice = 0;

            if (A[x][y] == 0)
                continue;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];

                if (nx < 0 || nx >= L || ny < 0 || ny >= L)
                    continue;
                
                if (B[nx][ny] != 0)
                    ice += 1;
            }

            if (ice < 3)
                A[x][y] -= 1;
        }
}

int sum_ice(int L, int A[MAX][MAX])
{
    int result = 0;

    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            result += A[i][j];
    
    return result;
}

int count_area(int x, int y)
{
    int ret = 1;
    visited[x][y] = true;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx < 0 || nx >= L || ny < 0 || ny >= L)
            continue;
        
        if (visited[nx][ny] || A[nx][ny] == 0)
            continue;
        
        ret += count_area(nx, ny);
    }

    return ret;
}

int count_max_area(int L, int A[MAX][MAX])
{
    int result = 0;

    for (int x = 0; x < L; x++)
        for (int y = 0; y < L; y++)
        {
            if (visited[x][y] || A[x][y] == 0)
                continue;
            
            result = max(result, count_area(x, y));
        }
    
    return result;
}