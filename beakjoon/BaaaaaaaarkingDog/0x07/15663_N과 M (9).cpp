#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10;

int N, M;
int numbers[MAX];
bool visited[MAX];
vector<int> result;

void permutations(int depth)
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
        bool used[10001] = { false };
        for (int i = 0; i < N; i++)
            if (visited[i] == false && used[numbers[i]] == false)
            {
                visited[i] = true;
                used[numbers[i]] = true;
                result.push_back(numbers[i]);
                permutations(depth + 1);
                visited[i] = false;
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

    permutations(0);

    return 0;
}
