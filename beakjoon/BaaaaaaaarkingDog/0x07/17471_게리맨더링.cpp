#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 12;

int N, answer = INT_MAX;
int ward[MAX];
bool A[MAX][MAX];
bool selected[MAX];
bool visited[MAX];
vector<int> a;
vector<int> b;

int differnce(int a, int b)
{
    int result;
    
    if (a > b)
        result = a - b;
    else
        result = b - a;
    
    return result;
}

int dfs(int depth, int x, vector<int>& a)
{
    int ret = 1;
    visited[x] = true;

    vector<int>::iterator iter;

    for(iter = a.begin(); iter != a.end(); iter++)
        if (visited[(*iter)] == false && A[x][(*iter)])
            ret += dfs(depth + 1, (*iter), a);
    
    return ret;
}

void combinations(int depth)
{
    if (depth == N + 1)
    {
        if (a.size() == N || b.size() == N)
            return;
        
        fill_n(&visited[0], MAX, false);
        int a_size = dfs(0, a[0], a);
        int b_size = dfs(0, b[0], b);

        if (a_size == a.size() && b_size == b.size())
        {

            vector<int>::iterator iter;
            int sum_a = 0, sum_b = 0;

            for (iter = a.begin(); iter != a.end(); iter++)
                sum_a += ward[(*iter)];
            
            for (iter = b.begin(); iter != b.end(); iter++)
                sum_b += ward[(*iter)];
            
            answer = min(answer, differnce(sum_a, sum_b));
        }

        return;
    }

    selected[depth] = true;
    a.push_back(depth);
    combinations(depth + 1);
    selected[depth] = false;
    a.pop_back();

    b.push_back(depth);
    combinations(depth + 1);
    b.pop_back();
}


int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> ward[i];
    
    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;

        while (cnt--)
        {
            int j;
            cin >> j;

            A[i][j] = true;
            A[j][i] = true;
        }
    }

    combinations(1);

    if (answer == INT_MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}
