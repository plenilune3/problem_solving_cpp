#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int MAX = 100000;

int N;
int solution[MAX];
int answer[2];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int s;
        cin >> s;

        solution[i] = s;
    }

    sort(solution, solution + N);

    int left = 0, right = N - 1;
    int min_attribute = INT_MAX;

    while (left < right)
    {
        int attribute = solution[left] + solution[right];

        if (abs(attribute) < min_attribute)
        {
            min_attribute = abs(attribute);
            answer[0] = left, answer[1] = right;
        }

        if (attribute < 0)
            left++;
        else
            right--;
    }

    cout << solution[answer[0]] << " " << solution[answer[1]] << "\n";

    return 0;
}
