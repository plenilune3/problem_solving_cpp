#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int MAX = 52;

struct rotate
{
    int r, c, s;
};

int N, M, K, answer = INT_MAX;
int A[MAX][MAX];
rotate B[6];
bool selected[6];
vector<rotate> v;

void rotate_calculate(rotate k, int B[MAX][MAX])
{
    int r = k.r;
    int c = k.c;
    int s = k.s;

    while ((r-s != r+s) && (c-s != c+s))
    {
        int temp = B[r-s][c-s];

        for (int i = r-s; i < r+s; i++)
            B[i][c-s] = B[i+1][c-s];
        
        for (int i = c-s; i < c+s; i++)
            B[r+s][i] = B[r+s][i+1];
        
        for (int i = r+s; i > r-s; i--)
            B[i][c+s] = B[i-1][c+s];
        
        for (int i = c+s; i > c-s; i--)
            B[r-s][i] = B[r-s][i-1];
        
        B[r-s][c-s+1] = temp;
        s -= 1;
    }
}

void permutations(int depth)
{
    if (depth == K)
    {
        int B[MAX][MAX];
        copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

        vector<rotate>::iterator iter;
        for (iter = v.begin(); iter != v.end(); iter++)
            rotate_calculate((*iter), B);
        
        int sum_min = INT_MAX;

        for (int i = 1; i <= N; i++)
        {
            int sum = 0;

            for (int j = 1; j <= M; j++)
                sum += B[i][j];
            
            sum_min = min(sum_min, sum);
        }

        answer = min(answer, sum_min);

        return;
    }

    for (int i = 0; i < K; i++)
        if (selected[i] == false)
        {
            selected[i] = true;
            v.push_back(B[i]);
            permutations(depth + 1);
            selected[i] = false;
            v.pop_back();
        }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];
    
    for (int k = 0; k < K; k++)
    {
        int r, c, s;
        cin >> r >> c >> s;

        rotate t = { r, c, s };
        B[k] = t;
    }

    permutations(0);

    cout << answer << "\n";

    return 0;
}
