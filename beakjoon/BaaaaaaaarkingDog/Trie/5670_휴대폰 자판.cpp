#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e5 + 1;

class Trie
{
private:
    Trie* child[26];
    bool finished;
    int branch;
public:
    Trie();
    ~Trie();
    void insert(const char* word);
    int count(const char* word, int i);
    int char_to_index(const char a);
};

int N;
char word[MAX][85];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout << fixed;
    cout.precision(2);

    while (cin >> N)
    {
        Trie *T = new Trie();

        for (int i = 0; i < N; i++)
        {
            cin >> word[i];
            T->insert(word[i]);
        }

        double sum_count = 0;

        for (int i = 0; i < N; i++)
            sum_count += T->count(word[i], 0);
        
        cout << sum_count / N << "\n";

        delete T;
    }

    return 0;
}

int Trie::count(const char* word, int i)
{
    int next = char_to_index(*word);

    if (*word == '\0') return 0;

    if (child[next] == NULL) return 0;

    int c = child[next]->count(word + 1, i + 1);

    return i == 0 || branch > 1 || finished ? c + 1 : c;
}

void Trie::insert(const char* word)
{
    if (*word == '\0')
    {
        finished = true;
        return;
    }

    int next = char_to_index(*word);

    if (child[next] == NULL)
    {
        child[next] = new Trie();
        branch += 1;
    }

    child[next]->insert(word + 1);
}

int Trie::char_to_index(const char a)
{
    return a - 'a';
}

Trie::Trie()
{
    for (int i = 0; i < 26; i++)
        child[i] = NULL;
    finished = false, branch = 0;
}

Trie::~Trie()
{
    for (int i = 0; i < 26; i++)
        if (child[i] != NULL)
            delete child[i];
}
