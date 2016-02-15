main:main.o func.o
	g++ -o main main.o func.o
main.o:main.c
	g++ -c main.c
func.o:func.c
	g++ -c func.c
.PHONY:clean

clean:
	rm -f main.o func.o main

