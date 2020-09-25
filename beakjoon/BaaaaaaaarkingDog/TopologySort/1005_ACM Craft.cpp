#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e3 + 1;

int N, K, W;
int build_time[MAX], build_memo[MAX];
vector< vector<int> > node(MAX);

int calc_min_time(int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        fill(node.begin(), node.end(), vector<int> ());
        fill_n(&build_memo[0], MAX, -1);

        cin >> N >> K;

        for (int i = 1; i <= N; i++)
            cin >> build_time[i];
        
        for (int i = 0; i < K; i++)
        {
            int u, v; cin >> u >> v;
            node[v].push_back(u);
        }

        cin >> W;

        int answer = calc_min_time(W);
        cout << answer << "\n";
    }

    return 0;
}

int calc_min_time(int u)
{
    if (build_memo[u] >= 0)
        return build_memo[u];
    
    int max_time = 0;

    for (vector<int>::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
        max_time = max(max_time, calc_min_time((*iter)));
    
    return build_memo[u] = max_time + build_time[u];
}
// int N, K, W;
// int in_degree[MAX];
// int t[MAX];
// vector< vector<int> > node(MAX);

// int find_time(int target);

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     int T; cin >> T;

//     while (T--)
//     {
//         fill_n(&in_degree[0], MAX, 0);
//         fill(node.begin(), node.end(), vector<int> ());

//         cin >> N >> K;

//         for (int i = 1; i <= N; i++)
//             cin >> t[i];
        
//         for (int i = 0; i < K; i++)
//         {
//             int u, v; cin >> u >> v;
//             node[u].push_back(v);
//             in_degree[v] += 1;
//         }

//         cin >> W;

//         int answer = find_time(W);
//         cout << answer << "\n";
//     }

//     return 0;
// }

// int find_time(int target)
// {
//     vector<int> result(N + 1);
//     queue<int> q;

//     for (int i = 1; i <= N; i++)
//     {
//         result[i] = t[i];

//         if (in_degree[i] == 0)
//             q.push(i);
//     }

//     for (int i = 1; i <= N; i++)
//     {
//         int u = q.front();
//         q.pop();

//         if (u == target)
//             return result[u];
        
//         for (vector<int>::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
//         {
//             int v = (*iter);

//             result[v] = max(result[v], result[u] + t[v]);

//             if (--in_degree[v] == 0)
//                 q.push(v);
//         }
//     }
    
//      return -1;
// }
