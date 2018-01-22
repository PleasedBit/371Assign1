make:
	gcc -std=c99 assignment.c -o assignment.o -lpthread
run:
	./assignment.o 200 /Documents
clean:
	rm *.o
