main: main.o section.o file.o symbol.o version.o
	g++ -o main main.o section.o file.o symbol.o version.o
main.o: main.cc
	g++ -c main.cc
file.o: file.cc file.h
	g++ -c file.cc
section.o: section.cc section.h
	g++ -c section.cc
symbol.o: symbol.cc symbol.h
	g++ -c symbol.cc
version.o: version.cc version.h
	g++ -c version.cc
clean:
	rm -rf main *.o *~
