#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "pdb.h"

using namespace std;
pdb::pdb(){
}

void pdb::get_atom(void){
}

void pdb::parse(string id){

	cout << "Parse Start: " << id << endl;
	
	vector<struct pdb_atom> ivec;

	string line = "";
	ifstream file;
	file.open("1air.pdb",ios::in);

	while(!file.eof()) {
		getline(file,line);
		string str2 = line.substr (0,12);

		if (line != "" && line.substr(0,6) == "ATOM  ") {
			struct pdb_atom tmp_atom;

			tmp_atom.x = atof(line.substr(30,8).c_str());
			tmp_atom.y = atof(line.substr(38,8).c_str());
			tmp_atom.z = atof(line.substr(46,8).c_str());
			tmp_atom.res = line.substr(17,3);
			tmp_atom.resnum = atoi(line.substr(22,4).c_str());

			ivec.push_back(tmp_atom);

		}
	}

	file.close();
	cout << "Parse exit " << endl;

	//
	// Start parsing PDB Info
	//
	for(vector<struct pdb_atom>::iterator it = ivec.begin();it != ivec.end();it++){
		cout << "Tets> " << it->res << " :: " << it->resnum << "\t" << it->x << "\t" << it->y << "\t" << it->z << endl;
	}
}

void pdb::residue_analysis(void){

}
