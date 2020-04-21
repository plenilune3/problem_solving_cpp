#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10;

int N, M;
vector<int> result;
int numbers[MAX];
bool visited[MAX];

void combinations(int depth, int index)
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
        for (int i = index; i < N; i++)
            if (visited[i] == false)
            {
                visited[i] = true;
                result.push_back(numbers[i]);
                combinations(depth + 1, i);
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
    
    combinations(0, 0);

    return 0;
}
