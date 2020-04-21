#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int MAX = 10;

int N, M;
int numbers[MAX];
bool visited[MAX];
vector<int> result;
set< vector<int> > results;

void permutations(int depth)
{
    if (depth == M)
    {
        // results.insert(result);
        vector<int>::iterator iter;
        for(iter = result.begin(); iter != result.end(); iter++)
            printf("%d ", (*iter));
        printf("\n");
    }
    else
    {
        for (int i = 0; i < N; i++)
            if (visited[i] == false)
            {
                visited[i] = true;
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

    set<int> s1;

    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(1);

    // set<vector<int>>::iterator i;
    // for (i = results.begin(); i != results.end(); i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         printf("%d ", (*i)[j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}
