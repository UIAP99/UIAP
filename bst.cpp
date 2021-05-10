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
        void set_parent(Node *parent)
        {
            this->parent = parent;
        }
        Node* get_right()
        {
            return right;
        }
        void set_right(Node *right)
        {
            this->right = right;
        }
        Node* get_left()
        {
            return left;
        }
        void set_left(Node *left)
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
            int get_size()
            {
                return size;
            }
		Binary_Search_Tree();
		~Binary_Search_Tree();
		void insert(int data);
		void remove(int data);
                Node *find(int data);
		//search about bfs
		void print();
};
int main()
{
	return 0;
}
