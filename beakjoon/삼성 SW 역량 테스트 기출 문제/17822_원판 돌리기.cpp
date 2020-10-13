#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;

int N, M, T;
int board[MAX][MAX];

vector< pair<int, int> > find_equals();
void erase_equals(vector< pair<int, int> > &v);
void reset_board();
void rotate(int row[MAX], int d, int k);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> T;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    while (T--)
    {
        int x, d, k; cin >> x >> d >> k;

        for (int i = 1; i <= N; i++)
            if (i % x == 0)
                rotate(board[i - 1], d, k);
        
        vector< pair<int, int> > v = find_equals();

        if (!v.empty()) erase_equals(v); 
        else reset_board();

        // cout << "=========================\n";

        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //         cout << board[i][j] << " ";
        //     cout << "\n";
        // }
    }
    
    int answer = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            answer += board[i][j];
    
    cout << answer << "\n";

    return 0;
}

vector< pair<int, int> > find_equals()
{
    vector< pair<int, int> > v;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
                continue;

            if (board[i][j] == board[i][(j + 1) % M])
            {
                v.push_back(make_pair(i, j));
                v.push_back(make_pair(i, (j + 1) % M));
            }
            
            if (i + 1 < N && board[i][j] == board[i + 1][j])
            {
                v.push_back(make_pair(i, j));
                v.push_back(make_pair(i + 1, j));
            }
        }
    
    return v;
}

void erase_equals(vector< pair<int, int> > &v)
{
    for (vector< pair<int, int> >::iterator i = v.begin(); i != v.end(); i++)
        board[(*i).first][(*i).second] = 0;
}

void reset_board()
{
    int sum_board = 0, count_board = 0;
    double average = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j])
                sum_board += board[i][j], count_board += 1;
    
    average = (double) sum_board / (double) count_board;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j])
            {
                if (board[i][j] > average) board[i][j] -= 1;
                else if (board[i][j] < average) board[i][j] += 1;
            }
}

void rotate(int row[MAX], int d, int k)
{
    int row_c[MAX];

    for (int i = 0; i < M; i++)
        if (d == 0) row_c[(i + k) % M] = row[i];
        else row_c[i] = row[(i + k) % M];
    
    copy(&row_c[0], &row_c[0] + MAX, &row[0]);
}
