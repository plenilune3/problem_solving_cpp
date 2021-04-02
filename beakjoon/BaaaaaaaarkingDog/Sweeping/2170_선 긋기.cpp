#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

struct line
{
    int left, right;

    line(int _left, int _right) : left(_left), right(_right) {}

    bool operator<(const line l) const
    {
        if (left != l.left)
            return left < l.left;
        else
            return right < l.right;
    }
};

int N;
vector<line> lines;

int calculate_line_length(vector<line> &lines);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int left, right;
        cin >> left >> right;
        lines.push_back(line(left, right));
    }

    sort(lines.begin(), lines.end());

    answer = calculate_line_length(lines);

    cout << answer << "\n";

    return 0;
}

int calculate_line_length(vector<line> &lines)
{
    int result = 0;
    int left = -1e9, right = -1e9;

    for (vector<line>::iterator i = lines.begin(); i != lines.end(); i++)
    {
        if ((*i).left < right)
            right = max(right, (*i).right);
        else
        {
            result += right - left;
            left = (*i).left;
            right = (*i).right;
        }
    }
    result += right - left;

    return result;
}