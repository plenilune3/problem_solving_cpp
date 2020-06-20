#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAX = 10001;

int N, end_point, answer;
int visited[MAX];
map< int, set< pair<int, int> > > graph;

void dfs(int point, int length)
{
    visited[point] = true;

    if (answer < length)
    {
        answer = length;
        end_point = point;
    }

    for (set< pair<int, int> >::iterator iter = graph[point].begin(); iter != graph[point].end(); iter++)
        if (visited[(*iter).first] == false)
            dfs((*iter).first, length + (*iter).second);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 1; i <= N - 1; i++)
    {
        int a, b, cost;

        cin >> a >> b >> cost;

        graph[a].insert(make_pair(b, cost));
        graph[b].insert(make_pair(a, cost));
    }

    dfs(1, 0);
    fill_n(&visited[0], MAX, false);
    dfs(end_point, 0);

    cout << answer << "\n";

    return 0;
}
