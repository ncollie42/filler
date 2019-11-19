#include "h_functions.h"


void    genHeatMap(block map, players p)
{
    block visitedMap;
    queue *Q1;
    queue *Q2;
    groupedMaps maps;

    Q1 = initQueue();
    Q2 = initQueue();
    visitedMap = newBlock(map.dimen);
    maps.map = map;
    maps.visited = visitedMap;
    initQueFromMap(map, Q1, visitedMap, p);

    BFS_HeatMap(maps, Q1, Q2, 2);

    free(visitedMap.body);
    free(Q1);
    free(Q2);
}

int main(void) {
    // int fd = open("sample.data", O_RDWR);
    f = fopen("view", "w");
    // int fd = open("view", O_RDWR);
    int fd = 0;
    block map;
    block piece;
    players p;
    cordinate cord; 
    p = setPlayers(fd);
    while (1) 
    {
        map = getBlock(fd, MAP);
        piece = getBlock(fd, PIECE);
        piece = trimPiece(piece);
        genHeatMap(map, p);


        printPieceHiddenF(map);
        cord = getBestCordinate(map, piece);
        freeBlocks(map.body, piece.body);
        printPoint(cord.x, cord.y);

    }
}
