all:test_pb2json
test_pb2json:test_pb2json.cpp user_info.pb.cc user_info.pb.h
	g++ -o test_pb2json test_pb2json.cpp user_info.pb.cc pb2json.cpp  -lhiredis -lprotobuf -ljansson
