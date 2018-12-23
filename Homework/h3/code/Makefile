CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic -Wno-unused-result -g
SRC = main.c ex3_ll.c ex3_sorter.c
MAIN = ex3_sorter
.PHONY: clean

all: $(MAIN)
	@echo ex3_sorter successfully constructed

$(MAIN): $(SRC)
	$(CC) $(CFLAGS) -o $(MAIN) $(SRC)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *.a *~ $(MAIN)
