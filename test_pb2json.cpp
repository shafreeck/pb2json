#include <iostream>
#include <jansson.h>
#include <hiredis/hiredis.h>
#include <google/protobuf/descriptor.h>
#include "user_info.pb.h"
#include "pb2json.h"
using std::string;
using std::cout;
using std::endl;
using namespace google::protobuf;

extern "C"{
char * getjson(char *name,char *buf,int len)
{
	Message *msg;
	if(!strcmp(name,"user_base"))
		msg = new user_base();
	if(!strcmp(name,"user_ext"))
		msg = new user_ext();
	char *json = pb2json(msg,buf,len);
	delete msg;
	return json;
}
}
int main(int argc,char *argv[])
{
	if (argc !=2)
	{
		cout<<argv[0]<<" uid"<<endl;
		exit(1);
	}
	char * uid = argv[1];
	redisContext *c;
	redisReply *reply;
	c = redisConnect("127.0.0.1",8001);
	if(c->err)
	{
		printf("error when connect to redis:%s\n",c->errstr);
		exit(1);
	}

	char * prefix = "usex";
	reply = (redisReply*)redisCommand(c,"GET %s.%s",uid,prefix);
	int len = reply->len;
	char *buf = reply->str;
	cout<<getjson("user_ext",buf,len)<<endl;
}

