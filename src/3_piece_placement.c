#include "h_functions.h"

static bool checkBounds(block map, block piece, int x, int y)
{
    if ((x + piece.dimen.width) > map.dimen.width)
        return false;
    if ((y + piece.dimen.height) > map.dimen.height)
        return false;
    return true;
}

placementResponce checkPlacement(block map, block piece, int x, int y)
{
    int yy;
    int xx;
    int p_index;
    int player;
    int score;
    int m_index;

    player = 0;
    score = 0;
    yy = -1;
    while(++yy < piece.dimen.height)
    {
        xx = -1;;
        while(++xx < piece.dimen.width)
        {
            p_index = POS(xx, yy, piece.dimen.width);
            m_index = POS(x + xx, y + yy, map.dimen.width);
            if (piece.body[p_index] == '*')
            {
                if (map.body[m_index] == ENEMY)
                    return (placementResponce){.valid = false, .score = 0};
                if (map.body[m_index] == PLAYER)
                    player++;
                score += map.body[m_index];
            }
        }
    }
    if (player == 1)
        return (placementResponce){.valid = true, .score = score};
    return (placementResponce){.valid = false, .score = 0};
}

cordinate getBestCordinate(block map, block piece)
{
    int yy;
    int xx;
    int index;
    placementResponce responce;
    cordinate ret;
    int best;

    best = INT32_MAX;
    ret = (cordinate){0,0};
    yy = -1;
    while(++yy < map.dimen.height)
    {
        xx = -1;;
        while(++xx < map.dimen.width)
        {
            index = POS(xx, yy, map.dimen.width);
            if (checkBounds(map, piece, xx, yy))
            {
                responce = checkPlacement(map, piece, xx, yy);
                if (responce.valid && (best > responce.score))
                {
                    best = responce.score;
                    ret = (cordinate){xx, yy};
                }
            }
        }
    }
    return ret;
}
