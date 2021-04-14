#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e5 + 1;

struct line
{
    int left, right;

    line(int _left, int _right) : left(_left), right(_right) {}

    bool operator<(const line l) const
    {
        if (right != l.right)
            return right < l.right;
        else
            return left < l.left;
    }
};

int N, D;
vector<line> lines;

int calculate_people(int length, vector<line> &lines);

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
        lines.push_back(line(min(left, right), max(left, right)));
    }
    cin >> D;

    sort(lines.begin(), lines.end());

    answer = calculate_people(D, lines);

    cout << answer << "\n";

    return 0;
}

int calculate_people(int length, vector<line> &lines)
{
    int result = 0;
    priority_queue< int, vector<int>, greater<int> > pq;

    for (vector<line>::iterator i = lines.begin(); i != lines.end(); i++)
    {
        if (((*i).right - (*i).left) > length)
            continue;

        pq.push((*i).left);

        while (!pq.empty() && (*i).right - pq.top() > length)
            pq.pop();
        
        result = max(result, (int)pq.size());
    }

    return result;
}