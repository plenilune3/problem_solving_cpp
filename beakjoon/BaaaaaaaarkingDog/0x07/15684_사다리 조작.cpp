#include <iostream>

using namespace std;

const int N_MAX = 12;
const int H_MAX = 32;

int N, M, H, answer = 4;
bool ladder[H_MAX][N_MAX] = { false };

int down(int x, int y)
{
    while (x < H + 1)
    {
        if (ladder[x][y])
            y += 1;
        else if (ladder[x][y-1])
            y -= 1;
        
        x += 1;
    }

    return y;
}

bool possible()
{
    for (int i = 1; i <= N; i++)
        if (i != down(1, i))
            return false;
    
    return true;
}

void backtracking(int depth, int x, int y)
{
    if (answer <= depth)
        return;

    if (possible())
    {
        answer = min(answer, depth);
        return;
    }

    if (depth == 3)
        return;
    
    for (int i = x; i <= H; i++)
        for (int j = 0; j <= N - 1; j++)
            if (ladder[i][j] == false)
            {
                if (ladder[i][j-1] || ladder[i][j+1])
                    continue;
                
                ladder[i][j] = true;
                backtracking(depth + 1, i, j);
                ladder[i][j] = false;
            }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        ladder[a][b] = true;
    }

    backtracking(0, 1, 1);

    if (answer <= 3)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
