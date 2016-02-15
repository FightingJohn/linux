OBJS:=main.o func.o
EXE:=main
CFLAGS:= -Wall -g
CC:=gcc
$(EXE):$(OBJS)
	$(CC) -o $@ $^
main.o:main.c
	$(CC) -c $(CFLAGS) $^ -o $@ -I../
func.o:func.c
	$(CC) -o $@ -c $(CFLAGS) $^
.PHONY:clean

clean:
	rm -f $(EXE) $(OBJS)

