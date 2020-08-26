#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4000;

int N;
long long answer;
int A[MAX], B[MAX], C[MAX], D[MAX];
long long AB[MAX * MAX], CD[MAX * MAX];

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        A[i] = a, B[i] = b, C[i] = c, D[i] = d;
    }

    int index = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            AB[index] = (A[i] + B[j]), CD[index] = (C[i] + D[j]);
            index++;
        }
    
    sort(AB, AB + N * N);
    sort(CD, CD + N * N);

    int length = N * N, left = 0, right = length - 1;

    while (true)
    {
        long long left_value = AB[left], right_value = CD[right];

        if (left == length || right < 0)
            break;
        
        if (AB[left] + CD[right] == 0)
        {
            long long left_cnt = 0, right_cnt = 0;

            while (left < length && AB[left] == left_value)
                left_cnt += 1, left++;

            while (right >= 0 && CD[right] == right_value)
                right_cnt += 1, right--;

            answer += left_cnt * right_cnt;
        }

        else if (AB[left] + CD[right] < 0) left++;

        else right--;
    }

    cout << answer << "\n";

    return 0;
}
