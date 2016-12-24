CC=gcc
CFLAGS=-c
#SOURCES=main.c sort.c sort.h util.c util.h
SOURCES=main.c mysort.c mysort.h util.c util.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=sortdemo

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
