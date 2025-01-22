CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = --coverage
CHECK_FLAGS = -lcheck -lm -lsubunit
CFILES = memory.c 
OBJS = $(CFILES:.c=.o)
LIB_FILE = s21_matrix.a

run:clean $(LIB_FILE)
	$(CC) $(FLAGS) main.c -L. $(LIB_FILE) -o main
	./main

$(LIB_FILE): $(OBJS)
	ar rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf main *.a *.o
