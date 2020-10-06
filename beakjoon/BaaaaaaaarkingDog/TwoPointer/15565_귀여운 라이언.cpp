#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, K;
int doll[MAX];

int get_length();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> doll[i];
    
    int answer = get_length();

    if (answer != MAX)
        cout << get_length() << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

int get_length()
{
    int left = 0, right = 0;
    int cnt = 0, min_length = MAX;

    while (true)
    {
        if (cnt == K)
        {
            if (doll[left++] == 1)
                cnt -= 1;
        }
        else if (right == N)
            break;
        else
        {
            if (doll[right++] == 1)
                cnt += 1;
        }

        if (cnt == K)
            min_length = min(min_length, right - left);
    }

    return min_length;
}
