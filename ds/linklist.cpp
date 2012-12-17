#include <iostream>
#include "linklist.h"

using namespace std;

CKLinkList::CKLinkList(){
	p = NULL;
	count_i = 0;
};

int CKLinkList::length(){
	return count_i;
};

void CKLinkList::del(int num){
	node *q, *r;
	q = p;

	// No node
	if (p == NULL) return;

	// Delete the first node
	if (q->x == num){
		p = q->link;
		delete q;
		count_i--;
		return;
	}

	// Delete the remainder
	r = q;
	while( q != NULL){
		if (q->x == num){
			r->link = q->link;
			delete q;
			count_i--;
			return;
		}

		r = q;
		q = q->link;
	}
};

void CKLinkList::insert_first(int num){

	node *q, *t;
	q = p;

	t = new node;
	t->x = num;
	t->y = num*2;
	t->z = num*3;

	t->link = q;
	p = t;
	count_i++;
};

void CKLinkList::insert_after(int start_val,int num){
	node *q, *t;

	if (start_val != 0){
		q = p;
		while(q->link != NULL){
			if (q->x == start_val){

				t = new node;
				t->x = num;
				t->y = num*2;
				t->z = num*3;
				t->link = q->link;
				q->link = t;

				count_i++;
				return;
			}

			q = q->link;
		}
	}
};

void CKLinkList::append(int num){
	node *q, *t;

	if (p == NULL){
		p = new node;
		p->x = num;
		p->y = num*2;
		p->z = num*3;
		p->link = NULL;
	} else {
		q = p;
		while(q->link != NULL){
			q = q->link;
		}

		t = new node;
		t->x = num;
		t->y = num*2;
		t->z = num*3;
		t->link = NULL;
		q->link = t;
	}

	count_i++;
};

void CKLinkList::display_line(void){
	node *q;

	for(q = p; q != NULL; q = q->link){
		cout << " <- " << q->x;
	}

	cout << endl;
};

void CKLinkList::display(void){
	node *q;

	for(q = p; q != NULL; q = q->link){
		cout << "This is : " << q->x << ", " << q->y << ", " << q->z << endl;
	}
};

CKLinkList::~CKLinkList(){
	node *q;
	if (p == NULL) return;

	while (p != NULL){
		q = p->link;
		delete p;
		p = q;
	}
};
