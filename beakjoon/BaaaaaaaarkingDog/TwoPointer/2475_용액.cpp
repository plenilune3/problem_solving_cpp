#include <iostream>
#include <climits>

using namespace std;

const int MAX = 100000;

int N, answer[2];
int solution[MAX];

int abs(int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> solution[i];
    
    int left = 0, right = N - 1;
    int min_attribute = INT_MAX;

    while (left < right)
    {
        int attribute = solution[left] + solution[right];

        if (abs(attribute) < min_attribute)
        {
            min_attribute = abs(attribute);
            answer[0] = solution[left], answer[1] = solution[right];
        }

        if (attribute < 0)
            left++;
        else
            right--;
    }

    cout << answer[0] << " " << answer[1] << "\n";

    return 0;
}

int abs(int x)
{
    return x >= 0 ? x : -x;
}

