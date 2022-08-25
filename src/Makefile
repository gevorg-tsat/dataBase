CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LGFLAGS=
SOURCES=main.c levels.c module.c shared.c status_events.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE) 

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

rebuild: clean all

run:
	./main
