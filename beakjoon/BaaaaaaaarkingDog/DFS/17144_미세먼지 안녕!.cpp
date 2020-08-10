#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;

int A[MAX][MAX];

int R, C, T;
vector< pair<int, int> > air_cleaner;

void diffuse()
{
    int B[MAX][MAX];
    copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
            if (A[x][y] > 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) 
                        continue;
                    
                    if ((nx == air_cleaner[0].first && ny == 0) || (nx == air_cleaner[1].first && ny == 0))
                        continue;
                    
                    B[nx][ny] += A[x][y] / 5;
                    B[x][y] -= A[x][y] / 5;
                }
            }
    
    copy(&B[0][0], &B[0][0] + MAX * MAX, &A[0][0]);
}

void cleaning()
{
    int top = air_cleaner[0].first;

    for (int i = top; i >= 1; i--)
        A[i][0] = A[i-1][0];
    for (int i = 0; i < C-1; i++)
        A[0][i] = A[0][i+1];
    for (int i = 0; i < top; i++)
        A[i][C-1] = A[i+1][C-1];
    for (int i = C-1; i >= 1; i--)
        A[top][i] = A[top][i-1];
    
    A[top][0] = 0;
    A[top][1] = 0;

    int bottom = air_cleaner[1].first;

    for (int i = bottom; i < R-1; i++)
        A[i][0] = A[i + 1][0];
    for (int i = 0; i < C-1; i++)
        A[R-1][i] = A[R-1][i+1];
    for (int i = R-1; i > bottom; i--)
        A[i][C-1] = A[i-1][C-1];
    for (int i = C-1; i >= 1; i--)
        A[bottom][i] = A[bottom][i-1];
    
    A[bottom][0] = 0;
    A[bottom][1] = 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> R >> C >> T;
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> A[i][j];

            if (A[i][j] == -1)
            {
                air_cleaner.push_back(make_pair(i, j));
                A[i][j] = 0;
            }
        }
    
    while (T--)
    {
        diffuse();
        cleaning();
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }

    int answer = 0;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            answer += A[i][j];
    
    cout << answer << "\n";
    
    return 0;
}
