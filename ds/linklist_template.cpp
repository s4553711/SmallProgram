#include <iostream>
using namespace std;

template <class T>
class ChainNode {
	private:

	public:
		T data;
		ChainNode<T> *link;

		ChainNode(void){};
		ChainNode(const T& data){ this->data = data; };
		ChainNode(const T& data, ChainNode<T> *link){
			this->data = data;
			this->link = link;
		};
};

template <class T>
class Chain {
	private:
		ChainNode<T> *first;
		int count;

	public:
		Chain(void){ first = NULL; count = 0; };
		bool isEmpty() const {return first == NULL;}
		int IndexOf(const T&) const;
		int size(void){return count;}
		void Delete(int);
		void Insert(int,const T&);
		void Display(void);
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
		count--;

	} else {
		ChainNode<T> *p = first;
		for(int i =0; i< theIndex-1; i++){
			if (p == NULL) throw "Element not exist";
			p = p->link;
		}

		deleteNode = p->link;
		p->link = p->link->link;
		delete deleteNode;
		count--;
	}
}

template <class T>
void Chain<T>::Insert(int theIndex, const T& theElement){
	if (theIndex < 0) throw "Bad";

	if (theIndex == 0){
		first = new ChainNode<T>(theElement,first);
		count++;
	} else {
		ChainNode<T> *p = first;
		for(int i = 0; i < theIndex-1; i++){
			if (p == NULL) throw "Not Exist";
			p = p->link;
		}
		
		p->link = new ChainNode<T>(theElement, p->link);
		count++;
	}
};

template <class T>
void Chain<T>::Display(void){

	ChainNode<T> *p = first;

	while(p != NULL){
		cout << " <- " << p->data;
		p = p->link;
	}
	cout << endl;
};

int main() {
	cout << "This is LinkList .." << endl;

	Chain<int> *list = new Chain<int>;
	cout << "Size: " << list->size() << endl;

	list->Insert(0,1);
	list->Display();
	list->Insert(0,2);
	list->Display();
	list->Insert(1,3);
	list->Display();
	list->Insert(1,4);
	list->Display();
	list->Insert(0,5);
	list->Display();
	list->Delete(2);
	list->Display();

	cout << "Size: " << list->size() << endl;
}
