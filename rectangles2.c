#include <stdio.h>
#include <stdbool.h>

bool is_in_rect(int x, int y, int lx, int ty, int rx, int by)
{
return(x >= lx && x <= rx && y >= ty && y<= by);
}

int main(int argc, char **argv)
{
    int lx1 = 2;
    int rx1 = 6;
    int ty1 = 2;
    int by1 = 5;
    int lx2 = 4;
    int rx2 = 8;
    int ty2 = 3;
    int by2 = 7;
int width = 10;
int height = 10;

for(int y=0; y<height; y++) {
    for(int x=0; x<width; x++) {
       if (is_in_rect(x, y, lx1, ty1, rx1, by1) !=
           is_in_rect(x, y, lx2, ty2, rx2, by2)) 
            {
           printf("*");
       } else {
           printf(".");
       }
    }
    printf("\n");
}

    return 0;
}