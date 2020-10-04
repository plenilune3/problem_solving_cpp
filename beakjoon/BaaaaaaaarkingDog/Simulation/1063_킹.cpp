#include <iostream>

using namespace std;

const int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
const int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int N;
pair<int, int> king, stone;

void set_piece(string king_coordinate, string stone_coordinate);
int get_dir(string move);
bool is_out_of_range(int x, int y);
pair<int, int> get_coordinate(string coordinate);
pair<char, char> get_coordinate(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string king_coordinate, stone_coordinate;
    cin >> king_coordinate >> stone_coordinate >> N;

    king = get_coordinate(king_coordinate);
    stone = get_coordinate(stone_coordinate);

    while (N--)
    {
        string move;

        cin >> move;

        int dir = get_dir(move);

        pair<int ,int> nstone = stone;
        pair<int, int> nking = make_pair(king.first + dx[dir], king.second + dy[dir]);

        if (is_out_of_range(nking.first, nking.second))
            continue;
        
        if (nking == stone)
        {
            nstone = make_pair(stone.first + dx[dir], stone.second + dy[dir]);

            if (is_out_of_range(nstone.first, nstone.second))
                continue;
        }

        king = nking, stone = nstone;
    }

    pair<char, char> king_last = get_coordinate(king.first, king.second);
    pair<char, char> stone_last = get_coordinate(stone.first, stone.second);

    cout << king_last.first << king_last.second << "\n";
    cout << stone_last.first << stone_last.second << "\n";

    return 0;
}

pair<char, char> get_coordinate(int x, int y)
{
    pair<char, char> c = make_pair('A' + y ,(8 - x) + '0');
    return c;
}

pair<int, int> get_coordinate(string coordinate)
{
    pair<int, int> c = make_pair(7 - (coordinate[1] - '1'), coordinate[0] - 'A');
    return c;
}

int get_dir(string move)
{
    if (move == "R") return 0;
    else if (move == "L") return 1;
    else if (move == "B") return 2;
    else if (move == "T") return 3;
    else if (move == "RT") return 4;
    else if (move == "LT") return 5;
    else if (move == "RB") return 6;
    else return 7;
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= 8 || y < 0 || y >= 8;
}
