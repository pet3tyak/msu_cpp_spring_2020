all: start

start: test.o
		g++ -o start test.o


test.o: test.cpp vector.h allocator.h iterator.h
		g++ -c test.cpp
		
run:	start
		./start

clean:
		rm -rf *.o start
		rm -rf *.stackdump start
		rm -rf *.exe start