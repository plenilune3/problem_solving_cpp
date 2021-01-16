#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

const int MAX = 1e5 + 1;

struct hayble
{
    int F, S;
};

int N; long long M;
hayble haybles[MAX];
vector<int> tree;

int calculate_spiciness(long long M);
int init_(int node, int start, int end);
int max_(int node, int start, int end, int left, int right);

int main(int argc, char const *argv[])
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> haybles[i].F >> haybles[i].S;
    
    int answer = calculate_spiciness(M);
    cout << answer << "\n";

    return 0;
}

int calculate_spiciness(long long M)
{
    int h = (int) ceil(log2(N));
    int tree_size = (1 << (h + 1));
    tree = vector<int> (tree_size);

    init_(1, 0, N - 1);

    int left = 0, right = 0;
    int min_spiciness = INT_MAX;
    long long sum = 0;

    while (true)
    {
        if (sum >= M)
            sum -= (long long) haybles[left++].F;
        else if (right == N)
            break;
        else
            sum += (long long) haybles[right++].F;

        if (sum >= M)
            min_spiciness = min(min_spiciness, max_(1, 0, N - 1, left, right - 1));
    }

    return min_spiciness;
}

int init_(int node, int start, int end)
{
    if (start == end)
        return tree[node] = haybles[start].S;
    else
        return tree[node] = max(init_(node * 2, start, (start + end) / 2), init_(node * 2 + 1, (start + end) / 2 + 1, end));
}

int max_(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return INT_MIN;
    
    if (left <= start && right >= end)
        return tree[node];
    
    return max(max_(node * 2, start, (start + end) / 2, left , right), max_(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
