#include <iostream>
#include <vector>

using namespace std;

const int MAX = 501;

int N;
int build_time[MAX], build_memo[MAX];
vector< vector<int> > node(MAX);

int calc_time(int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&build_memo[0], MAX, -1);

    cin >> N;

    for (int u = 1; u <= N; u++)
    {
        cin >> build_time[u];

        while (true)
        {
            int v; cin >> v;

            if (v == -1)
                break;
            
            node[u].push_back(v);
        }
    }

    for (int u = 1; u <= N; u++)
        cout << calc_time(u) << "\n";

    return 0;
}

int calc_time(int u)
{
    if (build_memo[u] >= 0)
        return build_memo[u];
    
    int max_time = 0;

    for (vector<int>::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
        max_time = max(max_time, calc_time((*iter)));
    
    return build_memo[u] = max_time + build_time[u];
}