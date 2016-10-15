CC ?= g++
LD ?= $(CC)
CFLAGS ?= $(CCFLAGS) -Os -Wall -Wp,-I.
LDFLAGS ?= -Wl,--gc-sections

COMPILE=$(CC) $(CFLAGS)
LINK=$(LD) $(LDFLAGS)

libastar.o: Astar.o NodeHeap.o AstarNode.o debugcompat.o
	ar -cr libastar.a Astar.o NodeHeap.o AstarNode.o debugcompat.o

debugcompat.o: debugcompat.h debugcompat.c
	$(COMPILE) -c debugcompat.c -o debugcompat.o 

AstarNode.o: AstarNode.h AstarNode.cpp
	$(COMPILE) -c AstarNode.cpp -o AstarNode.o

NodeHeap.o: NodeHeap.h NodeHeap.cpp
	$(COMPILE) -c NodeHeap.cpp -o NodeHeap.o

Astar.o: Astar.h Astar.cpp
	$(COMPILE) -c Astar.cpp -o Astar.o
