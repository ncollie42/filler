#ifndef STRUCTS_H
#define STRUCTS_H

//filler
typedef struct dimentions {
    int height;
    int width;
}dimentions;

typedef struct block { 
    dimentions dimen;
    char        *body;
} block;

typedef struct players {
    char enemy;
    char us;
} players;

//queue
typedef struct cordinate {
    int x;
    int y;
}cordinate;

typedef struct node {
    cordinate cord;
    struct node *next;
}node;

typedef struct queue {
    node *first;
    node *last;
}queue;

typedef struct groupedMaps {
    block map;
    block visited;
} groupedMaps;

//special return

typedef struct placementResponce {
    bool valid;
    int score;
} placementResponce;

#endif