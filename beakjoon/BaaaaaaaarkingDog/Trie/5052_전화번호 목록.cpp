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

int N;
char numbers[MAX][15];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        Trie *T = new Trie();
        bool possible = true;
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> numbers[i];
            T->insert(numbers[i]);
        }

        for (int i = 0; i < N; i++)
        {
            if (T->find(numbers[i]))
            {
                possible = false;
                break;
            }
        }

        if (possible)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
        
        delete T;
    }

    return 0;
}

bool Trie::find(const char* word)
{
    int next = char_to_index(*word);

    if (*word == '\0') return false;

    if (child[next] == NULL)  return false;

    if (finished) return true;

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
    return a - '0';
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
