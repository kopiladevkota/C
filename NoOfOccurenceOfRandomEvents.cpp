#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Arand() {
    return 1 + rand() % 5;
}

int Brand() {
    return 1 + rand() % 5;
}

int main() {
    srand(time(0)); 
    
    int sa = 0, sb = 0, a, b, x, y;
    a = Arand();
    b = Arand();
    sa = a + b;
    
    x = Brand();
    y = Brand();
    sb = x + y;
    
    if (sa > sb)
        printf("A wins the game by %d points\n", sa);
    else if (sb > sa)
        printf("B wins the game by %d points\n", sb);
    else
        printf("The game is a draw with %d points each\n", sa);
    
    return 0;
}
