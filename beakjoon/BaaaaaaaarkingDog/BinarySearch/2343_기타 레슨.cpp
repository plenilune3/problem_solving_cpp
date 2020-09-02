#include <iostream>

using namespace std;

const int MAX = 1e5;

int N, M;
int lesson[MAX];

bool is_possible(int length);
int find_min_length(int sum);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> lesson[i];
        sum += lesson[i];
    }

    int answer = find_min_length(sum);

    cout << answer << "\n";
    
    return 0;
}

bool is_possible(int length)
{
    int sum = 0;
    int count = 1;

    for (int i = 0; i < N; i++)
    {
        if (lesson[i] > length)
            return false;
        
        sum += lesson[i];

        if (sum > length)
        {
            sum = lesson[i];
            count += 1;
        }

    }

    return count <= M;
}

int find_min_length(int sum)
{
    int left = 0, right = sum;
    int min_length = sum + 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (is_possible(mid))
        {
            min_length = min(min_length, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return min_length;
}


