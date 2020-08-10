#include <cstdio>
#include <vector>

using namespace std;

int N, M;

void products(int depth, vector<int>& result)
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
        for (int i = 1; i <= N; i++)
        {
            result.push_back(i);
            products(depth + 1, result);
            result.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> result;
    scanf("%d %d", &N, &M);

    products(0, result);

    return 0;
}
