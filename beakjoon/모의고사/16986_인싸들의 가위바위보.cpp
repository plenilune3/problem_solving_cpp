#include <iostream>

using namespace std;

const int MAX = 11;

int N, K;
int board[MAX][MAX];
int A[3][20];
bool selected[MAX];
bool answer;

void permuations(int depth);
bool play();

int main(int argc, char const *argv[])
{
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    
    for (int i = 1; i < 3; i++)
        for (int j = 0; j < 20; j++)
            cin >> A[i][j];
    
    permuations(0);

    cout << answer << "\n";
    
    return 0;
}

bool play()
{
    int winning_count[3] = { 0, 0, 0 };
    int player_count[3] = { 0, 0, 0 };

    int player1 = 0, player2 = 1;

    while (true)
    {
        if (winning_count[0] == K || winning_count[1] == K || winning_count[2] == K || player_count[0] == N)
            break;
        
        if (player1 > player2)
            swap(player1, player2);
        
        if (board[A[player1][player_count[player1]]][A[player2][player_count[player2]]] == 2)
        {
            player_count[player1] += 1, player_count[player2] += 1;
            winning_count[player1] += 1;
            player2 = 3 - (player1 + player2);
        }
        else
        {
            player_count[player1] += 1, player_count[player2] += 1;
            winning_count[player2] += 1;
            player1 = 3 - (player1 + player2);
        }
    }

    return winning_count[0] == K;
}

void permuations(int depth)
{
    if (answer)
        return;

    if (depth == N)
    {
        if (play())
            answer = true;

        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (selected[i]) continue;

        selected[i] = true;
        A[0][depth] = i;
        permuations(depth + 1);
        selected[i] = false;
        A[0][depth] = 0;
    }
}
