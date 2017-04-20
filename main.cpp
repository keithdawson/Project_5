#include <iostream>
#include "BST.cpp"
#include "Heap.cpp"
using namespace std;
int main() {
	int a[10];
	for (int i=0;i<10; i++) a[i]=i;
	BST T(a,10);
	T.inorder();
	T.preorder();
	T.insert(11);
	T.insert(10);
	T.inorder();
	node *t = T.search(11);
	T.preorder(t);
	T.remove(5);
	T.preorder();
	T.remove(3);
	T.preorder();
	T.remove(4,'s');
	T.preorder();
	T.remove(11);
	T.preorder();

	cout << endl << "Heap Examples" << endl;

	Heap h;
	h.insert(5); h.insert(10); h.insert(3);
	h.out();
	//cout << h.extract() << endl;
	//h.out();
	for (int i=0;i<10;i++) a[i]=10-i;
	Heap h2(a,10);
	//h2.out();
	//h2.extract();
	//h2.out();
	Heap h3(a,10,"max");
	//h3.out();
	//cout << h3.extract() << endl;
	//h3.out();
}