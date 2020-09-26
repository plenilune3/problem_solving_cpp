#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e3 + 1;

int N, M;
int in_degree[MAX];
vector< vector<int> > node(MAX);

vector<int> find_order();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int K; cin >> K;
        int prev_singer = 0;

        while (K--)
        {
            int cur_singer = 0;
            cin >> cur_singer;

            if (prev_singer != 0)
            {
                node[prev_singer].push_back(cur_singer);
                in_degree[cur_singer] += 1;
            }
            
            prev_singer = cur_singer;
        }
    }

    vector<int> answer = find_order();

    for (vector<int>::iterator iter = answer.begin(); iter != answer.end(); iter++)
        cout << (*iter) << "\n";
    
    return 0;
}

vector<int> find_order()
{
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (in_degree[i] == 0)
            q.push(i);
    
    for (int i = 1; i <= N; i++)
    {
        if (q.empty())
            return vector<int> (1, 0);
        
        int u = q.front(); q.pop();

        result.push_back(u);

        for (vector<int>::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
        {
            int v = (*iter);

            if (--in_degree[v] == 0)
                q.push(v);
        }
    }

    return result;
}
