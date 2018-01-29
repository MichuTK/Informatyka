CXX=g++
CXXFLAGS=-Wall -I.
OBJS=uczen.o main.o

pong: uczen.o main.o
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	
.PHONY: clean

clean: 
	rm -f *.o *~ core *~
