#include <stdio.h>
#include <cs50.h>

int h;
int get_height();
void piramid(int arg);

int main(void)
{
    printf("Wysokość: ");
    h = get_height();
    piramid(h);
}

int get_height()
{

    h = get_int();
    if (h < 0 || h > 23){
        printf("Wysokość: ");        
        h = get_height();
        return h;
    } if (h == 0) {
        return false;
    } else {
        return h;
    }
}

void piramid(int arg)
{
    int spacje = arg - 1;

    for (int i = 0; i < arg; i++){
        for (int j = 0; j < spacje; j++){
            printf(" ");
        }
        for (int k = 0; k <= i; k++){
            printf("#");
        }
        spacje--;
        printf("  ");
        for (int k = 0; k <= i; k++){
            printf("#");
        }
        printf("\n");
    }
}