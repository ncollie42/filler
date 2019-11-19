#include "h_functions.h"

block updatePiece(block piece, dimentions newDimen)
{
    int yy;
    block new;
    int offset;

    offset = 0;
    new = newBlock(newDimen);
    yy = -1;
    while(++yy < piece.dimen.height)
    {
        ft_memmove(new.body + offset, piece.body + (yy * piece.dimen.width), newDimen.width);
        offset += newDimen.width;
    }
    free(piece.body);
    fprintf(f, "new: \n");
    printPieceF(new);
    return new;
}


block trimPiece(block piece)
{
    int yy;
    int xx;
    int index;
    dimentions newDimen;
    fprintf(f, "---------------------------------------\n");
    fprintf(f, "before: %d %d\n", piece.dimen.height, piece.dimen.width);
    newDimen = (dimentions){0,0};
    yy = -1;
    while(++yy < piece.dimen.height)
    {
        xx = -1;;
        while(++xx < piece.dimen.width)
        {
            index = POS(xx, yy, piece.dimen.width);
            if (piece.body[index] == '*')
            {
                if (xx + 1 > newDimen.width)
                    newDimen.width = xx + 1;
                if (yy + 1 > newDimen.height)
                    newDimen.height = yy + 1;
            }
        }
    }
    fprintf(f, "after: %d %d\n", newDimen.height, newDimen.width);
    if (piece.dimen.width != newDimen.width || piece.dimen.height != newDimen.height)
        piece = updatePiece(piece, newDimen);
    return piece;

}


