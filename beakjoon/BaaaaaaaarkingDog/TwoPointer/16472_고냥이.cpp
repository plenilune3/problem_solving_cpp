#include <iostream>
#include <string>

using namespace std;

int N, M;
string str;

int get_length();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> str;

    M = (int) str.size();

    int answer = get_length();

    cout << answer << "\n";

    return 0;
}

int get_length()
{
    int alpha[26] = { 0 };
    int left = 0, right = 0, sort = 0, length = 0;
    int max_length = 0;

    while (true)
    {
        if (sort > N)
        {
            if (--alpha[str[left++] - 'a'] == 0)
                sort -= 1;
            length -= 1;
        }
        else if (right == M)
            break;
        else
        {
            if (++alpha[str[right++] - 'a'] == 1)
                sort += 1;
            length += 1;
        }

        if (sort <= N)
            max_length = max(max_length, length);
    }

    return max_length;
}

