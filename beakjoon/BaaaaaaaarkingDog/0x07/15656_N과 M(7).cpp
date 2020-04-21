#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10;

int N, M;
vector<int> result;
int numbers[MAX];

void products(int depth)
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
        for (int i = 0; i < N; i++)
        {
            result.push_back(numbers[i]);
            products(depth + 1);
            result.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &numbers[i]);
    
    sort(numbers, numbers + N);

    products(0);

    return 0;
}
