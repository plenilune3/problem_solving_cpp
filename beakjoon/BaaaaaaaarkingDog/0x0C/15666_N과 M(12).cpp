#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10;

int N, M;
int numbers[MAX];
vector<int> result;

void combinations_with_replace(int depth, int index)
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
        int before = -1;
        for (int i = index; i < N; i++)
            if (before != numbers[i])
            {
                before = numbers[i];
                result.push_back(numbers[i]);
                combinations_with_replace(depth + 1, i);
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

    combinations_with_replace(0, 0);

    return 0;
}
