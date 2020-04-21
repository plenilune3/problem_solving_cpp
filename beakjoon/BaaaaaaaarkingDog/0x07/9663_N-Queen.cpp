#include <iostream>


using namespace std;
const int MAX = 15;
bool c[MAX];
bool ld[MAX + MAX - 1];
bool rd[MAX + MAX - 1];

int N;
int answer;

void backtracking(int i)
{
    if (i == N)
        answer++;
    else
    {
        for (int j = 0; j < N; j++)
        {
            if (c[j] || ld[i + j] || rd[i - j + N - 1])
                continue;
            
            c[j] = ld[i + j] = rd[i - j + N - 1] = true;
            backtracking(i + 1);
            c[j] = ld[i + j] = rd[i - j + N - 1] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> N;
    backtracking(0);
    cout << answer << "\n";

    return 0;
}



