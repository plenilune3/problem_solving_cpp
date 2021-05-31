#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;

class node
{
private:
    node* child[96];
    bool finished, deleted;
    int count;
public:
    node();
    ~node();
    void insert(const char* word, bool d);
    int char_to_index(const char a);
    int count_delete();
};

int N, M;
char files_A[MAX][25], files_B[MAX][25];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        node *T = new node();
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> files_A[i];
            T->insert(files_A[i], true);
        }
        
        cin >> M;

        for (int i = 0; i < M; i++)
        {
            cin >> files_B[i];
            T->insert(files_B[i], false);
        }

        int answer = T->count_delete();
        cout << answer << "\n";

        delete T;
    }

    return 0;
}

int node::count_delete()
{
    if (deleted)
        return 1;
    
    int ret = 0;

    if (finished)
        ret += 1;

    for (int i = 0; i < 96; i++)
        if (child[i] != NULL)
            ret += child[i]->count_delete();
    
    return ret;
}

void node::insert(const char* word, bool d)
{
    deleted = d;
    count += 1;

    if (*word == '\0')
    {
        finished = d;
        return;
    }

    int next = char_to_index(*word);

    if (child[next] == NULL) child[next] = new node();

    child[next]->insert(word + 1, d);
}

int node::char_to_index(const char a)
{
    return a - 32;
}

node::node()
{
    finished = false, deleted = false, count = 0;
    for (int i = 0; i < 96; i++)
        child[i] = NULL;
}

node::~node()
{
    for (int i = 0; i < 96; i++)
        if (child[i] != NULL)
            delete child[i];
}