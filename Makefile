all:libpb2json.so
libpb2json.so:pb2json.cpp pb2json.h
	 gcc -g -O3 -shared -Wall -fPIC -o libpb2json.so pb2json.cpp -lprotobuf -ljansson
	 cd test && make -f Makefile
clean:
	rm -f *.o *.so test_pb2json
	cd test && make clean
install:
	cp -vf libpb2json.so /usr/local/lib/
	cp -vf pb2json.h /usr/local/include/
