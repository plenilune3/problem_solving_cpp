#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 26;

string input;
char X;
string Y;
int N;
int in_degree[MAX], build_time[MAX];
vector< vector<int> > node(MAX);

int calculate_time(vector< vector<int> > &node);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> input)
    {
        int u = input[0] - 'A';
        cin >> build_time[u] >> Y;

        for (string::iterator i = Y.begin(); i != Y.end(); i++)
        {
            int v = (*i) - 'A';
            node[u].push_back(v);
            in_degree[v] += 1;
        }
    }

    int answer = calculate_time(node);

    cout << answer << "\n";

    return 0;
}

int calculate_time(vector< vector<int> > &node)
{
    queue<int> q;
    vector<int> build_memo(MAX, 0);

    for (int i = 0; i < MAX; i++)
        if (in_degree[i] == 0 && !build_time[i])
        {
            q.push(i);
            build_memo[i] = build_time[i];
        }
    
    for (int i = 0; i < MAX; i++)
    {
        int u = q.front();
        q.pop();

        for (vector<int>::iterator j = node[u].begin(); j != node[u].end(); j++)
        {
            int v = (*j);

            if (--in_degree[v] == 0)
                q.push(v);
            
            build_memo[v] = max(build_memo[v], build_memo[u] + build_time[v]);
        }
    }

    return *max_element(build_memo.begin(), build_memo.end());
}
