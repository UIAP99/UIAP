#include <bits/stdc++.h>
using namespace std;

class node
{
	private:
		int data;
		node *parent;
		node *right;
		node *left;
	public:
		node(int data, node *parent = nullptr, node *right = nullptr, node *left = nullptr)
        {
            this->data = data;
            this->parent = parent;
            this->right = right;
            this->left = left;
        }
        int get_data()const
        {
            return data;
        }
        void set_data(int data)
        {
            this->data = data;
        }

};
class Binary_Search_Tree{
	private:
		node* root;
		int size;
	public:
		//add getter and setter functions here
		/*
			here
		*/
	Binary_Search_Tree();
	~Binary_Search_Tree();
	void insert(int data);
	void remove(int data);
	node *find(int data);
	//search about bfs
	void print();


};
int main(){


	return 0;
}
