all: start

start: test.o
		g++ -std=c++17 -o start test.o

test.o: test.cpp pool.h
		g++ -std=c++17 -c test.cpp
		
run:	my_prog
		./start

clean:
		rm -rf *.o start
		rm -rf *.stackdump start
		rm -rf *.exe start