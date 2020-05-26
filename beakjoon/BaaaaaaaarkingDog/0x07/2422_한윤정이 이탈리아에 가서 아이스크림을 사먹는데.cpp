#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 201;

int N, M, answer;
bool selected[MAX];
bool check[MAX][MAX];
vector<int> v;

void combinations(int depth, int index)
{
    if (depth == 3)
    {
        if (!check[v[0]][v[1]] && !check[v[1]][v[2]] && !check[v[0]][v[2]])
            answer += 1;
        
        return;
    }

    for (int i = index; i <= N; i++)
        if (selected[i] == false)
        {
            selected[i] = true;
            v.push_back(i);
            combinations(depth + 1, i);
            selected[i] = false;
            v.pop_back();
        }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        check[a][b] = check[b][a] = true;
    }

    combinations(0, 1);

    cout << answer << "\n";

    return 0;
}
