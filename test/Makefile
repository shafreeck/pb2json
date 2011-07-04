all:person.pb.cc test_person test_json 
person.pb.cc:person.proto
	protoc --cpp_out=./ person.proto
test_person:test_person.cpp person.pb.cc person.pb.h
	g++ -g -o test_person test_person.cpp person.pb.cc -lprotobuf
test_json:test_json.cpp person.pb.cc person.pb.h ../pb2json.cpp  ../pb2json.h
	g++ -g -o test_json test_json.cpp person.pb.cc ../pb2json.cpp  -lprotobuf -ljansson

clean:
	rm -f test_person test_json person.pb.cc person.pb.h dump
