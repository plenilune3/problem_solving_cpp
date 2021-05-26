#include <iostream>

using namespace std;

const int MAX = 27;

string P, I;
int N, idx[MAX];

void get_postorder(int is, int ie, int ps, int pe);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> P >> I)
    {
        N = (int) I.size();

        for (int i = 0; i < N; i++)
            idx[I[i] - 'A'] = i;

        get_postorder(0, N - 1, 0, N - 1);
        cout << "\n";
    }

    return 0;
}

void get_postorder(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe)
        return;

    int root_idx = idx[P[ps] - 'A'];
    int left_size = root_idx - is;

    get_postorder(is, root_idx - 1, ps + 1, ps + left_size);
    get_postorder(root_idx + 1, ie, ps + left_size + 1, pe);
    cout << I[root_idx];
}
