#include <iostream>

using namespace std;

const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

class node
{
private:
    node* child[26];
    bool finished;
    bool hit;
public:
    node();
    ~node();
    void insert(const char* word);
    void find(int x, int y, string word);
    void clear();
    void set_hit();
    int char_to_index(const char a);
    bool is_finished();
    bool is_hit();
};

string answer;
int N, max_score, counter_word;
char board[4][4];
bool visited[4][4];

int calculate_score(int l);
bool compare(const string &a, const string &b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    node *R = new node();

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char word[10]; cin >> word;
        R->insert(word);
    }

    int T; cin >> T;

    while (T--)
    {
        R->clear();
        answer.clear();
        max_score = 0, counter_word = 0;

        for (int i = 0; i < 4; i++)
            cin >> board[i];
        
        for (int x = 0; x < 4; x++)
            for (int y = 0; y < 4; y++)
                R->find(x, y, "");
        
        cout << max_score << " " << answer << " " << counter_word << "\n";
    }

    delete R;

    return 0;
}

void node::find(int x, int y, string word)
{
    if (word.size() >= 8) return;

    int next = char_to_index(board[x][y]);

    if (child[next] == NULL) return;

    visited[x][y] = true;
    word.push_back(board[x][y]);

    if (child[next]->is_finished() && !child[next]->is_hit()) 
    {
        child[next]->set_hit();
        max_score += calculate_score(word.size());
        counter_word += 1;

        if (compare(answer, word)) answer = word;
    }

    for (int d = 0; d < 8; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;

        if (visited[nx][ny]) continue;

        child[next]->find(nx, ny, word);
    }

    visited[x][y] = false;
}

void node::insert(const char* word)
{
    if (*word == '\0')
    {
        finished = true;
        return;
    }

    int next = char_to_index(*word);

    if (child[next] == NULL) child[next] = new node();

    child[next]->insert(word + 1);
}

void node::clear()
{
    hit = false;
    for (int i = 0; i < 26; i++)
        if (child[i] != NULL)
            child[i]->clear();
}

void node::set_hit()
{
    hit = true;
}

int calculate_score(int l)
{
    if (l <= 2) return 0;
    else if (l == 3 || l == 4) return 1;
    else if (l == 5) return 2;
    else if (l == 6) return 3;
    else if (l == 7) return 5;
    else return 11;
}

bool compare(const string &a, const string &b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    else
        return a.compare(b) > 0 ? true : false;
}

bool node::is_finished()
{
    return finished;
}

bool node::is_hit()
{
    return hit;
}

int node::char_to_index(const char a)
{
    return a - 'A';
}

node::node()
{
    finished = false, hit = false;
    for (int i = 0; i < 26; i++)
        child[i] = NULL;
}

node::~node()
{
    for (int i = 0; i < 26; i++)
        if (child[i] != NULL)
            delete child[i];
}
