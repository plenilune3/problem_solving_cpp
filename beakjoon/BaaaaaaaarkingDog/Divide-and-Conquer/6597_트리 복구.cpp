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

    cin >> P >> I;

    N = (int) I.size();

    for (int i = 0; i < N; i++)
        idx[I[i] - 'A'] = i;

    cout << N << "\n";

    for (int i = 0; i < N; i++)
        cout << idx[i] << " ";
    cout << "\n";

    // get_postorder(0, N - 1, 0, N - 1);

    // while (cin >> P >> I)
    // {
    //     cout << P << "\n";
    //     cout << I << "\n";

    //     N = (int) I.size();

    //     for (int i = 0; i < N; i++)
    //         idx[I[i] - 'A'] = i;

    //     get_postorder(0, N - 1, 0, N - 1);
    // }

    return 0;
}

void get_postorder(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe)
        return;

    int root_idx = idx[P[ps] - 'A'];
    int left_size = root_idx - is;

    cout << is << " " << ie << " " << ps << " " << pe << "\n";

    get_postorder(is, root_idx - 1, ps, ps + left_size - 1);
    get_postorder(root_idx + 1, ie, ps + left_size, pe - 1);
    cout << I[root_idx] << " ";
}
