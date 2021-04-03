#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 3e5 + 1;

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

int N, M;
vector<line> lines;

long long calculate_distance(vector<line> &lines);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long answer = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int left, right;
        cin >> left >> right;

        if (left <= right)
            continue;

        lines.push_back(line(right, left));
    }

    sort(lines.begin(), lines.end());

    answer = calculate_distance(lines);

    cout << answer << "\n";

    return 0;
}

long long calculate_distance(vector<line> &lines)
{
    long long result = M;
    int left = 0, right = 0;

    for (vector<line>::iterator i = lines.begin(); i != lines.end(); i++)
    {
        if ((*i).left < right)
            right = max(right, (*i).right);
        else
        {
            result += 2 * (right - left);
            left = (*i).left;
            right = (*i).right;
        }
    }
    result += 2 * (right - left);

    return result;
}