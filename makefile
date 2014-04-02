main: main.o section.o file.o symbol.o version.o relocation.o disasm.o dis-table.o
	g++ -o main main.o section.o file.o symbol.o version.o relocation.o disasm.o dis-table.o
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
relocation.o: relocation.cc relocation.h
	g++ -c relocation.cc
disasm.o: disasm.cpp disasm.h dis-table.h dis.h
	g++ -c disasm.cpp
dis-table.o: dis-table.cpp dis-table.h dis.h
	g++ -c dis-table.cpp
clean:
	rm -rf main *.o *~
