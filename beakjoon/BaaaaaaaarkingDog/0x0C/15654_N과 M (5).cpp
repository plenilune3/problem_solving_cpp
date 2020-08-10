#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10;

int N, M;
int numbers[MAX];
bool visited[MAX];

void permutations(int depth, vector<int>& result)
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
        for(int i = 0; i < N; i++)
            if (visited[i] == false)
            {
                visited[i] = true;
                result.push_back(numbers[i]);
                permutations(depth + 1, result);
                visited[i] = false;
                result.pop_back();
            }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> result;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &numbers[i]);
    
    sort(numbers, numbers + N);

    permutations(0, result);

    return 0;
}
