#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10001;

int N, M, cnt_max;
vector< vector<int> > graph(MAX);
int answer[MAX];
bool visited[MAX];

int dfs(int x)
{
    visited[x] = true;

    int ret = 1;

    for (vector<int>::iterator iter = graph[x].begin(); iter != graph[x].end(); iter++)
        if (visited[(*iter)] == false)
            ret += dfs((*iter));

    return ret;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        fill_n(&visited[0], MAX, false);
        int temp = dfs(i);

        answer[i] = temp;
        cnt_max = max(cnt_max, temp);
    }

    for (int i = 1; i <= N; i++)
        if (answer[i] == cnt_max)
            cout << i << " ";

    return 0;
}
