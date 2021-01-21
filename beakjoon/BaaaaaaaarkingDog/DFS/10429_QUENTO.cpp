#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 3;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct oper
{
    int p;
    char op;
};

int N, M;
bool is_finished;
char board[MAX][MAX];
bool visited[MAX][MAX];
vector<char> v;
vector< pair<int, int> > c;
vector< pair<int, int> > answer;

void combinations(int depth, int x, int y);
int calculator(vector<char> &v);
void calculate(stack<int> &operands, stack<oper> &operators);
int get_priority(char op);
oper make_oper(int p, char op);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < MAX; i++)
        cin >> board[i];

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (board[i][j] >= '0' && board[i][j] <= '9')
            {
                visited[i][j] = true;
                v.push_back(board[i][j]);
                c.push_back(make_pair(i, j));
                combinations(1, i, j);
                visited[i][j] = false;
                v.pop_back();
                c.pop_back();
            }

            if (is_finished)
                break;
        }

        if (is_finished)
            break;
    }

    cout << is_finished << "\n";

    if (is_finished)
        for (vector< pair<int, int> >::iterator i = answer.begin(); i != answer.end(); i++)
            cout << (*i).first << " " << (*i).second << "\n";

    return 0;
}

void combinations(int depth, int x, int y)
{
    if (is_finished)
        return;
    
    if (depth == M * 2 - 1)
    {
        if (calculator(v) == N)
        {
            is_finished = true;
            answer.assign(c.begin(), c.end());
        }

        return;
    }

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];
        
        if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
            continue;
        
        if (visited[nx][ny])
            continue;
        
        visited[nx][ny] = true;
        v.push_back(board[nx][ny]);
        c.push_back(make_pair(nx, ny));
        combinations(depth + 1, nx, ny);
        visited[nx][ny] = false;
        v.pop_back();
        c.pop_back();
    }
}

int calculator(vector<char> &v)
{
    stack<int> operands;
    stack<oper> operators;

    for (vector<char>::iterator i = v.begin(); i != v.end(); i++)
    {
        char c = (*i);

        if (c == '(')
            operators.push(make_oper(get_priority(c), c));
        else if (c == ')')
        {
            while (operators.top().op != '(')
                calculate(operands, operators);
            operators.pop();
        }
        else if (c == '*' || c == '/' || c == '+' || c == '-')
        {
            int p = get_priority(c);

            while (!operators.empty() && p <= operators.top().p)
                calculate(operands, operators);
            
            operators.push(make_oper(p, c));
        }
        else
            operands.push(c - '0');
    }

    while (!operators.empty())
        calculate(operands, operators);
    
    return operands.top();
}

void calculate(stack<int> &operands, stack<oper> &operators)
{
    int b = operands.top(); operands.pop();
    int a = operands.top(); operands.pop();
    char op = operators.top().op; operators.pop();

    int result = 0;

    if (op == '*') result = a * b;
    else if (op == '/') result = a / b;
    else if (op == '+') result = a + b;
    else result = a - b;

    operands.push(result);
}

int get_priority(char op)
{
    if (op == '(' || op == ')')
        return 0;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 1;
}

oper make_oper(int p, char op)
{
    oper o = { p, op };
    return o;
}

