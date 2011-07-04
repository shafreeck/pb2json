#include <iostream>
#include <fstream>
#include "person.pb.h"

using namespace std;
using namespace google::protobuf;

int main(int argc,char *argv[])
{
	Person p;
	p.set_name("renenglish");
	cout<<"set name:"<<p.name()<<endl;
	p.set_id(1);
	cout<<"set id :"<<p.id()<<endl;
	p.set_email("renenglish@163.com");
	cout<<"set_email:"<<p.email()<<endl;

	Person_PhoneNumber *pn1 = p.add_phone();
	pn1->set_number("1234567");
	pn1->set_type(Person::HOME);
	cout<<"add phone: number:"<<pn1->number()<<" type:"<<pn1->type()<<endl;

	Person_PhoneNumber *pn2 = p.add_phone();
	pn2->set_number("7654321");
	pn2->set_type(Person::MOBILE);
	cout<<"add phone: number:"<<pn2->number()<<" type:"<<pn2->type()<<endl;

	ofstream of("dump");
	p.SerializeToOstream(&of);

	return 0;
}
