#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 51;

struct rotation
{
    int r, c, s;

    rotation() : r(0), c(0), s(0) {};
    rotation(int _r, int _c, int _s) : r(_r), c(_c), s(_s) {};
};

int N, M, K, A[MAX][MAX], answer = INT_MAX;
rotation r[6];
bool visited[6];
vector<rotation> v;

void permutations(int depth);
void rotate(int A[MAX][MAX], rotation B);
int calculate(int A[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < K; i++)
    {
        cin >> r[i].r  >> r[i].c >> r[i].s;
        r[i].r -= 1, r[i].c -= 1;
    }

    permutations(0);

    cout << answer << "\n";

    return 0;
}

void rotate(int A[MAX][MAX], rotation B)
{
    int r = B.r, c = B.c, s = B.s;

    while (s)
    {
        int temp = A[r - s][c - s];

        for (int i = r - s; i < r + s; i++)
            A[i][c - s] = A[i + 1][c - s];
        for (int i = c - s; i < c + s; i++)
            A[r + s][i] = A[r + s][i + 1];
        for (int i = r + s; i > r - s; i--)
            A[i][c + s] = A[i - 1][c + s];
        for (int i = c + s; i > c - s; i--)
            A[r - s][i] = A[r - s][i - 1];
        
        A[r - s][c - s + 1] = temp;
        s -= 1;
    }
}

void permutations(int depth)
{
    if (depth == K)
    {
        int B[MAX][MAX];
        copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

        for (vector<rotation>::iterator i = v.begin(); i != v.end(); i++)
            rotate(B, (*i));

        answer = min(answer, calculate(B));

        return;
    }

    for (int i = 0; i < K; i++)
    {
        if (visited[i])
            continue;
        
        visited[i] = true;
        v.push_back(r[i]);
        permutations(depth + 1);
        visited[i] = false;
        v.pop_back();
    }
}

int calculate(int A[MAX][MAX])
{
    int result = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        int temp = 0;

        for (int j = 0; j < M; j++)
            temp += A[i][j];
        
        result = min(result, temp);
    }

    return result;
}
