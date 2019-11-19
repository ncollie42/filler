src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -L ../Lib/42_lib/ -lft
CFLAGS :=  -Wall -Wextra -Wshadow -g -std=c11 

f: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) -fsanitize=address

.PHONY: clean
clean:
	rm -f $(obj) f