CXX=g++
CXXFLAGS=-Wall -I.
OBJS=drzewo.o main.o

pong: drzewo.o main.o
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	
.PHONY: clean

clean: 
	rm -f *.o *~ core *~
