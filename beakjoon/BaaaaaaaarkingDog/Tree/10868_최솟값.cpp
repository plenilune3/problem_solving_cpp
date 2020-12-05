#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree
{
private:
    vector<long long> tree;
public:
    SegmentTree(int N)
    {
        int h = (int) ceil(log2(N));
        int tree_size = (1 << (h + 1));
        (*this).tree = vector<long long> (tree_size);
    }

    long long init(int A[], int node, int start, int end)
    {
        if (start == end)
            return tree[node] = A[start];
        else
            return tree[node] = min(init(A, node * 2, start, (start + end) / 2), init(A, node * 2 + 1, (start + end) / 2 + 1, end));
    }

    long long min_(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start)
            return LONG_LONG_MAX;

        if (left <= start && end <= right)
            return tree[node];
        
        return min(min_(node * 2, start, (start + end) / 2, left, right), min_(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
    }
};

const int MAX = 1e6 + 1;

int N, M;
int A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    SegmentTree *S = new SegmentTree(N);

    S->init(A, 1, 0, N - 1);

    while (M--)
    {
        int left, right;
        cin >> left >> right;
        cout << S->min_(1, 0, N - 1, left - 1, right - 1) << "\n";
    }

    return 0;
}
