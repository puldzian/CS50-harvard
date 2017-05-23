#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Wie viele Minuten duschst du: ");
    int min = get_int();
    printf("Minuten: %i\n", min);
    printf("Liter: %i\n", min * 12);
}