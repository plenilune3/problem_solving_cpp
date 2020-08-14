#include <iostream>
#include <cmath>

using namespace std;

int N;

void backtracking(int depth, int result);
bool is_prime(int num);

int main(int argc, char const *argv[])
{
    cin >> N;

    backtracking(1, 2);
    backtracking(1, 3);
    backtracking(1, 5);
    backtracking(1, 7);

    return 0;
}

bool is_prime(int num)
{
    if (num == 1)
        return false;

    for (int i = 2; i < sqrt(num) + 1; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void backtracking(int depth, int result)
{
    if (depth == N)
    {
        cout << result << "\n";
        return;
    }

    for (int i = 1; i <= 9; i += 2)
    {
        int next_result = result * 10 + i;

        if (is_prime(next_result))
            backtracking(depth + 1, next_result);
    }
}

