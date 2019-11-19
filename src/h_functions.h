#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../Lib/42_lib/includes/libft.h"
#include <stdbool.h>
#define POS(x, y, width) ((x) + (y) * (width)) 
#define MAP 4
#define PIECE 0
#define ENEMY 1
#define PLAYER 0
#include "h_structs.h"

FILE *f;

block newBlock(dimentions dimen);

// extra
char *gnl();
void freeSplitLine(char **split);
int _puts(const char *str);
void freeBlocks(char *map, char *piece);

// read 
players setPlayers();
block getBlock(int type);

//peice update
block trimPiece(block piece);
//piece placement
cordinate getBestCordinate(block map, block piece);
//
void printPoint(int x, int y);

cordinate deQueue(queue *q);
void addQueue(queue *q, cordinate cord);
bool isQueueEmpty(queue *q);
queue *initQueue();
node *newNode(int x, int y);

//heatmap
void initQueFromMap(block map, queue *Q1, block visited, players p);
void BFS_HeatMap(groupedMaps maps, queue *Q1, queue *Q2, int level);

//testing
void printPiece(block p);
void printPieceF(block p);
void printPieceFD(int fd, block p);
void printQueue(queue *q);
void queTest(void);
void printPieceHidden(block p);
void printPieceHiddenF(block p);

#endif