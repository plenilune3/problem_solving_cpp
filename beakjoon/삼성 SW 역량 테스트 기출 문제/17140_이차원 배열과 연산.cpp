#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX = 101;

int R, C, K, A[MAX][MAX];

void calculate_R(int &X, int &Y, int A[MAX][MAX]);
void calculate_C(int &X, int &Y, int A[MAX][MAX]);
void transpose(int &X, int &Y, int A[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C >> K;

    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            cin >> A[x][y];
    
    int answer = 0;
    int X = 3, Y = 3;

    while (true)
    {
        if (A[R - 1][C - 1] == K || answer > 100)
            break;
        
        answer += 1;

        if (X >= Y)
            calculate_R(X, Y, A);
        else
            calculate_C(X, Y, A);
    }

    if (answer <= 100)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void calculate_R(int &X, int &Y, int A[MAX][MAX])
{
    int max_y = Y;

    for (int x = 0; x < X; x++)
    {
        map<int, int> counter;
        vector< pair<int, int> > v;

        for (int y = 0; y < Y; y++)
        {
            if (A[x][y] == 0)
                continue;

            counter[A[x][y]] += 1;
            A[x][y] = 0;
        }

        for (map<int, int>::iterator i = counter.begin(); i != counter.end(); i++)
            v.push_back(make_pair((*i).second, (*i).first));
        
        sort(v.begin(), v.end());

        int k = min(MAX / 2, (int) v.size());
        max_y = max(max_y, k * 2);

        for (int i = 0; i < k; i++)
            A[x][i * 2] = v[i].second, A[x][i * 2 + 1] = v[i].first;
    }

    Y = max_y;
}

void calculate_C(int &X, int &Y, int A[MAX][MAX])
{
    transpose(X, Y, A);
    calculate_R(X, Y, A);
    transpose(X, Y, A);
}

void transpose(int &X, int &Y, int A[MAX][MAX])
{
    int B[X][Y];

    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
        {
            B[x][y] = A[x][y];
            A[x][y] = 0;
        }

    swap(X, Y);

    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            A[x][y] = B[y][x];
}