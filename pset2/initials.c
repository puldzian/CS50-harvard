#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void wez_inicjal(string arg);

int main(void){
    string name = get_string();
    wez_inicjal(name);
}

void wez_inicjal(string arg){
    char poprzednia;
    for (int i = 0; i < strlen(arg); i++){
        // Jeśli jest pierwsza i nie jest spacją - dodaj do inicjałów
        if (i == 0 && arg[i] != 32) {
            printf("%c", toupper(arg[i]));
            
        } 
        if (arg[i] != 32 && poprzednia == 32) {
            printf("%c", toupper(arg[i]));
        }
        poprzednia = arg[i];
    }
    printf("\n");
}
