#include "h_functions.h"


char *gnl() {
	static char buf[256];
	int k = 0;
	char c = 0;
	while (read(0, &c, 1) > 0) {
		if (c == '\n' || k > 255)
			break;
		buf[k++] = c;
	}
	buf[k] = '\0';
	return buf;
}

void freeSplitLine(char **split) {
   int  ii;

   ii = -1;
   while(split[++ii])
	   free(split[ii]);
   free(split);
}

int _puts(int fd, const char *str) {
	return write(fd,str,__builtin_strlen(str));
}

void freeBlocks(char *map, char *piece) {
	free(map);
	free(piece);
}

block newBlock(dimentions dimen)
{
	block tmp;

	tmp.dimen = dimen;
	tmp.body = malloc(sizeof(char) * tmp.dimen.height * tmp.dimen.width);
	ft_bzero(tmp.body, tmp.dimen.height * tmp.dimen.width);
	return tmp;
}

void printPoint(int x, int y)
{
	char *num1 = ft_itoa(y);
	char *num2 = ft_itoa(x);
	write(1, num1, ft_strlen(num1));
	write(1, " ", 1);
	write(1, num2, ft_strlen(num2));
	write(1, "\n", 1);
	free(num1);
	free(num2);
}
