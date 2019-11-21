NAME = ncollie.filler
src = $(wildcard *.c)
obj = $(src:.c=.o)

LIBLOCATION = ../Lib/42_lib/
LDFLAGS = -L $(LIBLOCATION) -lft
CFLAGS :=  -Wall -Wextra -Wshadow -g -std=c11 
F = -fsanitize=address
all: $(NAME)

$(NAME): $(obj) $(LIBLOCATION)/libft.a
	$(CC) -o $@ $^ $(LDFLAGS) 

$(LIBLOCATION)/libft.a:
	make -C $(LIBLOCATION)

.PHONY: clean
clean:
	rm -f $(obj) f

re: clean all

fclean:	clean
	rm $(NAME)

superfclean: fclean
	make fclean -C $(LIBLOCATION)