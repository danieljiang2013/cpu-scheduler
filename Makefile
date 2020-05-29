CC     = gcc
CFLAGS = -Wall -lm
EXE	   = scheduler
OBJ    = scheduler.o

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

scheduler.o: scheduler.h scheduler.c
	$(CC) $(CFLAGS) -c scheduler.c

.PHONY: clean all

clean:
	rm -f $(OBJ) $(EXE)

	