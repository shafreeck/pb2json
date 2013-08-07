#include <jansson.h>
#include <string>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
using namespace google::protobuf;
char *pb2json(const Message &msg);
char *pb2json(Message *msg,const char *buf,int len);
static json_t *parse_msg(const Message *msg);
static json_t *parse_repeated_field(const Message *msg,const Reflection * ref,const FieldDescriptor *field);
