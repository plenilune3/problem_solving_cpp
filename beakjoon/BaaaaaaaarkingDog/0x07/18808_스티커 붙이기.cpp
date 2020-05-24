#include <iostream>
#include <climits>

using namespace std;

const int MAX_A = 40;
const int MAX_S = 10;
const int MAX_count = 100;

struct sticker
{
    int R, C;
    bool S[MAX_S][MAX_S];
};


bool A[MAX_A][MAX_A];
sticker S[MAX_count];
bool visited[MAX_count];
int N, M, K, answer = INT_MIN;

void rotate(sticker& S)
{
    bool S_copy[MAX_S][MAX_S] = { false };

    for (int i = 0; i < S.R; i++)
        for (int j = 0; j < S.C; j++)
            S_copy[j][S.R - 1 - i] = S.S[i][j];
    
    int temp;
    temp = S.R; S.R = S.C, S.C = temp;
    copy(&S_copy[0][0], &S_copy[0][0] + MAX_S * MAX_S, &S.S[0][0]);
}

bool is_possible(sticker& S, int x, int y)
{
    if (x + S.R > N || y + S.C > M)
        return false;

    for (int i = 0; i < S.R; i++)
        for (int j = 0; j < S.C; j++)
            if (S.S[i][j] && A[x + i][y + j])
                return false;
    
    return true;
}

void attach(sticker& S, int x, int y)
{
    for (int i = 0; i < S.R; i++)
        for (int j = 0; j < S.C; j++)
            if (S.S[i][j])
                A[x + i][y + j] = true;
}

void detach(sticker& S, int x, int y)
{
    for (int i = 0; i < S.R; i++)
        for (int j = 0; j < S.C; j++)
            if (S.S[i][j])
                A[x + i][y + j] = false;
}

void dfs(int depth)
{
    if (depth == K)
    {
        int result = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (A[i][j])
                    result += 1;

        answer = max(answer, result);

        return;
    }

    bool possible = false;

    for (int n = 0; n < 4; n++)
    {

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                if (is_possible(S[depth], i, j))
                {
                    possible = true;
                    attach(S[depth], i, j);
                    dfs(depth + 1);
                    detach(S[depth], i, j);
                    break;
                }

            if (possible)
                break;
        }

        if (possible)
            break;

        rotate(S[depth]);
    }
    
    if (possible == false)
        dfs(depth + 1);
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int k = 0; k < K; k++)
    {
        int R, C;
        cin >> R >> C;
        S[k].R = R, S[k].C = C;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> S[k].S[i][j];
    }

    dfs(0);
    cout << answer << "\n";

    return 0;
}
