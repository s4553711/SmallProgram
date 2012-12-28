#include <iostream>
#include <vector>

using namespace std;
class pdb {
	private:
		vector<struct pdb_atom> ivec;

	public:
		pdb();
		void get_atom(void);
		void parse(string id);
		void calc_phipsi(void);
		void display(void);
		void dihedral(pdb_atom&, pdb_atom&, pdb_atom&, pdb_atom&);
};

struct pdb_atom {
	double x;
	double y;
	double z;
	double opy;
	double tmpf;
	string res;
	string atomname;
	string chain;
	int resnum;
	int atomnum;
};
