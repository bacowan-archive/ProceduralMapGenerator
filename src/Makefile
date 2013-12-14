LIBS=
CFLAGS=-Wall -std=c++0x
SRC=$(wildcard *.cc)

test: $(SRC)
	g++ -c $^ $(CFLAGS) $(LIBS)
	
clean:
	rm *.o
