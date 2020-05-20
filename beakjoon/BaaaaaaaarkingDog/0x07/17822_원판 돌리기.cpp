#include <iostream>
#include <vector>

using namespace std;

const int MAX = 51;

int N, M, T;
int A[MAX][MAX];

void rotate(int r, int d, int k)
{
    int B[M];

    if (d == 0)
        for (int i = 0; i < M; i++)
            B[(i + k) % M] = A[r][i];
    else
        for (int i = 0; i < M; i++)
            B[i] = A[r][(i + k) % M];
    
    copy(&B[0], &B[0] + M, &A[r][0]);
}

bool duplicate()
{
    vector< pair<int, int> > v;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == 0)
                continue;

            int a = j - 1 < 0 ? M - 1 : j - 1;
            int b = j + 1 >= M ? 0 : j + 1;

            if (A[i][j] == A[i][a])
            {
                v.push_back(make_pair(i, a));
                v.push_back(make_pair(i, j));
            }

            if (A[i][j] == A[i][b])
            {
                v.push_back(make_pair(i, b));
                v.push_back(make_pair(i, j));
            }

            int c = i - 1;
            int d = i + 1;

            if (c >= 1 && (A[i][j] == A[c][j]))
            {
                v.push_back(make_pair(i, j));
                v.push_back(make_pair(c, j));
            }

            if (d <= N && (A[i][j] == A[d][j]))
            {
                v.push_back(make_pair(i, j));
                v.push_back(make_pair(d, j));
            }
        }
    
    vector< pair<int, int> >::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++)
        A[(*iter).first][(*iter).second] = 0;
    
    if (v.empty())
        return false;
    else
        return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    
    while (T--)
    {
        int r, d, k;
        cin >> r >> d >> k;

        for (int i = 1; i <= N; i++)
            if (i % r == 0)
                rotate(i, d, k);

        if (duplicate() == false)
        {
            int sum = 0, cnt = 0;

            for (int i = 1; i <= N; i++)
                for (int j = 0; j < M; j++)
                    if (A[i][j])
                        sum += A[i][j], cnt += 1;
            
            float avg = (float) sum / (float) cnt;

            for (int i = 1; i <= N; i++)
                for (int j = 0; j < M; j++)
                {
                    if (A[i][j] == 0)
                        continue;

                    if (A[i][j] > avg)
                        A[i][j] -= 1;
                    else if (A[i][j] < avg)
                        A[i][j] += 1;
                }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            answer += A[i][j];
    
    cout << answer << "\n";

    return 0;
}
