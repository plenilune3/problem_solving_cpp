#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

struct line
{
    int left, right, height;

    line(int _left, int _right, int _height) : left(_left), right(_right), height(_height) {}

    bool operator<(const line l) const
    {
        if (left != l.left)
            return left < l.left;
        else if (right != l.right)
            return right < l.right;
        else
            return height < l.height;
    }
};

int N;
vector<line> lines;

void print_skyline(int N, vector<line> &lines);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int L, H, R;
        cin >> L >> H >> R;
        lines.push_back(line(L, R, H));
    }

    sort(lines.begin(), lines.end());

    print_skyline(N, lines);

    return 0;
}

void print_skyline(int N, vector<line> &lines)
{
    int left = 0, right = 0, height = 0;

    for (int i = 0; i < N; i++)
    {
        int l = lines[i].left, r = lines[i].right, h = lines[i].height;
    }
}