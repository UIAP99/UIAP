#include <iostream>

template <typename T>
class Node{

    template<typename Ta>
    friend class BST;
private:
    T data;
    Node* parent;
    Node* right;
    Node* left;
    Node(T data)
    {
        this->data = data;
        parent = nullptr;
        right = nullptr;
        left = nullptr;
    }
};

template <typename T>
class BST{

private:
    Node<T>* root;
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
    bool insert(T data)
    {
        Node<T>* new_node = new Node<T>(data);

        if(root == nullptr)
        {
            root = new_node;
            size++;
            return true;
        }

        Node<T>* tempnode = root;
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
    Node<T>* find(T data)
    {
        if(root->data == data)
            return root;
        Node<T>* tempnode = root;
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
        Node<T>* to_print = root;
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
    bool remove(T data)
    {
        Node<T>* dataptr = find(data);

        if(dataptr == nullptr)
            return false;

        if(dataptr == root)
        {
            Node<T>* minRight = get_min(root->right);
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
                Node<T>* minright = get_min(dataptr->right);
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
    Node<T>* get_min(Node<T>* node)
    {
        if(node == nullptr)
            return node;
        while(node->left != nullptr)
            node = node->left;
        return node;
    }
};



int main()
{

    BST<float> bst;
    bst.insert(20.4);
    bst.insert(100.5);
    bst.insert(87.7);
    bst.insert(10.5);
    bst.insert(74.1);
    bst.insert(63.9);
    bst.insert(72.7);
    bst.insert(86.7);
    bst.insert(1.8);
    bst.insert(25.9);
    bst.insert(68.4);
    bst.insert(41.8);
    bst.insert(32.5);
    bst.insert(52.9);
    bst.insert(118.11);
    bst.print();
    bst.~BST();
    bst.print();

    return 0;
}