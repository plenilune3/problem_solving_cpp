#include <vector>
#include <cstdio>

using namespace std;

const int MAX = 13;

int k;
int nums[MAX];
bool visited[MAX];
vector<int> result;

void backtracking(int depth, int index)
{
    if (depth == 6)
    {
        vector<int>::iterator iter;
        for (iter = result.begin(); iter != result.end(); iter++)
            printf("%d ", (*iter));
        printf("\n");
    }
    else
    {
        for (int i = index; i < k; i++)
            if (visited[i] == false)
            {
                visited[i] = true;
                result.push_back(nums[i]);
                backtracking(depth + 1, i);
                visited[i] = false;
                result.pop_back();
            }
    }
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        fill_n(&visited[0], MAX, false);

        scanf("%d", &k);

        if (k == 0)
            break;
        
        for (int i = 0; i < k; i++)
            scanf("%d", &nums[i]);

        backtracking(0, 0);
        printf("\n");
    }
    return 0;
}
