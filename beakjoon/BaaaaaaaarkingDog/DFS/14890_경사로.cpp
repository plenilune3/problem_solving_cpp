#include <iostream>

using namespace std;

const int MAX = 101;

int N, L, answer;
int board[MAX][MAX];

void ramp(int i, bool c)
{
    int cnt = 1;

    for (int j = 0; j < N-1; j++)
    {
        int d = c == true ? board[i][j+1] - board[i][j] : board[j+1][i] - board[j][i];
        if (d == 0) cnt += 1;
        else if (d == 1 && cnt >= L) cnt = 1;
        else if (d == -1 && cnt >= 0) cnt = -L+1;
        else return;
    }

    if(cnt >= 0)
        answer += 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
        
    for (int i = 0; i < N; i++)
    {
        ramp(i, 0);
        ramp(i, 1);
    }

    cout << answer << "\n";

    return 0;
}


// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int board[MAX][MAX] = { 0 };
//     bool ramp_row[MAX][MAX] = { false };
//     bool ramp_col[MAX][MAX] = { false };
//     int N, L, answer = 0;

//     cin >> N >> L;

//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//             cin >> board[i][j];

//     for (int i = 0; i < N; i++)
//     {
//         bool possible = true;

//         for (int j = 0; j < N - 1; j++)
//         {
//             if (board[i][j] == board[i][j+1])
//                 continue;
            
//             else if (board[i][j] == board[i][j+1] - 1)
//             {
//                 for (int l = 0; l < L; l++)
//                     if (j - l < 0 || board[i][j] != board[i][j-l] || ramp_row[i][j-l])
//                     {
//                         possible = false;
//                         break;
//                     }
                
//                 if (possible == false)
//                     break;
                
//                 for (int l = 0; l < L; l++)
//                     ramp_row[i][j-l] = true;
//             }

//             else if (board[i][j] - 1 == board[i][j+1])
//             {
//                 for (int l = 0; l < L; l++)
//                     if (j + 1 + l >= N || board[i][j+1] != board[i][j+1+l] || ramp_row[i][j+1+l])
//                     {
//                         possible = false;
//                         break;
//                     }
                
//                 if (possible == false)
//                     break;
                
//                 for (int l = 0; l < L; l++)
//                     ramp_row[i][j+1+l] = true;
//             }

//             else
//             {
//                 possible = false;
//                 break;
//             }
//         }

//         if (possible)
//             answer += 1;
//     }

//     for (int j = 0; j < N; j++)
//     {
//         bool possible = true;

//         for (int i = 0; i < N - 1; i++)
//         {
//             if (board[i][j] == board[i+1][j])
//                 continue;
            
//             else if (board[i][j] == board[i+1][j] - 1)
//             {
//                 for (int l = 0; l < L; l++)
//                     if (i - l < 0 || board[i][j] != board[i-l][j] || ramp_col[i-l][j])
//                     {
//                         possible = false;
//                         break;
//                     }
                
//                 if (possible == false)
//                     break;
                
//                 for (int l = 0; l < L; l++)
//                     ramp_col[i-l][j] = true;
//             }

//             else if (board[i][j] - 1 == board[i+1][j])
//             {
//                 for (int l = 0; l < L; l++)
//                     if (i + 1 + l >= N || board[i+1][j] != board[i+1+l][j] || ramp_col[i+1+l][j])
//                     {
//                         possible = false;
//                         break;
//                     }
                
//                 if (possible == false)
//                     break;
                
//                 for (int l = 0; l < L; l++)
//                     ramp_col[i+1+l][j] = true;
//             }

//             else
//             {
//                 possible = false;
//                 break;
//             }
//         }

//         if (possible)
//             answer += 1;
//     }

//     cout << answer << "\n";

//     return 0;
// }
