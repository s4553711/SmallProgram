#include <iostream>
template <class T>
class ChainNode {
	private:
		T data;
		ChainNode<T> *link;
};

template <class T>
class Chain {
	private:
		ChainNode<T> *first;

	public:
		Chain(void){ first = NULL; };
		bool isEmpty() const {return first == NULL;}
		int IndexOf(const T&) const;
		void Delete(int);
		void Insert(int,const T&);
		~Chain();
};

// Destruction
template <class T>
Chain<T>::~Chain() {

	while (first != NULL){
		ChainNode<T> *next = first->link;
		delete first;
		first = next;
	}
};

template <class T>
int Chain<T>::IndexOf(const T& theElement) const{

	ChainNode<T> *currentNode = first;
	int index = 0;
	while(currentNode != NULL && currentNode->data != theElement){
		currentNode = currentNode->link;
		index++;
	}

	if (currentNode == NULL)
		return -1;
	else
		return index;
};

template <class T>
void Chain<T>::Delete(int theIndex){
	if (first == NULL) throw "Can not delete empty chain";

	ChainNode<T> *deleteNode;
	if (theIndex == 0){
		deleteNode = first;
		first = first->link;
		delete deleteNode;
	} else {
		ChainNode<T> *p = first;
		for(int i =0; i<= theIndex-1; i++){
			if (p == NULL) throw "Element not exist";
			p = p->link;
		}

		deleteNode = p->link;
		p->link = p->link->link;
		delete deleteNode;
	}
}

template <class T>
void Chain<T>::Insert(int theIndex, const T& theElement){
	if (theIndex < 0) throw "Bad";

	if (theIndex == 0){
		first = new ChainNode<T>(theElement,first);
	} else {
		ChainNode<T> *p = first;
		for(int i = 0; i < theIndex-1; i++){
			if (p == NULL) throw "Not Exist";
			p = p->link;
		}
		
		p->link = new ChainNode<T>(theElement, p->link);
	}
};

using namespace std;
int main() {
	cout << "THis is LinkList" << endl;

	Chain<int> *linklist = new Chain<int>;
}
