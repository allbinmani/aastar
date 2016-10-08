CC=g++
LD=$(CC)
CFLAGS=$(CCFLAGS) -Os -Wall -Wp,-I.
LDFLAGS= -Wl,--gc-sections
COMPILE=$(CC) $(CFLAGS)
LINK=$(LD) $(LDFLAGS)

example: example.o AstarNode.o NodeHeap.o Astar.o debugcompat.o
	$(LINK) -o example example.o debugcompat.o NodeHeap.o AstarNode.o Astar.o

strip:
	strip -s -R '.comment' -R '.gnu.version' --strip-unneeded example

clean:
	rm -f *.o

debugcompat.o: debugcompat.h debugcompat.c
	$(COMPILE) -c debugcompat.c -o debugcompat.o 

AstarNode.o: AstarNode.h AstarNode.cpp
	$(COMPILE) -c AstarNode.cpp -o AstarNode.o

NodeHeap.o: NodeHeap.h NodeHeap.cpp
	$(COMPILE) -c NodeHeap.cpp -o NodeHeap.o

Astar.o: Astar.h Astar.cpp
	$(COMPILE) -c Astar.cpp -o Astar.o

example.o: example.cpp
	$(COMPILE) -c example.cpp -o example.o
