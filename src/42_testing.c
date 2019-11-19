#include "h_functions.h"

//testing
void printPieceF(block p) {
    int hh = -1;

    fprintf(f, "%d %d\n", p.dimen.height, p.dimen.width);
    while (++hh < p.dimen.height) {
        fprintf(f, "%.*s\n", p.dimen.width, p.body + (hh * p.dimen.width));
    }
}

void printPiece(block p) {
    int hh = -1;

    printf("%d %d\n", p.dimen.height, p.dimen.width);
    while (++hh < p.dimen.height) {
        printf("%.*s\n", p.dimen.width, p.body + (hh * p.dimen.width));
    }
}

void printPieceHidden(block p) {
    int yy;
    int xx;
    int index;

    printf("%d %d\n", p.dimen.height, p.dimen.width);
    yy = -1;
    while(++yy < p.dimen.height)
    {
        xx = -1;;
        while(++xx < p.dimen.width)
        {
            index = POS(xx, yy, p.dimen.width);
            printf("%2d ", p.body[index]);
        }
        printf("\n");
    }
}

void printPieceHiddenF(block p) {
    int yy;
    int xx;
    int index;

    fprintf(f, "%d %d\n", p.dimen.height, p.dimen.width);
    yy = -1;
    while(++yy < p.dimen.height)
    {
        xx = -1;;
        while(++xx < p.dimen.width)
        {
            index = POS(xx, yy, p.dimen.width);
            fprintf(f, "%2d ", p.body[index]);
        }
        fprintf(f, "\n");
    }
}

void printPieceFD(int fd, block p) {
    int hh = -1;
    
    write(fd, ft_itoa(p.dimen.height), ft_strlen(ft_itoa(p.dimen.height)));
    write(fd, " ", 1);
    write(fd, ft_itoa(p.dimen.width), ft_strlen(ft_itoa(p.dimen.width)));
    write(fd, "\n", 1);
    while (++hh < p.dimen.height) {
        write(fd, p.body + (hh * p.dimen.width), p.dimen.width);
        write(fd, "\n", 1);
    }
}

void printQueue(queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("it's empty\n");
        return;
    }
    node *tmp = q->first;
    while(tmp)
    {
        printf("x: %d y: %d\n", tmp->cord.x, tmp->cord.y);
        tmp = tmp->next;
    }
}

void queTest()
{
    queue *q;

    q = initQueue();
    printQueue(q);
    addQueue(q, (cordinate){5, 7});
    addQueue(q, (cordinate){3, 4});
    addQueue(q, (cordinate){2, 5});
    addQueue(q, (cordinate){1, 6});
    printQueue(q);
    printf("------------\n");
    deQueue(q);
    deQueue(q);
    printQueue(q);
    printf("------------\n");
    deQueue(q);
    deQueue(q);
    printQueue(q);
    free(q);
}


//---------------------------------------------

void test(int fd, int times) {
    char *tmp;

    while(times--) {
        tmp = gnl(0);
        // fprintf(f, "%s\n", tmp);
        _puts(fd, tmp);
        _puts(fd, "\n");
    }
}

void test2(void)
{
    int fd = open("view", O_RDWR);
    test(fd, 21);
    _puts(1, "12 12\n");
    test(fd, 20);
    _puts(1, "12 11\n");
    test(fd, 20);
    _puts(1, "12 11\n");
}


//---------------------------------------------------
