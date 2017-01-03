#include <bits/stdc++.h>

using namespace std;
struct RedBlackTree {
	struct Node;
	Node *leaf, *root;
	RedBlackTree();
	Node* NewNode();
	Node* RotateLeft(Node *child);
	Node* RotateRight(Node *child);
	Node* Insert(Node *is);
	Node* Insert(int key);
	Node* Find(int key);
	bool isLeaf(Node* node);
};
struct RedBlackTree::Node {
	Node(){}
	Node *leftc, *rightc, *parent;
    bool red;
	int key;
};
struct Tester {
	RedBlackTree* tree;
	Tester();
	void PrintTree(RedBlackTree*);
	void Test(const char* inputfile);
};
bool RedBlackTree::isLeaf(Node* node) {
	return node == leaf;
}
Tester::Tester() {
	tree = new RedBlackTree();
}
void Tester::PrintTree(RedBlackTree* T) {
	puts("Start PrintTree");
	puts("---------------------------");
	queue<RedBlackTree::Node*> que;
	que.push(tree->root);
	while(!que.empty()) {
		auto v = que.front();
		que.pop();
		printf("Node: %d, color: %d, leftc: %d, rightc: %d, parent: %d\n",
				v->key, v->red, v->leftc->key, v->rightc->key, v->parent->key);
		if(!T->isLeaf(v->leftc)) que.push(v->leftc);
		if(!T->isLeaf(v->rightc)) que.push(v->rightc);
	}
	puts("End PrintTree");
	puts("----------------------------");
}
void Tester::Test(const char* inputfile) {
	ifstream in(inputfile);
	if(!in.is_open()) {
		puts("openfile error");
		return;
	}
	int cases;
	in >> cases;
	for(int i = 0; i < cases; i++) {
		string op;
		in >> op;
		int x;
		in >> x;
		if(op == "Insert") {
			tree->Insert(x);
		} else if(op == "RotateLeft"){
			auto p = tree->Find(x);
			tree->RotateLeft(p);
		} else if(op == "RotateRight") {
			auto p = tree->Find(x);
			tree->RotateRight(p);
		}
		puts("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
		printf("end operation %d\n", i + 1);
		PrintTree(tree);
	}
	puts("end operation");
	PrintTree(tree);
	in.close();
}
RedBlackTree::Node* RedBlackTree::Insert(int key) {
	Node* is = NewNode();
	is->key = key;
	Insert(is);
}
RedBlackTree::Node* RedBlackTree::NewNode() {
	Node* p = new Node();
	p->parent = p->leftc = p->rightc = leaf;
	p->red = 1;
	return p;
}
RedBlackTree::RedBlackTree() {
	leaf = new Node();
	leaf->key = -1;
	leaf->red = 0;
	leaf->parent = leaf->leftc = leaf->rightc = leaf;
	root = leaf;
}
RedBlackTree::Node* RedBlackTree::Insert(Node *is) {
	Node* now = root, *p = leaf;
	while(now != leaf) {
		assert(now->key != is->key);
		p = now;
		if(now->key > is->key) now = now->leftc;
		else now = now->rightc;
	}
	if(p == leaf) return root = is;
	else {
		if(p->key > is->key) p->leftc = is;
		else p->rightc = is;
		is->parent = p;
		return is;
	}
}
RedBlackTree::Node* RedBlackTree::Find(int key) {
	Node* now = root;
	while(now != leaf) {
		if(now->key == key) return now;
		if(now->key > key) now = now->leftc;
		else now = now->rightc;
	}
	return leaf;
}
RedBlackTree::Node* RedBlackTree::RotateLeft(Node *child) {
	Node *p = child->parent;
	assert(p != 0);
	assert(child != p->leftc);
	Node *x = p->leftc;
	Node *y = child->leftc;
	Node *z = child->rightc;
	Node *pp = p->parent;
	swap(*p, *child);
	p->rightc = z;
	p->leftc = child;
	p->parent = pp;
	child->parent = p;
	child->rightc = y;
	child->leftc = x;
	x->parent = child;
	z->parent = p;
	return p;
}
RedBlackTree::Node* RedBlackTree::RotateRight(Node *child) {
	Node *p = child->parent;
	assert(p != 0);
	assert(child != p->rightc);
	Node *x = child->leftc;
	Node *y = child->rightc;
	Node *z = p->rightc;
	Node *pp = p->parent;
	swap(*p, *child);
	p->rightc = child;
	p->leftc = x;
	p->parent = pp;
	child->parent = p;
	child->rightc = z;
	child->leftc = y;
	x->parent = p;
	z->parent = child;
	return p;
}
int main() {

	Tester tester = Tester();
	//tester.Test("/home/thyrix/Data/RedBlackTreeTest/InsertTestCase1");
	tester.Test("/home/thyrix/Data/RedBlackTreeTest/RotateTestCase1");
	return 0;
}
