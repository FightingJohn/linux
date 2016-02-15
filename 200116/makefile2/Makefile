OBJS:=main.o func.o
EXE:=main
$(EXE):$(OBJS)
	g++ -o $(EXE) $(OBJS) 
main.o:main.c
	g++ -c main.c
func.o:func.c
	g++ -c func.c
.PHONY:clean

clean:
	rm -f $(OBJS) $(EXE)

