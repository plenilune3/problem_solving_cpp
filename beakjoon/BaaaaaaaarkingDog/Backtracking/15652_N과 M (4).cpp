#include <cstdio>
#include <vector>

using namespace std;

int N, M;

void combinations_with_replace(int depth, int index, vector<int>& result)
{
    if (depth == M)
    {
        vector<int>::iterator iter;
        for (iter = result.begin(); iter != result.end(); iter++)
            printf("%d ", (*iter));
        printf("\n");
    }
    else
    {
        for (int i = index; i <= N; i++)
        {
            result.push_back(i);
            combinations_with_replace(depth + 1, i, result);
            result.pop_back();
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<int> result;
    scanf("%d %d", &N, &M);

    combinations_with_replace(0, 1, result);

    return 0;
}
