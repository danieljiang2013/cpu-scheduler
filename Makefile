CC     = gcc
CFLAGS = -Wall -lm -g
EXE	   = scheduler
OBJ    = scheduler.o process.o

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

scheduler.o: scheduler.c
	$(CC) $(CFLAGS) -c scheduler.c

process.o: process.h process.c
	$(CC) $(CFLAGS) -c process.c


.PHONY: clean all

clean:
	rm -f $(OBJ) $(EXE)