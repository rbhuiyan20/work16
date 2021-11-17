all: work16.o
	gcc -o output work16.o

work13.o: work16.c
	gcc -c work16.c

run:
	./output

clean:
	rm *.o
	rm output
	


