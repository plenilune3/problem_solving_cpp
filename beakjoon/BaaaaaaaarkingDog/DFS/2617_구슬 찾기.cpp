#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

int N, M;
vector<int> heavy_graph[MAX], light_graph[MAX];
bool heavy_visited[MAX], light_visited[MAX];

int dfs(int node)
{
    heavy_visited[node] = true;
    int result = 1;

    for (vector<int>::iterator iter = heavy_graph[node].begin(); iter != heavy_graph[node].end(); iter++)
    {
        int next_node = (*iter);

        if (heavy_visited[next_node])
            continue;
        
        result += dfs(next_node);
    }

    return result;
}

int rdfs(int node)
{
    light_visited[node] = true;
    int result = 1;

    for (vector<int>::iterator iter = light_graph[node].begin(); iter != light_graph[node].end(); iter++)
    {
        int next_node = (*iter);

        if (light_visited[next_node])
            continue;
        
        result += rdfs(next_node);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    int answer = 0;
    bool result[N + 1] = { false };

    while (M--)
    {
        int a, b;
        cin >> a >> b;

        heavy_graph[a].push_back(b);
        light_graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        fill_n(&heavy_visited[0], MAX, false);
        fill_n(&light_visited[0], MAX, false);

        int middle = (N + 1) / 2;

        if (dfs(i) > middle)
            result[i] = true;
        else if (rdfs(i) > middle)
            result[i] = true;
    }

    for (int i = 1; i <= N; i++)
        if (result[i])
            answer += 1;
    
    cout << answer << "\n";

    return 0;
}
