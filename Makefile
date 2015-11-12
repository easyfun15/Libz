CC= g++

IDIR= /usr/local/include/

CFLAGS= -I$(IDIR)

LDFLAGS= -lz

release:
	@echo "building LibzExample release"
	$(CC) -o "LibzExample" app/LibzExample.cpp    $(CFLAGS) -g -DDEBUG $(LDFLAGS)
	@echo "build LibzExample release success"

debug:
	@echo "building LibzExample debug"
	$(CC) -o "LibzExample" app/LibzExample.cpp   $(CFLAGS) -DDEBUG -g $(LDFLAGS)
	@echo "build LibzExample debug success"

clean:
	rm -f LibzExample

