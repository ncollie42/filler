#include "h_functions.h"

dimentions getDimentions(int fd) {
    char *line;
    char **split;
    dimentions ret;

    line = gnl(fd);
    split = ft_strsplit(line, ' ');
    if (split[0] == NULL)
        exit(EXIT_FAILURE);
    ret.height = ft_atoi(split[1]);
    ret.width = ft_atoi(split[2]);
    freeSplitLine(split);
    return ret;
}

players setPlayers(int fd) {
    char *line;
    char **split;
    players p;

    line = gnl(fd);
    split = ft_strsplit(line, ' ');
    p.us = (split[2][1] == '1') ? 'o' : 'x';
    p.enemy = (split[2][1] == '2') ? 'o' : 'x'; 

    freeSplitLine(split);
    return p;
}

block getBlock(int fd, int type) {
    block   tmp;
    int     hh;
    char    *line;
    int     offset;

    offset = 0;
    tmp = newBlock(getDimentions(fd));
    hh = tmp.dimen.height;
    if (type == MAP) {
        gnl(fd);
    }
    while(hh--) {
        line = gnl(fd);
        ft_memmove(tmp.body + offset, (line + type), tmp.dimen.width);
        offset += tmp.dimen.width;
    }
    return tmp;
}
