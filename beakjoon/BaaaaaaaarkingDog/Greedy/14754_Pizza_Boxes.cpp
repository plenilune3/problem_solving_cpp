#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;

int N, M;
int A[MAX][MAX], B[MAX][MAX];

long long remove_boxes(int A[MAX][MAX], int B[MAX][MAX]);
void front_view(int A[MAX][MAX], int B[MAX][MAX]);
void side_view(int A[MAX][MAX], int B[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
            B[i][j] = 0;
        }
    
    long long answer = remove_boxes(A, B);

    cout << answer << "\n";

    return 0;
}

long long remove_boxes(int A[MAX][MAX], int B[MAX][MAX])
{
    long long sum_boxes = 0;
    long long result = 0;

    front_view(A, B);
    side_view(A, B);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            sum_boxes += A[i][j];
            result += B[i][j];
        }

    return sum_boxes - result;
}

void front_view(int A[MAX][MAX], int B[MAX][MAX])
{
    for (int j = 0; j < M; j++)
    {
        int max_box = 0;

        for (int i = 0; i < N; i++)
            max_box = max(max_box, A[i][j]);
        
        for (int i = 0; i < N; i++)
            if (A[i][j] == max_box)
                B[i][j] = max_box;
    }
}

void side_view(int A[MAX][MAX], int B[MAX][MAX])
{
    for (int i = 0; i < N; i++)
    {
        int max_box = 0;

        for (int j = 0; j < M; j++)
            max_box = max(max_box, A[i][j]);
        
        for (int j = 0; j < M; j++)
            if (A[i][j] == max_box)
                B[i][j] = max_box;
    }
}