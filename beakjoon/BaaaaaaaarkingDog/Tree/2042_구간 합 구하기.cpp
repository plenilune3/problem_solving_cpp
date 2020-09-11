#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e6;

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
            return tree[node] = init(A, node * 2, start, (start + end) / 2) + init(A, node * 2 + 1, (start + end) / 2 + 1, end);
    }

    void update(int node, int start, int end, int index, long long diff)
    {
        if (index < start || index > end)
            return;

        tree[node] = tree[node] + diff;

        if (start != end)
        {
            update(node * 2, start, (start + end) / 2, index, diff);
            update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
        }
    }

    long long sum(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        
        return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
};

int N, M, K;
int A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    SegmentTree segmentTree(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    segmentTree.init(A, 1, 0, N - 1);

    M += K;

    while (M--)
    {
        int a, b; long long c; cin >> a >> b >> c;

        if (a == 1)
        {
            b -= 1;
            long long diff = c - A[b];
            A[b] = c;
            segmentTree.update(1, 0, N - 1, b, diff);
        }
        else if (a == 2)
        {
            cout << segmentTree.sum(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
    
    return 0;
}


