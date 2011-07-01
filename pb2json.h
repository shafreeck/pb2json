#include <jansson.h>
#include <string>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
using namespace google::protobuf;
char *pb2json( Message *msg,const char *buf,const int len);
