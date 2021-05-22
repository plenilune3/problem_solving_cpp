#include <iostream>

using namespace std;

const int MAX = 100;

int N, cnt;
char players[7][MAX];

void make_team(int depth, int left, int right);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < MAX; j++)
            players[i][j] = j % 2 ? 'A' : 'B';

    cin >> N;

    make_team(0, 0, N - 1);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < N; j++)
            cout << players[i][j];
        cout << "\n";
    }

    return 0;
}

void make_team(int depth, int left, int right)
{
    if (left == right || depth == 7)
        return;
    
    int mid = (left + right) / 2;

    for (int i = left; i <= right; i++)
        players[depth][i] = i <= mid ? 'A' : 'B';
    
    make_team(depth + 1, left, mid);
    make_team(depth + 1, mid + 1, right);
}
