CC     = gcc
CFLAGS = -Wall -lm -g
EXE	   = scheduler
OBJ    = scheduler.o process.o schedule_queue.o memory.o

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

scheduler.o: scheduler.c
	$(CC) $(CFLAGS) -c scheduler.c

process.o: process.h process.c
	$(CC) $(CFLAGS) -c process.c

schedule_queue.o: schedule_queue.h schedule_queue.c
	$(CC) $(CFLAGS) -c schedule_queue.c

memory.o: memory.h memory.c
	$(CC) $(CFLAGS) -c memory.c

.PHONY: clean all

clean:
	rm -f $(OBJ) $(EXE)