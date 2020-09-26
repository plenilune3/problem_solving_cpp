#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 1e5 + 1;

int N;
vector< vector<int> > node(MAX);
int job_time[MAX], job_memo[MAX];

int calc_time(int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&job_memo[0], MAX, -1);

    cin >> N;

    for (int u = 1; u <= N; u++)
    {
        int M;
        cin >> job_time[u];
        cin >> M;

        while (M--)
        {
            int v; cin >> v;
            node[v].push_back(u);
        }
    }

    int max_time = INT_MIN; 

    for (int u = 1; u <= N; u++)
        max_time = max(max_time, calc_time(u));
    
    cout << max_time << "\n";

    return 0;
}

int calc_time(int u)
{
    if (job_memo[u] >= 0)
        return job_memo[u];
    
    int max_time = 0;

    for (vector<int>::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
        max_time = max(max_time, calc_time((*iter)));
    
    return job_memo[u] = max_time + job_time[u];
}

