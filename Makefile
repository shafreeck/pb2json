.PHONY: tests

all: lib tests

lib: libpb2json.so libpb2json.a

libpb2json.so: pb2json.cpp pb2json.h
	 ${CXX} -g -O3 -shared -Wall -fPIC -o libpb2json.so pb2json.cpp -lprotobuf -ljansson

libpb2json.a: pb2json.o
	 ar cr libpb2json.a pb2json.o

tests:
	 cd test && make -f Makefile

pb2json.o:pb2json.cpp

clean:
	rm -f *.o *.so *.a test_pb2json
	cd test && make clean

install:
	install libpb2json.so /usr/local/lib/
	install libpb2json.a /usr/local/lib/
	cp -vf  pb2json.h /usr/local/include/
