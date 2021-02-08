#include <iostream>

using namespace std;

const int MAX = 51;

int N, M;
char A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

void flip(int x, int y);
bool is_possible();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            C[i][j] = A[i][j] == B[i][j] ? '0' : '1';
    
    int answer = 0;

    for (int x = 0; x <= N - 3; x++)
        for (int y = 0; y <= M - 3; y++)
            if (C[x][y] == '1')
                flip(x, y), answer += 1;
   
    if (is_possible())
        cout << answer << "\n";
    else
        cout << -1 << "\n";
        
    return 0;
}

void flip(int x, int y)
{
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            C[i][j] = C[i][j] == '1' ? '0' : '1';
}

bool is_possible()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (C[i][j] == '1')
                return false;
    
    return true;
}