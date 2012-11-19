#include <iostream>
#include "pdb.h"

using namespace std;
pdb::pdb(){
	cout << "Construction" << endl;
}

void pdb::get_atom(void){
	cout << "Get Atom" << endl;
}

void pdb::parse(string id){
	cout << "Parse Start: " << id << endl;
}
