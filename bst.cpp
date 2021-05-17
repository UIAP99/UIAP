#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node<T> *right;
    Node<T> *left;
    Node<T> *parent;

public:
    Node(T data, Node<T> *parent = nullptr, Node<T> *right = nullptr, Node<T> *left = nullptr)
    {
        this->data = data;
        this->right = right;
        this->left = left;
        this->parent = parent;
    }
    T get_data()
    {
        return data;
    }
    void set_data(T data)
    {
        this->data = data;
    }
    Node<T> *get_right()
    {
        return right;
    }
    void set_right(Node<T> *right)
    {
        this->right = right;
    }
    Node<T> *get_left()
    {
        return left;
    }
    void set_left(Node<T> *left)
    {
        this->left = left;
    }
    Node<T> *get_parent()
    {
        return parent;
    }
    void set_parent(Node<T> *parent)
    {
        this->parent = parent;
    }
};

template <typename T>
class Binary_Search_Tree
{
private:
    Node<T> *root;
    int size;

public:
    Binary_Search_Tree()
    {
        root = nullptr;
        size = 0;
    }
    ~Binary_Search_Tree()
    {
        destroy(root);
        root = nullptr;
        size = 0;
    }
    Binary_Search_Tree(Binary_Search_Tree<T> &x)
    {
        this->size = 0;
        this->root = nullptr;
        Node<T> *tmp = x.root;
        copy_constructor(tmp);
    }
    Binary_Search_Tree<T> &operator<<(T d)
    {
        this->remove(d);
        return *this;
    }
    Binary_Search_Tree<T> &operator=(Binary_Search_Tree<T> &bst)
    {
        this->~Binary_Search_Tree();
        copy_constructor(bst.root);
        return *this;
    }
    void copy_constructor(Node<T> *tmp)
    {
        if (!tmp)
            return;
        insert(tmp->get_data());
        copy_constructor(tmp->get_left());
        copy_constructor(tmp->get_right());
    }
    void destroy(Node<T> *tp)
    {
        if (tp == nullptr)
            return;
        destroy(tp->get_left());
        destroy(tp->get_right());
        delete tp;
    }
    int get_size()
    {
        return size;
    }
    void insert(T data)
    {
        size++;
        root = main_insert(data, root, nullptr);
    }
    void remove(T data)
    {
        size--;
        root = main_remove(data, root);
    }
    Node<T> *find(T data)
    {
        return main_find(data, root);
    }
    void print()
    {
        main_print(root);
    }

private:
    void main_print(Node<T> *tmp)
    {
        if (tmp == nullptr)
        {
            return;
        }
        main_print(tmp->get_left());
        cout << tmp->get_data() << " ";
        main_print(tmp->get_right());
    }
    Node<T> *main_find(T data, Node<T> *tmp)
    {
        if (data == tmp->get_data() || tmp == nullptr)
            return tmp;
        if (tmp->get_data() > data)
            return main_find(data, tmp->get_left());
        return main_find(data, tmp->get_right());
    }
    Node<T> *main_remove(T data, Node<T> *tmp)
    {
        if (!tmp)
            return nullptr;
        else if (data < tmp->get_data())
            tmp->set_left(main_remove(data, tmp->get_left()));
        else if (data > tmp->get_data())
            tmp->set_right(main_remove(data, tmp->get_right()));
        else
        {
            //no child
            if (tmp->get_left() == nullptr && tmp->get_right() == nullptr)
            {
                delete tmp;
                tmp = nullptr;
            }
            // one child
            else if (tmp->get_right() == nullptr)
            {
                Node<T> *tt = tmp;
                tmp = tmp->get_left();
                tmp->set_parent(tt->get_parent());
                delete tt;
            }
            else if (tmp->get_left() == nullptr)
            {
                Node<T> *tt = tmp;
                tmp = tmp->get_right();
                tmp->set_parent(tt->get_parent());
                delete tt;
            }
            //2 children
            else
            {
                Node<T> *tt = FindMin(tmp->get_right());
                tmp->set_data(tt->get_data());
                tmp->set_right(main_remove(tt->get_data(), tmp->get_right()));
            }
        }
        return tmp;
    }
    Node<T> *main_insert(T data, Node<T> *tmp, Node<T> *prev)
    {
        if (!tmp)
            tmp = new Node<T>(data, prev, nullptr, nullptr);
        else if (tmp->get_data() > data)
            tmp->set_left(main_insert(data, tmp->get_left(), tmp));
        else if (tmp->get_data() < data)
            tmp->set_right(main_insert(data, tmp->get_right(), tmp));
        return tmp;
    }
    Node<T> *FindMin(Node<T> *tmp)
    {
        while (tmp->get_left() != nullptr)
            tmp = tmp->get_left();
        return tmp;
    }
};

template <typename T>
istream &operator>>(istream &k, Binary_Search_Tree<T> &bst)
{
    int x;
    k >> x;
    while (x >= 0)
    {
        bst.insert(x);
        k >> x;
    }
    return k;
}

template <typename T>
ostream &operator<<(ostream &k, Binary_Search_Tree<T> &bst)
{
    bst.print();
    return k;
}

template <typename T>
Binary_Search_Tree<T> &operator>>(Binary_Search_Tree<T> &bst, T data)
{
    bst.insert(data);
    return bst;
}

int main()
{
    Binary_Search_Tree<double> x;
    x.insert(100.2);
    x >> 34.0 >> 747.0 >> 200.0;
    x.insert(500);
    x.insert(12.1);
    x.insert(194.34);
    x.insert(70);
    cout << x << endl;
    x.remove(100.2);
    x.print();
    cout << endl;
    x << 12.1 << 200 << 34;
    Binary_Search_Tree<double> s = x;
    x.~Binary_Search_Tree();
    cout << "-----------------" << endl;
    cout << s << endl;
    cin >> s >> x;
    cout << s << endl
         << x << endl;
    return 0;
}