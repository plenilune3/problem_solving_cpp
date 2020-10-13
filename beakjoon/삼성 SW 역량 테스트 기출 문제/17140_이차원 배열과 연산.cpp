#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX = 100;

int R, C, K, N, M;
int board[MAX][MAX];
map<int, int> counter;

void calculate_R();
void calculate_C();

int main(int argc, char const *argv[])
{
    cin >> R >> C >> K;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];
    
    N = 3, M = 3;

    int time = 0;

    while (true)
    {
        if (time > 100) break;

        if (board[R - 1][C - 1] == K) break;

        if (N >= M) calculate_R();
        else calculate_C();

        time += 1;
    }

    if (time <= 100)
        cout << time << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}

void calculate_R()
{
    int max_k = M;

    for (int i = 0; i < N; i++)
    {
        vector< pair<int, int> > v;
        map<int, int> counter;

        for (int j = 0; j < M; j++)
            if (board[i][j])
            {
                counter[board[i][j]] += 1;
                board[i][j] = 0;
            }
        
        for (map<int, int>::iterator iter = counter.begin(); iter != counter.end(); iter++)
            v.push_back(make_pair((*iter).second, (*iter).first));
        
        sort(v.begin(), v.end());

        int k = min(MAX / 2, (int) v.size());

        for (int j = 0; j < k; j ++)
            board[i][j * 2] = v[j].second, board[i][j * 2 + 1] = v[j].first;
        
        max_k = max(max_k, k * 2);
    }

    M = max_k;
}

void calculate_C()
{
    int max_k = N;

    for (int j = 0; j < M; j++)
    {
        vector< pair<int, int> > v;
        map<int, int> counter;

        for (int i = 0; i < N; i++)
            if (board[i][j])
            {
                counter[board[i][j]] += 1;
                board[i][j] = 0;
            }
        
        for (map<int, int>::iterator iter = counter.begin(); iter != counter.end(); iter++)
            v.push_back(make_pair((*iter).second, (*iter).first));
        
        sort(v.begin(), v.end());

        int k = min(MAX / 2, (int) v.size());

        for (int i = 0; i < k; i ++)
            board[i * 2][j] = v[i].second, board[i * 2 + 1][j] = v[i].first;

        max_k = max(max_k, k * 2);
    }

    N = max_k;
}
