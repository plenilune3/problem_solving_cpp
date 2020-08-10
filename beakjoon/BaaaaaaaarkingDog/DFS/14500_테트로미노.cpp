#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 502;

bool desc(int a, int b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, answer = 0;
    int board[MAX][MAX] = { 0 };

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M-1; j++)
        {
            int tetromino;
            int sub[] = {board[i-1][j], board[i-1][j+1], board[i][j+2], 
                            board[i+1][j+1], board[i+1][j], board[i][j-1]};
            
            sort(sub, sub + 6, desc);
            tetromino = board[i][j] + board[i][j+1] + sub[0] + sub[1];

            answer = max(answer, tetromino);
        }

    for (int i = 1; i <= N-1; i++)
        for (int j = 1; j <= M; j++)
        {
            int tetromino;
            int sub[] = {board[i-1][j], board[i][j+1], board[i+1][j+1], 
                            board[i+2][j], board[i+1][j-1], board[i][j-1]};
            
            sort(sub, sub + 6, desc);
            tetromino = board[i][j] + board[i+1][j] + sub[0] + sub[1];

            answer = max(answer, tetromino);
        }
    
    cout << answer << "\n";

    return 0;
}
