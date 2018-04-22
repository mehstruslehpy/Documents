#include "Shapes.h"
void fillVert(double x_1, double y_1, double y_2)
{
    double count = (y_2>y_1)?(y_2-y_1):(y_1-y_2);
    double start = (y_2>y_1)?(y_1):(y_2);

    for (double i = 0; i <= count; i++)
    {
        if (checkPoint(x_1,start+i))
        {
            move(start+i, x_1);
            addch('0');
        }
    }
    return;
}

void fillLine(double x_1, double x_2, double y_1, double m)
{
    double count = (x_2>x_1)?(x_2-x_1):(x_1-x_2);
    double start = (x_2>x_1)?(x_1):(x_2);
    double y = 0;

    //horizontal fill
    for (double i = 0; i <= count; i++)
    {
        y = m*(start+i - x_1)+y_1;
        if (checkPoint(start+i,y))
        {
            move(y, start+i);
            addch('0');
        }
    }

    //vertical fill
    //double x = 0;
    //double y_2 = m*(x_2-x_1)+y_1;
    //count = (y_2>y_1)?(y_2-x_1):(y_1-y_2);
    //start = (y_2>y_1)?(y_1):(y_2);
    //for (double i = 0; i <= count; i++)
    //{
    //    x = floor((start+i-y_1)/m + x_1);
    //    //x = (start+i-y_1)/m + x_1;
    //    if (checkPoint(x,start+i))
    //    {
    //        move(start+i,x);
    //        addch('0');
    //    }
    //}
    //
    //return;
}

void drawLSeg(double x_1, double y_1, double x_2, double y_2)
{
    double m  = (y_2-y_1)/(x_2-x_1);


    //if (checkPoint(x_1,y_1))
    //{
    //    move(y_1,x_1);
    //    addch('0');
    //}
    //
    //if (checkPoint(x_2,y_2))
    //{
    //    move(y_2,x_2);
    //    addch('0');
    //}

    drawSinglePoint(x_1,y_1);
    drawSinglePoint(x_2,y_2);

    if((x_2-x_1) == 0)
    {
        fillVert(x_1,y_1,y_2);
        return;
    }
    else
    {
        fillLine(x_1,x_2,y_1,m);
        return;
    }
}

//these might be useful later
/*
double sgn(double x)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
void swap(double *x, double *y)
{
    double temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

*/

