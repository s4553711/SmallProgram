#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <fstream>
#include "linklist.h"

using namespace std;

void process_mem_usage(double& vm_usage, double& resident_set)
{
   using std::ios_base;
   using std::ifstream;
   using std::string;

   vm_usage     = 0.0;
   resident_set = 0.0;

   // 'file' stat seems to give the most reliable results
   //
   ifstream stat_stream("/proc/self/stat",ios_base::in);
   
   // dummy vars for leading entries in stat that we don't care about
   //
   string pid, comm, state, ppid, pgrp, session, tty_nr;
   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   string utime, stime, cutime, cstime, priority, nice;
   string O, itrealvalue, starttime;

   // the two fields we want
   //
	unsigned long vsize;
	long rss;

	stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
				>> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
				>> utime >> stime >> cutime >> cstime >> priority >> nice
				>> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

	stat_stream.close();

	long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
	vm_usage     = vsize / 1024.0;
	resident_set = rss * page_size_kb;
   //                                                                      }
}   

int main(){

	using std::cout;
	using std::endl;
	
	double vm, rss;

	for(int j = 1; j <= 2; j++){
		process_mem_usage(vm, rss);
		cout << "1> " << j << ", VM: " << vm << "; RSS: " << rss << endl;

		CKLinkList *container = new CKLinkList();
		//cout << "Add Element" << endl;

		for(int i = 1; i <= j*10; i++){
			container->append(i);
		}
		
		cout << "Length> " << container->length() << endl;
		container->display_line();

		cout << "Del> 8" << endl;
		container->del(8);
		cout << "Length> " << container->length() << endl;
		container->display_line();

		cout << "Insert> 1" << endl;
		container->insert_after(1,50);
		cout << "Length> " << container->length() << endl;
		container->display_line();

		cout << "Insert> First" << endl;
		container->insert_first(22);
		cout << "Length> " << container->length() << endl;
		container->display_line();

		delete container;

		process_mem_usage(vm, rss);
		cout << "2> " << j <<", VM: " << vm << "; RSS: " << rss << endl;
	}

	process_mem_usage(vm, rss);
	cout << "Final> VM: " << vm << "; RSS: " << rss << endl;

	//usleep(10000000);
}
