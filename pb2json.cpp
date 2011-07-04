#include "pb2json.h"

using std::string;
char * pb2json(Message *msg,const char *buf ,const int len)
{
	string s (buf,len);
	msg->ParseFromString(s);
	json_t *root = parse_msg(msg);
	char *json = json_dumps(root,0);
	json_decref(root);
	return json; // should be freed by caller
}
static json_t *parse_msg(const Message *msg)
{
	const Descriptor *d = msg->GetDescriptor();
	if(!d)return NULL;
	size_t count = d->field_count();
	json_t *root = json_object();
	if(!root)return NULL;
	for (size_t i = 0; i != count ; ++i)
	{
		const FieldDescriptor *field = d->field(i);
		if(!field)return NULL;
		const Reflection *ref = msg->GetReflection();
		if(!ref)return NULL;
		if(ref->HasField(*msg,field))
		{
			double value1;
			float value2;
			int64_t value3;
			uint64_t value4;
			int32_t value5;
			uint32_t value6;
			bool value7;
			string value8;
			const Message *value9;
			const EnumValueDescriptor *value10;

			const char *name = field->name().c_str();
			switch (field->cpp_type())
			{
				case FieldDescriptor::CPPTYPE_DOUBLE:
					value1 = ref->GetDouble(*msg,field);
					json_object_set_new(root,name,json_real(value1));	
					break;
				case FieldDescriptor::CPPTYPE_FLOAT:
					value2 = ref->GetFloat(*msg,field);
					json_object_set_new(root,name,json_real(value1));	
					break;
				case FieldDescriptor::CPPTYPE_INT64:
					value3 = ref->GetInt64(*msg,field);
					json_object_set_new(root,name,json_integer(value3))	;
					break;
				case FieldDescriptor::CPPTYPE_UINT64:
					value4 = ref->GetUInt64(*msg,field);
					json_object_set_new(root,name,json_integer(value4));	
					break;
				case FieldDescriptor::CPPTYPE_INT32:
					value5 = ref->GetInt32(*msg,field);
					json_object_set_new(root,name,json_integer(value5));	
					break;
				case FieldDescriptor::CPPTYPE_UINT32:
					value6 = ref->GetUInt32(*msg,field);
					json_object_set_new(root,name,json_integer(value6));	
					break;
				case FieldDescriptor::CPPTYPE_BOOL:
					value7 = ref->GetBool(*msg,field);
				
					json_object_set_new(root,name,value7?json_true():json_false())	;
					break;
				case FieldDescriptor::CPPTYPE_STRING:
					value8 = ref->GetString(*msg,field);
					json_object_set_new(root,name,json_string(value8.c_str()));	
					break;
				case FieldDescriptor::CPPTYPE_MESSAGE:
					value9 = &(ref->GetMessage(*msg,field));
					json_object_set_new(root,name,parse_msg(value9));
					break;//FIXME : parse Message
				case FieldDescriptor::CPPTYPE_ENUM:
					value10 = ref->GetEnum(*msg,field);
					json_object_set_new(root,name,json_integer(value10->number()));	
					break;
				default:
					break;
			}

		}

	}
	return root;

}
