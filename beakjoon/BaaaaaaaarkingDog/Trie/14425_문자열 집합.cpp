#include <iostream>

using namespace std;

const int MAX = 1e4 + 1;

class Trie
{
private:
    Trie* child[26];
    bool finished;
public:
    Trie();
    ~Trie();
    int char_to_index(char a);
    void insert(const char* word);
    bool find(const char* word);
};

int N, M;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Trie *T = new Trie();

    while (N--)
    {
        char a[505]; cin >> a;
        T->insert(a);
    }

    int answer = 0;

    while (M--)
    {
        char a[505]; cin >> a;

        answer += T->find(a) ? 1 : 0;
    }

    cout << answer << "\n";

    delete T;

    return 0;
}

bool Trie::find(const char* word)
{
    int next = char_to_index(*word);

    if (*word == '\0') return finished;

    if (child[next] == NULL) return false;

    return child[next]->find(word + 1);
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
        child[next] = new Trie();
    
    child[next]->insert(word + 1);
}

int Trie::char_to_index(char a)
{
    return a - 'a';
}

Trie::Trie()
{
    for (int i = 0; i < 26; i++)
        child[i] = NULL;
    finished = false;
}

Trie::~Trie()
{
    for (int i = 0; i < 26; i++)
        if (child[i] != NULL)
            delete child[i];
}
