#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    char arr[400005], p[100005];
    deque<char*> dq;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        dq.clear();
        int n;
        scanf("%s %d %s", p, &n, arr);
        bool possible = true;
        bool reverse = false;

        char *temp = strtok(arr, "[,]");
        while (temp)
        {
            dq.push_back(temp);
            temp = strtok(NULL ,"[,]");
        }

        // for (int j = 0; j < n; j++)
        // {
        //     printf("%s ", dq[j]);
        // }
        // printf("\n");

        int length = strlen(p);
        for (int j = 0; j < length; j++)
        {
            if (p[j] == 'R')
            {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else if (p[j] == 'D')
            {
                if (dq.empty())
                {
                    possible = false;
                    break;
                }
                else
                {
                    if (reverse)
                        dq.pop_back();
                    else
                        dq.pop_front();
                }
            }
        }

        if (possible)
        {
            int length = dq.size();
            if (dq.empty())
                printf("[]\n");
            else if (!reverse)
            {
                printf("[");
                for (int j = 0; j < length-1; j++)
                {
                   printf("%s,", dq[j]); 
                }
                printf("%s]\n", dq[length-1]);
            }
            else
            {
                printf("[");
                for (int j = length - 1; j > 0; j--)    
                {
                    printf("%s,", dq[j]);
                }
                printf("%s]\n", dq[0]);
            }
            
        }
        else
        {
            printf("error\n");
        }
        
    }
    return 0;
}
