main: main.o section.o file.o symbol.o version.o relocation.o disasm.o dis-table.o upm.o operand.o SCInstr.o SCBlock.o SCFunction.o SCEdge.o SCLog.o
	g++ -o main main.o section.o file.o symbol.o version.o relocation.o disasm.o dis-table.o upm.o operand.o SCInstr.o SCBlock.o SCFunction.o SCEdge.o SCLog.o
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
disasm.o: disasm.cpp disasm.h dis-table.h type.h
	g++ -c -std=c++11 disasm.cpp
dis-table.o: dis-table.cpp dis-table.h SCInstr.h
	g++ -c -std=c++11 dis-table.cpp
upm.o: upm.h upm.cc
	g++ -c upm.cc
operand.o: type.h dis-table.h operand.cc
	g++ -c operand.cc
SCInstr.o: type.h SCInstr.h SCInstr.cpp operand.h
	g++ -c SCInstr.cpp
SCBlock.o: SCBlock.h SCBlock.cpp type.h
	g++ -c SCBlock.cpp
SCFunction.o: SCFunction.h SCFunction.cpp type.h
	g++ -c SCFunction.cpp
SCEdge.o: SCEdge.h SCEdge.cpp type.h
	g++ -c SCEdge.cpp
SCLog.o: SCLog.h SCLog.cpp
	g++ -c SCLog.cpp
clean:
	#rm -rf main *.o *~
	find . -name '*.o' -not -name 'obj.o' | xargs rm
