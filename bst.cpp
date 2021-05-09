#include <bits/stdc++.h>
using namespace std;

class node{
	private:
		int data;
		node *parent;
		node *right;
		node *left;
	public:
		//add getter and setter functions here
		/*
			here
		*/

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
