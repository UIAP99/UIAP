#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* parent;
    Node* right;
    Node* left;
public:
    Node(int data, Node* parent = nullptr, Node* right = nullptr, Node* left = nullptr)
    {
        this->data = data;
        this->parent = parent;
        this->right = right;
        this->left = left;
    }
    int get_data()
    {
        return data;
    }
    void set_data(int data)
    {
        this->data = data;
    }
    Node* get_parent()
    {
        return parent;
    }
    void set_parent(Node* parent)
    {
        this->parent = parent;
    }
    Node* get_right()
    {
        return right;
    }
    void set_right(Node* right)
    {
        this->right = right;
    }
    Node* get_left()
    {
        return left;
    }
    void set_left(Node* left)
    {
        this->left = left;
    }
};

class Binary_Search_Tree
{
private:
    Node* root;
    int size;
public:
    Binary_Search_Tree()
    {
        root=nullptr;
        size=0;
    }
    ~Binary_Search_Tree()
    {
        destroy(root);
        root = nullptr;
        size = 0;
    }
    void destroy(Node *tp)
    {
        if(tp == nullptr)
            return;
        destroy(tp->get_left());
        destroy(tp->get_right());
        delete tp;
    }
    int get_size()
    {
        return size;
    }
    void insert(int data)
    {
        Node* new_node{new Node(data)};

        if(root == nullptr)
        {
            root = new_node;
            size++;
            return;
        }

        Node* tempnode{root};
        while(true)
        {
            if(data < tempnode->get_data())
            {

                if(tempnode->get_left() == nullptr)
                {
                    tempnode->set_left(new_node);
                    new_node->set_parent(tempnode);
                    size++;
                    return;
                }

                tempnode = tempnode->get_left();
            }

            if(data > tempnode->get_data())
            {
                if(tempnode->get_right() == nullptr)
                {
                    tempnode->set_right(new_node);
                    new_node->set_parent(tempnode);
                    size++;
                    return;
                }

                tempnode = tempnode->get_right();
            }

            if(data == tempnode->get_data())
            {
                return;
            }
        }
    }
    bool remove(int data)
    {

        Node* dataptr{find(data)};

        if(dataptr == nullptr)
            return false;

        if(dataptr == root)
        {
            Node* minRight{get_min(root->get_right())};

            if(minRight == nullptr)
            {
                root = root->get_left();

                if(root != nullptr)
                    root->set_parent(nullptr);
            }

            else
            {

                minRight->set_left(root->get_left());

                root->get_left()->set_parent(minRight);

                root = root->get_right();

            }
        }

        else
        {

            bool rightside{dataptr == dataptr->get_parent()->get_right()};

            // Data doesn't have right side
            if(dataptr->get_right() == nullptr)
            {
                if(!rightside)
                    dataptr->get_parent()->set_left(dataptr->get_left());

                if(rightside)
                    dataptr->get_parent()->set_right(dataptr->get_left());

                // Data has left side
                if(dataptr->get_left() != nullptr)
                {
                    dataptr->get_left()->set_parent(dataptr->get_parent());
                }
            }

            // Data has right side
            else
            {

                Node* minright{get_min(dataptr->get_right())};

                minright->set_left(dataptr->get_left());

                if(!rightside)
                    dataptr->get_parent()->set_left(dataptr->get_right());

                if(rightside)
                    dataptr->get_parent()->set_right(dataptr->get_right());

                dataptr->get_right()->set_parent(dataptr->get_parent());

                // Data has left side
                if(dataptr->get_left() != nullptr)
                {
                    dataptr->get_left()->set_parent(minright);
                }
            }
        }

        size--;
        delete dataptr;
        return true;
    }

    Node* get_min(Node* node)
    {
        if(node == nullptr)
            return nullptr;

        if(node->get_left() == nullptr)
            return node;

        Node* temp{node->get_left()};

        while(temp->get_left() != nullptr)
        {
            temp = temp->get_left();
        }

        return temp;
    }

    Node *find(int data)
    {
        Node *tmp = root;
        while(tmp != nullptr)
        {
            if(data == tmp->get_data())
                return tmp;
            if(data > tmp->get_data())
                tmp = tmp->get_right();
            else
                tmp = tmp->get_left();
        }
        return nullptr;
    }
    //search about bfs
    void print();
};
int main()
{
    return 0;
}
