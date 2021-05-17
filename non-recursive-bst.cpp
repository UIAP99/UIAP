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

    BST()
    {
        root = nullptr;
        size = 0;
    }
    ~BST()
    {
        while(root != nullptr)
            remove(root->data);
    }
    int get_size()
    {
        return size;
    }
    bool insert(int data)
    {
        Node* new_node = new Node(data);

        if(root == nullptr)
        {
            root = new_node;
            size++;
            return true;
        }

        Node* tempnode = root;
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
    Node* find(int data)
    {
        Node* tempnode = root;

        while(tempnode != nullptr)
        {
            int tempdata = tempnode->data;

            if(data == tempdata)
            {
                return tempnode;
            }

            if(data < tempdata)
            {
                tempnode = tempnode->left;
                continue;
            }

            if(data > tempdata)
            {
                tempnode = tempnode->right;
                continue;
            }

        }

        return nullptr;
    }
    void print()
    {
        Node* to_print = root;
        bool right_forib = false;
        bool self_forib = false;
        bool left_forib = false;
        int step = 0;
        while(true)
        {
            //Check if we printed all of the nodes or not
            if(step == size)
                break;
            // We can move left
            if(!left_forib){

                // We can not move left anymore
                if(to_print->left == nullptr)
                {
                    left_forib = true;
                    continue;
                }
                to_print = to_print->left;
                continue;
            }
            // We can print the node
            if(!self_forib)
            {
                std::cout << to_print->data << std::endl;
                step++;
                self_forib = true;
                continue;
            }
            //We can not move left and we can not print the node, so we move right.
            if(!right_forib)
            {
                // We can not move right anymore
                if(to_print->right == nullptr)
                {
                    right_forib = true;
                    continue;
                }

                to_print = to_print->right;
                right_forib = false;
                self_forib = false;
                left_forib = false;
                continue;

            }
            //Node is not root
            if(to_print != root)
            {
                // We can not move left or right or print the node, so we go back to the parent

                right_forib = false;
                self_forib = false;
                left_forib = false;
                // Node is on the left side of the parent
                if(to_print == to_print->parent->left)
                {
                    left_forib = true;

                }
                // Node is on the right side of the parent
                if(to_print == to_print->parent->right)
                {
                    left_forib = true;
                    right_forib = true;
                    // If the node is on the right side of it's parent we're absoulty sure that the parent was printed before.
                    self_forib = true;
                }
                to_print = to_print->parent;
            }
        }
    }
    bool remove(int data)
    {
        Node* dataptr = find(data);

        if(dataptr == nullptr)
            return false;

        if(dataptr == root)
        {
            Node* minRight = get_min(root->right);
            if(minRight == nullptr)
            {
                root = root->left;
                if(root != nullptr)
                    root->parent = nullptr;
            }
            else
            {
                minRight->left = root->left;
                if(root->left != nullptr)
                    root->left->parent = minRight;
                root = root->right;
                root->parent = nullptr;
            }
        }
        else
        {
            bool rightside = (dataptr == dataptr->parent->right);
            // Data doesn't have right side
            if(dataptr->right == nullptr)
            {
                if(!rightside)
                    dataptr->parent->left = dataptr->left;
                if(rightside)
                    dataptr->parent->right = dataptr->left;
                // Data has left side
                if(dataptr->left != nullptr)
                {
                    dataptr->left->parent = dataptr->parent;
                }
            }
            // Data has right side
            else
            {
                Node* minright = get_min(dataptr->right);
                minright->left = dataptr->left;

                if(!rightside)
                    dataptr->parent->left = dataptr->right;
                if(rightside)
                    dataptr->parent->right = dataptr->right;

                dataptr->right->parent = dataptr->parent;
                // Data has left side
                if(dataptr->left != nullptr)
                {
                    dataptr->left->parent = minright;
                }
            }
            }
        size--;
        delete dataptr;
        return true;
    }


private:
    Node* get_min(Node* node)
    {
        while(node->left != nullptr)
            node = node->left;
        return node;
    }
};



int main()
{

//    BST bst;
//    bst.insert(50);
//    bst.insert(100);
//    bst.insert(87);
//    bst.insert(10);
//    bst.insert(74);
//    bst.insert(63);
//    bst.insert(72);
//    bst.insert(86);
//    bst.insert(1);
//    bst.insert(25);
//    bst.insert(68);
//    bst.insert(41);
//    bst.insert(32);
//    bst.insert(52);
//    bst.insert(118);
//    bst.print();
//    //bst.~BST();
//    //bst.print();

    return 0;
}
