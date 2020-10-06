#include <iostream>

using namespace std;

const int MAX = 3e5 + 1;

int N, B, W, M;
string shingles;

int get_length();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> B >> W;
    cin >> shingles;

    M = (int) shingles.size();

    int answer = get_length();

    cout << answer << "\n";

    return 0;
}

int get_length()
{
    int left = 0, right = 0, length = 0;
    int black = 0, white = 0;
    int max_length = 0;

    while (true)
    {
        if (black > B)
        {
            if (shingles[left++] == 'B') black -= 1;
            else white -= 1;
            
            length -= 1;
        }
        else if (right == M)
            break;
        else
        {
            if (shingles[right++] == 'B') black += 1;
            else white += 1;

            length += 1;
        }

        if (black <= B && white >= W)
            max_length = max(max_length, length);
    }

    return max_length;
}
