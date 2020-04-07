#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int dwarves[9];
bool visited[9];
bool flag = false;

void backtracking(int depth, int N, int index, int result=0)
{
    if (result > 100)
        return;
    if (flag)
        return;

    if (depth == 7)
    {
        if (result == 100)
        {
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
            {
                printf("%d\n", v[i]);
            }
            flag = true;
        }
        else
        {
            return;
        }
    }
    else
    {
        for (int i = index; i < 9; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                v.push_back(dwarves[i]);
                backtracking(depth+1, N, i+1, result+dwarves[i]);
                v.pop_back();
                visited[i] = false;
            }

        }
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &dwarves[i]);
    }

    backtracking(0, 7, 0);

    return 0;
}
