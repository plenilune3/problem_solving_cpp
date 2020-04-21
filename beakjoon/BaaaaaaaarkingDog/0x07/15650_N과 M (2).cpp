#include <cstdio>
#include <vector>

using namespace std;

int N, M;
bool visited[10] = { false };

void combinations(int depth, int index, vector<int>& result)
{
    if (depth == M)
    {
        vector<int>::iterator iter;
        for(iter = result.begin(); iter != result.end(); iter++)
            printf("%d ", (*iter));
        printf("\n");
    }
    else
    {
        for (int i = index; i <= N; i++)
            if (visited[i] == false)
            {
                visited[i] = true;
                result.push_back(i);
                combinations(depth + 1, i, result);
                visited[i] = false;
                result.pop_back();
            }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> result;
    scanf("%d %d", &N, &M);

    combinations(0, 1, result);

    return 0;
}
