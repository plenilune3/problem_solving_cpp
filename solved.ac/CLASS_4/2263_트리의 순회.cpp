#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

int N, position[MAX];
int in_order[MAX], post_order[MAX];
vector<int> pre_order;

void get_pre_order(int is, int ie, int ps, int pe);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> in_order[i];
    
    for (int i = 0; i < N; i++)
        cin >> post_order[i];
    
    for (int i = 0; i < N; i++)
        position[in_order[i]] = i;
    
    get_pre_order(0, N - 1, 0, N - 1);

    for (vector<int>::iterator i = pre_order.begin(); i != pre_order.end(); i++)
        cout << (*i) << " ";
    cout << "\n";
    
    return 0;
}

void get_pre_order(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe) return;

    int root_index = position[post_order[pe]];
    int left_size = root_index - is;

    pre_order.push_back(post_order[pe]);
    get_pre_order(is, root_index - 1, ps, ps + left_size - 1);
    get_pre_order(root_index + 1, ie, ps + left_size, pe - 1);
}
