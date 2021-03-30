#include <iostream>

using namespace std;

const int MAX = 5e5 + 1;

int N, R, B;
char A[MAX];

int count_move(char A[MAX], char color);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        if (A[i] == 'R') R += 1;
        else B += 1;
    }

    int answer = min(count_move(A, 'R'), count_move(A, 'B'));

    cout << answer << "\n";

    return 0;
}

int count_move(char A[MAX], char color)
{
    int left = 0, right = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] != color)
            break;
        left += 1;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] != color)
            break;
        right += 1;
    }

    return color == 'R' ? R - max(left, right) : B - max(left, right);
}