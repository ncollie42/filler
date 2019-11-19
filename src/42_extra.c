#include "h_functions.h"


char *gnl(int fd) {
    static char buf[256];
    int k = 0;
    char c = 0;
    while (read(fd, &c, 1) > 0) {
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








// void getMapBody() {
//     char    *line;
//     int     hh;
//     int     offset;
    
//     hh = height;
//     offset = 0;
//     gnl();          // Skil first line
//     while(hh--) {
//         line = gnl();
//         ft_memmove(map + offset, (line + 4), width);
//         offset += width;
//     }
// }

// void getMap(){
//     dimentions ret;
//     if (!height) {
//         ret = getDimentions();
//         height = ret.height;
//         width = ret.width;
//         map = malloc(sizeof(char) * (height * width));
//     } else {
//         gnl();
//     }
//     getMapBody();
// }

// block getPiece() {
//     char    *line;
//     dimentions ret;
//     block p;
//     int offset = 0;

//     ret = getDimentions();
//     p.dimen = ret;
//     int tmp = ret.height;
//     p.body = malloc(sizeof(char) * p.dimen.height * p.dimen.width);
//     while(tmp--) {
//         line = gnl();
//         ft_memmove(p.body + offset, line, p.dimen.width);
//         offset += p.dimen.width;
//     }
//     return p;
// }
