output: main.o now.o search.o sorts.o
	g++ main.o now.o search.o sorts.o -o main

main.o: main.cc
	g++ -c main.cc

now.o: now.cc now.hh
	g++ -c now.cc

search.o: search.cc search.hh
	g++ -c search.cc

sort.o: sorts.cc sorts.hh
	g++ -c sorts.cc

clean:
	rm *.o output
