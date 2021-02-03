#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

class node
{
private:
    node* child[26];
    int finished;
    int count;
public:
    node();
    ~node();
    int char_to_index(char a);
    int get_prefix(const char* word, int d);
    void insert(const char* word);
    int find(const char* word);
};

int N;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    node *T = new node();

    while (N--)
    {
        char user[12]; cin >> user;

        T->insert(user);

        if (T->find(user) == 1)
        {
            int p = T->get_prefix(user, 0);
            
            for (int i = 0; i < p; i++)
                cout << user[i];
            cout << "\n";
        }
        else
            cout << user << T->find(user) << "\n";
    }

    delete T;

    return 0;
}

int node::get_prefix(const char* word, int d)
{
    if (*word == '\0') return d;

    if (d > 0 && count == 1) return d;

    int next = char_to_index(*word);
    
    return child[next]->get_prefix(word + 1, d + 1);
}

void node::insert(const char* word)
{
    count += 1;

    if (*word == '\0')
    {
        finished += 1;
        return;
    }

    int next = char_to_index(*word);

    if (child[next] == NULL)
        child[next] = new node();
    
    child[next]->insert(word + 1);
}

int node::find(const char* word)
{
    if (*word == '\0') return finished;

    int next = char_to_index(*word);

    if (child[next] == NULL) return 0;

    return child[next]->find(word + 1);
}

int node::char_to_index(char a)
{
    return a - 'a';
}

node::node()
{
    finished = false, count = 0;
    for (int i = 0; i < 26; i++)
        child[i] = NULL;
}

node::~node()
{
    for (int i = 0; i < 26; i++)
        if (child[i] != NULL)
            delete child[i];
}

