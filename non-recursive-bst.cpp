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
    bool insert(int data)
    {
        Node* new_node{new Node(data)};

        if(root == nullptr)
        {
            root = new_node;
            size++;
            return true;
        }

        Node* tempnode{root};
        while(true)
        {
            if(data < tempnode->data)
            {

                if(tempnode->left == nullptr)
                {
                    tempnode->left = new_node;
                    new_node->parent = tempnode;
                    size++;
                    return true;
                }

                tempnode = tempnode->left;
            }

            if(data > tempnode->data)
            {
                if(tempnode->right == nullptr)
                {
                    tempnode->right = new_node;
                    new_node->parent = tempnode;
                    size++;
                    return true;
                }

                tempnode = tempnode->right;
            }

            if(data == tempnode->data)
            {
                return false;
            }
        }
    }

};


int main()
{



    return 0;
}
