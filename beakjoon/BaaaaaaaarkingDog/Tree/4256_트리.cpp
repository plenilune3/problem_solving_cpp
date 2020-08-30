#include <iostream>

using namespace std;

class node
{
public:
    char data;
    node *left, *right;

    node(char _data)
    {
        (*this).data = _data;
        (*this).left = NULL;
        (*this).right = NULL;
    }
};

class tree
{
private:
    void _insert(node *root, char data, char left_data, char right_data)
    {
        if (root == NULL)
            return;
        
        else if ((*root).data == data)
        {
            if (left_data != '.') (*root).left = new node(left_data);
            if (right_data != '.') (*root).right = new node(right_data);
        }

        else
        {
            _insert((*root).left, data, left_data, right_data);
            _insert((*root).right, data, left_data, right_data);
        }
    }

public:
    node *root = NULL;

    void insert(char data, char left_data, char right_data)
    {
        if ((*this).root == NULL)
        {
            if (data != '.') (*this).root = new node(data);
            if (left_data != '.') (*(*this).root).left = new node(left_data);
            if (right_data != '.') (*(*this).root).right = new node(right_data);
        }
        else
            _insert((*this).root, data, left_data, right_data);
    }

    void preorder(node *root)
    {
        cout << (*root).data;
        if ((*root).left != NULL) preorder((*root).left);
        if ((*root).right != NULL) preorder((*root).right);
    }

    void inorder(node *root)
    {
        if ((*root).left != NULL) inorder((*root).left);
        cout << (*root).data;
        if ((*root).right != NULL) inorder((*root).right);
    }

    void postorder(node *root)
    {
        if ((*root).left != NULL) postorder((*root).left);
        if ((*root).right != NULL) postorder((*root).right);
        cout << (*root).data;
    }

};


int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    tree *T = new tree();

    for (int i = 0; i < N; i++)
    {
        char data, left_data, right_data;
        cin >> data >> left_data >> right_data;

        (*T).insert(data, left_data, right_data);
    }

    (*T).preorder((*T).root);
    cout << "\n";
    (*T).inorder((*T).root);
    cout << "\n";
    (*T).postorder((*T).root);
    cout << "\n";

    return 0;
}
