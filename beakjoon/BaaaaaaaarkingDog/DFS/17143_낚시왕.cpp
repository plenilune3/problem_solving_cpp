#include <iostream>

using namespace std;

const int MAX = 102;
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};


struct shark
{
    int s, d, z;
};

int R, C, M;
shark A[MAX][MAX];


void move(int r, int c, shark B[MAX][MAX])
{
    shark t = A[r][c];

    if (t.d == 1 || t.d == 2)
    {
        int temp = R * 2 - 2;
        int cnt = t.s % temp;

        for (int i = 0; i < cnt; i++)
        {
            if (r + dx[t.d] < 1)
                t.d = t.d + 1;
            else if (r + dx[t.d] > R)
                t.d = t.d - 1;
            
            r = r + dx[t.d];
        }
    }
    else
    {
        int temp = C * 2 - 2;
        int cnt = t.s % temp;

        for (int i = 0; i < cnt; i++)
        {
            if (c + dy[t.d] < 1)
                t.d = t.d - 1;
            else if (c + dy[t.d] > C)
                t.d = t.d + 1;
            
            c = c + dy[t.d];
        }
    }

    if (t.z > B[r][c].z)
    {
        shark n = {t.s, t.d, t.z};
        B[r][c] = n;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;
    cin >> R >> C >> M;

    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z; 

        shark t = {s, d, z};

        A[r][c] = t;
    }

    int fishing = 0;

    while (fishing <= C)
    {
        fishing += 1;
        shark B[MAX][MAX];
        shark init = {0, 0, 0};
        fill_n(&B[0][0], MAX*MAX, init);

        for (int i = 1; i <= R; i++)
        {
            if(A[i][fishing].z != 0)
            {
                answer += A[i][fishing].z;
                shark t = {0, 0, 0};
                A[i][fishing] = t;
                break;
            }
        }

        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
            {
                if (A[i][j].z == 0)
                    continue;
                
                move(i, j, B);
            }

        copy(&B[0][0], &B[0][0] + MAX * MAX, &A[0][0]);
    }

    cout << answer << "\n";

    return 0;
}


