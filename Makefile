CC = clang
CFLAGS = -g -Wall
LDFLAGS =
INCLUDES = -I.
SOURCES = main.c \
		  sort.c \
		  util.c

OBJECTS = $(SOURCES:.c=.o)
TARGET = sort

all: $(TARGET)
	@echo Compile sortdemo ok!

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm *.o $(TARGET)
