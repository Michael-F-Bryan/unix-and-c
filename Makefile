CC = gcc
CFLAGS = -g -Wall -pedantic
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)


default: run_tests

run_tests: test
	-clear
	@echo "Running Tests"
	@echo "============="
	@echo
	./test

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

test: $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f *.gch
	-rm -f test
