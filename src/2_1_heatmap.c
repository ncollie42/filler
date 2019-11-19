#include "h_functions.h"

void initQueFromMap(block map, queue *Q1, block visited, players p)
{
    int yy;
    int xx;
    int index;

    yy = -1;
    while(++yy < map.dimen.height)
    {
        xx = -1;;
        while(++xx < map.dimen.width)
        {
            index = POS(xx, yy, map.dimen.width);
            if (map.body[index] != '.')
            { 
                if (ft_tolower(map.body[index]) == p.enemy)
                {
                    addQueue(Q1, (cordinate){xx, yy});
                    map.body[index] = ENEMY;
                } else 
                    map.body[index] = PLAYER;
                visited.body[index] = true;
            }
        }
    }
}

static bool checkBounds(cordinate cord, dimentions dimen)
{
    if (cord.x < 0)
        return false;
    if (cord.x >= dimen.width)
        return false;
    if (cord.y < 0)
        return false;
    if (cord.y >= dimen.height)
        return false;
    return true;
}

void setPoint(groupedMaps maps, cordinate cord, queue *Q, int level)
{
    int index;

    index = POS(cord.x, cord.y, maps.map.dimen.width);
    if (checkBounds(cord, maps.map.dimen) && !maps.visited.body[index])
    {
        maps.visited.body[index] = true;
        maps.map.body[index] = level;
        addQueue(Q, cord);
    }
}

void surrounding(groupedMaps maps, cordinate cord, queue *Q, int level)
{
    setPoint(maps, (cordinate){cord.x - 1, cord.y}, Q, level);
    setPoint(maps, (cordinate){cord.x - 1, cord.y + 1}, Q, level);
    setPoint(maps, (cordinate){cord.x - 1, cord.y - 1}, Q, level);
    setPoint(maps, (cordinate){cord.x, cord.y + 1}, Q, level);
    setPoint(maps, (cordinate){cord.x, cord.y - 1}, Q, level);
    setPoint(maps, (cordinate){cord.x + 1, cord.y}, Q, level);
    setPoint(maps, (cordinate){cord.x + 1, cord.y + 1}, Q, level);
    setPoint(maps, (cordinate){cord.x + 1, cord.y - 1}, Q, level);
}

void BFS_HeatMap(groupedMaps maps, queue *Q1, queue *Q2, int level)
{
    cordinate cords;

    while (!isQueueEmpty(Q1))
    {
        cords = deQueue(Q1);
        surrounding(maps, cords, Q2, level);
    }
    if (isQueueEmpty(Q2))
        return;
    BFS_HeatMap(maps, Q2, Q1, level + 1);
}

