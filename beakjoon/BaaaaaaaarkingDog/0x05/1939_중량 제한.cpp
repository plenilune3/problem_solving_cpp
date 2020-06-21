#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10001;

int N, M, answer;
bool visited[MAX];
vector< pair<int, int> > graph[MAX];

bool dfs(int a, int b, int w)
{
    visited[a] = true;

    if (a == b)
        return true;
    
    for (vector< pair<int, int> >::iterator iter = graph[a].begin(); iter != graph[a].end(); iter++)
    {
        if (visited[(*iter).first] == false && w <= (*iter).second)
            if (dfs((*iter).first, b, w))
                return true;
            else
                continue;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;

    while (M--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    
    int A, B;
    cin >> A >> B;

    int left = 0, right = 1000000000;
    while (left <= right)
    {
        fill_n(&visited[0], MAX, false);
        int mid = (left + right) / 2;

        if (dfs(A, B, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    cout << answer << "\n";

    return 0;
}
