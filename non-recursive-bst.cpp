#include <iostream>

class Node{

    friend class BST;
private:
    int data;
    Node* parent;
    Node* right;
    Node* left;
    Node(int data)
    {
        this->data = data;
        parent = nullptr;
        right = nullptr;
        left = nullptr;
    }
};

class BST{

private:
    Node* root;
    int size;

public:
    int get_size()
    {
        return size;
    }


};


int main()
{



    return 0;
}
