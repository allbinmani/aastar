CC ?= g++
LD ?= $(CC)
CFLAGS ?= $(CCFLAGS) -Os -Wall -Wp,-I.
LDFLAGS ?= -Wl,--gc-sections

COMPILE=$(CC) $(CFLAGS)
LINK=$(LD) $(LDFLAGS)

example: src/libastar.a examples/generic/example.o
	$(LINK) -o examples/generic/example examples/generic/example.o -Lsrc -lastar

strip:
	strip -s -R '.comment' -R '.gnu.version' --strip-unneeded examples/generic/example

clean:
	rm -f src/*.o src/*.a examples/generic/*.o

src/libastar.a:
	(cd src; make);


examples/generic/example.o: examples/generic/example.cpp
	$(COMPILE) -DEXAMPLE -c examples/generic/example.cpp -Isrc/ -o examples/generic/example.o
