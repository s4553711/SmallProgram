#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "pdb.h"
#include "unistd.h"

using namespace std;
pdb::pdb(){
}

void pdb::get_atom(void){
}

void pdb::parse(string id){

	cout << "Parse Start: " << id << endl;
	
	string line = "";
	ifstream file;
	file.open("1air.pdb",ios::in);

	while(!file.eof()) {
		getline(file,line);

		if (line != "" && line.substr(0,6) == "ATOM  ") {
			struct pdb_atom tmp_atom;

			tmp_atom.x = atof(line.substr(30,8).c_str());
			tmp_atom.y = atof(line.substr(38,8).c_str());
			tmp_atom.z = atof(line.substr(46,8).c_str());
			tmp_atom.opy = atof(line.substr(54,6).c_str());
			tmp_atom.tmpf = atof(line.substr(60,6).c_str());
			tmp_atom.res = line.substr(17,3);
			tmp_atom.atomname = line.substr(12,4);
			tmp_atom.chain = line.substr(21,1);
			tmp_atom.resnum = atoi(line.substr(22,4).c_str());
			tmp_atom.atomnum = atoi(line.substr(6,5).c_str());

			ivec.push_back(tmp_atom);
		}
	}

	file.close();
	cout << "Parse exit " << endl;
}

void pdb::display(void){

	// Start parsing PDB Info
	for(vector<struct pdb_atom>::iterator it = ivec.begin();it != ivec.end();it++){
		cout << "Tets> " << it->chain << "\t" << it->atomnum << "\t" << it->atomname 
			<< "\t" << it->res << "\t" << it->resnum << "\t" << it->x << "\t" << it->y 
			<< "\t" << it->z << "\t" << it->opy << "\t" << it->tmpf << endl;
	}

	//usleep(10000000);
}

void pdb::calc_phipsi(void){

	int i = 99999;

	struct pdb_atom pC0, pN, pCA, pC1;
	struct pdb_atom sN0, sCA, sC0, sN1;

	for(vector<struct pdb_atom>::iterator it = ivec.begin();it != ivec.end();it++){

	}
}
