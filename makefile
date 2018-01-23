make:
	gcc -std=c99 craigstestcode.c -o craigstestcode.o -lpthread
run:
	./craigstestcode.o
clean:
	rm *.o
