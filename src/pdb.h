#include <iostream>

using namespace std;
class pdb {
	public:
		pdb();
		void get_atom(void);
		void parse(string id);
		void residue_analysis(void);
};

struct pdb_atom {
	double x;
	double y;
	double z;
	string res;
	int resnum;
};
