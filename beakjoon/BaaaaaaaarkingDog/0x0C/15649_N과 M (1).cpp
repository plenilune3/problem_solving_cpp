#include <cstdio>
#include <vector>

using namespace std;

bool visited[10];

void permutations(int depth, int N, int M, vector<int>& result)
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
        for (int i = 1; i <= N; i++)
            if (visited[i] == false)
            {
                visited[i] = true;
                result.push_back(i);
                permutations(depth + 1, N, M, result);
                visited[i] = false;
                result.pop_back();
            }
    }
}

int main(int argc, char const *argv[])
{
    int N, M;
    vector<int> result;
    
    scanf("%d %d", &N, &M);

    permutations(0, N, M, result);
    
    return 0;
}
