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
		// It may impact performance. It's faster to use recursive method.
		while(root != nullptr)
        {
            remove(root->get_data());
        }
		
		/*
        destroy(root);
        root = nullptr;
        size = 0;
		*/
    }
    Binary_Search_Tree(Binary_Search_Tree & x)
    {
        this->size=0;
        this->root=nullptr;
        Node * tmp=x.root;
        copy_constructor(tmp);

    }
    void copy_constructor( Node *tmp)
    {
        if(tmp)
        {
          insert(tmp->get_data());
          copy_constructor(tmp->get_left());
          copy_constructor(tmp->get_right());
        }
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
    	Node* FindMin(Node* tmp)
        {
            while(tmp->get_left() != nullptr) tmp = tmp->get_left();
            return tmp;
        }
        void remove(int data)
    {
        size--;
        root=main_remove(data,root);
    }
    Node * main_remove(int data,Node * tmp)
    {
        if(!tmp)
            return nullptr;
        else if(data<tmp->get_data())
            tmp->set_left(main_remove(data, tmp->get_left()));
        else if(data >tmp->get_data())
            tmp->set_right( main_remove(data, tmp->get_right()));
        else 
        {
            //no child
            if(tmp->get_left()==nullptr && tmp->get_right()==nullptr)
            {
                delete tmp;
                tmp=nullptr;
            }
            // one child
            else if(tmp->get_right()==nullptr)
            {
                Node * tt=tmp;
                tmp=tmp->get_left();
                delete tt;
            }
             else if(tmp->get_left()==nullptr)
            {
                Node * tt=tmp;
                tmp=tmp->get_right();
                delete tt;
            }
            //2 children
            else{
                Node * tt=FindMin(tmp->get_right());
                tmp->set_data(tt->get_data());
                tmp->set_right(main_remove(tt->get_data(),tmp->get_right()));
            }
        }
        return tmp;
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
    void print()
    {
        main_print(root);
        cout<<endl;
    }
    void main_print(Node * tmp)
    {
        if(tmp==nullptr)
        {
            return;
        }
        main_print(tmp->get_left());
        cout<<tmp->get_data()<<" ";
        main_print(tmp->get_right());
    }
};
int main()
{
    Binary_Search_Tree x;
    x.insert(100);
    x.insert(500);
    x.insert(200);
    x.insert(70);
    x.insert(100);
    x.print();
    x.remove(100);
    x.print();
    Binary_Search_Tree s=x;
    cout<<"-----------------"<<endl;
    s.print();
    return 0;
}
