#include <fstream>
#include <iostream>
#include "person.pb.h"
//#include "../pb2json.h"
#include <pb2json.h>

using namespace std;

int main(int argc,char *argv[])
{
	ifstream fin("dump",ios::binary);
	fin.seekg(0,ios_base::end);
	size_t len = fin.tellg();
	fin.seekg(0,ios_base::beg);
	char *buf = new char [len];

	fin.read(buf,len);
	Message *p = new Person();
	char *json = pb2json(p,buf,len);
	cout<<json<<endl;
	free(json);
	delete p;
	return 0;
}
