test: a.out
	./a.out
main.o:
	g++ -c -std=c++11 main.cpp
a.out: main.o
	g++ main.o
clean:
	rm *.o test