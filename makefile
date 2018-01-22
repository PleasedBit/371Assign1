make:
	gcc -std=c99 assignment.c -o assignment.o -lpthread
run:
	./assignment.o
clean:
	rm *.o
