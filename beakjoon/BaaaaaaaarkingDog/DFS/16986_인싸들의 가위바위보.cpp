#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 11;

int N, K;
int A[MAX][MAX];
int B[3][20];
bool visited[MAX];
bool answer;

void game()
{
    int winning_cnt[3] = { 0, 0, 0 };
    int player_cnt[3] = { 0, 0, 0 };

    int p1 = 0;
    int p2 = 1;

    while (true)
    {
        if (winning_cnt[0] == K)
        {
            answer = true;
            break;
        }
        if (winning_cnt[1] == K || winning_cnt[2] == K || player_cnt[0] == N)
            break;

        if (p1 > p2)
            swap(p1, p2);

        if (A[B[p1][player_cnt[p1]]][B[p2][player_cnt[p2]]] == 2)
        {
            player_cnt[p1] += 1, player_cnt[p2] += 1;
            winning_cnt[p1] += 1;
            p2 = 3 - (p1 + p2);
        }
        else
        {
            player_cnt[p1] += 1, player_cnt[p2] += 1;
            winning_cnt[p2] += 1;
            p1 = 3 - (p1 + p2);
        }
    }
}

void permutations(int depth)
{
    if (answer)
        return;

    if (depth == N)
    {
        game();
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            B[0][depth] = i;
            permutations(depth + 1);
            visited[i] = false;
            B[0][depth] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];
    
    for (int i = 1; i < 3; i++)
        for (int j = 0; j < 20; j++)
            cin >> B[i][j];
    
    permutations(0);

    cout << answer << "\n";

    return 0;
}
