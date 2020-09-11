#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

const int MAX = 1e5;

class SegmentTree
{
private:
    vector<int> tree;

public:
    SegmentTree(int N)
    {
        int h = (int) ceil(log2(N));
        int tree_size = (1 << (h + 1));
        this->tree = vector<int> (tree_size);
    }

    int init_min(int A[], int node, int start, int end)
    {
        if (start == end)
            return tree[node] = A[start];
        else
            return tree[node] = min(init_min(A, node * 2, start, (start + end) / 2), init_min(A, node * 2 + 1, (start + end) / 2 + 1, end));
    }

    int init_max(int A[], int node, int start, int end)
    {
        if (start == end)
            return tree[node] = A[start];
        else
            return tree[node] = max(init_max(A, node * 2, start, (start + end) / 2), init_max(A, node * 2 + 1, (start + end) / 2 + 1, end));
    }

    int get_min(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start)
            return INT_MAX;
        if (left <= start && end <= right)
            return tree[node];
        
        return min(get_min(node * 2, start, (start + end) / 2, left, right), get_min(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
    }

    int get_max(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start)
            return INT_MIN;
        if (left <= start && end <= right)
            return tree[node];
        
        return max(get_max(node * 2, start, (start + end) / 2, left, right), get_max(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
    }
};

int N, M;
int A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    SegmentTree min_tree(N);
    SegmentTree max_tree(N);
    min_tree.init_min(A, 1, 0, N - 1);
    max_tree.init_max(A, 1, 0, N - 1);

    while (M--)
    {
        int a, b; cin >> a >> b;
        a -= 1, b -= 1;

        cout << min_tree.get_min(1, 0, N - 1, a, b) << " " << max_tree.get_max(1, 0, N - 1, a, b) << "\n";
    }

    return 0;
}

