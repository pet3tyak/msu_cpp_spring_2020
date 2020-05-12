all: start

start: test.o mysort.o 
		g++ -std=c++17 -o start test.o mysort.o

mysort.o: mysort.cpp mysort.h
		g++ -std=c++17 -c mysort.cpp

test.o: test.cpp mysort.h
		g++ -std=c++17 -c test.cpp
		
run:	start
		./start

clean:
		rm -rf *.o start
		rm -rf *.stackdump start
		rm -rf *.exe start