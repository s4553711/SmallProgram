//
// DataStructure Double-linked
//

#include <iostream>
#include "pdb.h"
using namespace std;

int main (int argc, char* argv[])
{
	cout << "COMMT> PDB Analysis Program" << endl;
	cout << "COMMT> Argument #: " << argc << endl;

	for(int i = 0; i < argc; i++){
		cout << "COMMT> Arg"<< i << " : " << argv[1] << endl;
	}

	pdb* pdb_reader = new pdb();
	pdb_reader->get_atom();
	pdb_reader->parse("1air");

	delete pdb_reader;

	return 0;
}
