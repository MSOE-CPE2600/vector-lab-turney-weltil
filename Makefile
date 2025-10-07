CC=gcc
CFLAGS=-c -Wall
LDFLAGS= -lncurses
SOURCES= main.c vector_math.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= compile

all: $(SOURCES) $(EXECUTABLE)

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d