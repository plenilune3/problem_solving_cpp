#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct students
{
    int x, p;

    students() : x(0), p(0) {}
    students(int _x, int _p) : x(_x), p(_p) {}

    bool operator< (const students s) const
    {
        return x > s.x;
    }
};

int N, K, S;

int calculate_distance(vector<students> &v);
bool compare_greater(students a, students b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<students> left, right;

    cin >> N >> K >> S;

    for (int i = 0; i < N; i++)
    {
        int x, p; cin >> x >> p;
        x = x - S;

        if (x < 0)
            left.push_back(students(-x, p));
        else if (x > 0)
            right.push_back(students(x, p));
    }

    int answer = 0;
    answer += calculate_distance(left);
    answer += calculate_distance(right);
    cout << answer << "\n";

    return 0;
}

int calculate_distance(vector<students> &v)
{
    int result = 0, prev_distance = 0, prev_count = 0;

    sort(v.begin(), v.end());

    for (vector<students>::iterator i = v.begin(); i != v.end(); i++)
    {
        int temp = prev_count + (*i).p;

        if (prev_count == 0)
            prev_distance = (*i).x;

        if (temp >= K)
        {
            result += prev_distance * 2;
            temp -= K;
            prev_distance = (*i).x;
            result += (temp / K) * prev_distance * 2;
            prev_count = temp % K;
        }
        else
            prev_count = temp;
    }

    if (prev_count)
        result += prev_distance * 2;

    return result;
}