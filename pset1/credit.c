#include <stdio.h>
#include <cs50.h>

long long wez_numer();
int czy_zero_na_koncu(int arg);
int polacz_dwie(int x, int y);
int wez_dlugosc(long long arg);
int wez_dwie_pierwsze(long long arg);
int wez_sume(long long arg);
void daj_firme();

/* GŁÓWNA */

int main(void){
    long long numer = wez_numer();
    int suma = wez_sume(numer);
    /* printf("main - suma: %i\n", suma); */
    int zero_na_koncu = czy_zero_na_koncu(suma);
    /* printf("main - zero na koncu Y/N: %i\n", zero_na_koncu); */
    int dwie_pierwsze = wez_dwie_pierwsze(numer);
    /* printf("main - dwie pierwsze: %i\n", dwie_pierwsze); */
    if (zero_na_koncu == 1) {
        daj_firme(dwie_pierwsze);
    } else {
        printf("INVALID\n");
    }
}

/* FUNKCJE */

void daj_firme(int arg){
    switch(arg) {
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            printf("VISA\n");
            break;        
        case 34:
        case 37:
            printf("AMEX\n");
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            printf("MASTER\n");
            break;
        default:
            printf("INVALID\n");
            break;
    }
}

int wez_dwie_pierwsze(long long arg){
    int numer_dlugosc = wez_dlugosc(arg);
    int cyfra1 = 0;
    int cyfra2 = 0;
    int cykl = 1;
    while (arg != 0) {
        /* do something */
        if (cykl == numer_dlugosc - 2) {
            cyfra2 = arg % 10;
        }
        if (cykl == numer_dlugosc - 1) {
            cyfra1 = arg % 10;
        }
        cykl = cykl + 1;
        arg /= 10;
    }
    int kodfirmy = polacz_dwie(cyfra1, cyfra2);
    return kodfirmy;
}

int polacz_dwie(int x, int y) {
    int pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

int czy_zero_na_koncu(int arg){
    int zarowka = 0;
    int zerowka = 0;
    while(arg != 0) {
        /* do something */
        int cyfra = arg % 10;
        if (cyfra == 0 && zarowka == 0) {
            zerowka = 1;
        }
        zarowka = 1;
        arg /= 10;
    } 
    return zerowka;
}

int wez_sume(long long arg){
    int cykl = 1;
    int nparzyste = 0; 
    int parzyste = 0;
    while (arg != 0) {
        /* Machinacje co iteracje */
        int cyfra = arg % 10;
        if (cykl % 2 == 0) {
            /* Jeśli co druga, parzysta */
            int parzysta = cyfra * 2;
            int podsuma = 0;
            int guwno;
            if (parzysta > 9) {
                while (parzysta != 0) {
                    guwno = parzysta % 10;
                    podsuma = podsuma + guwno;
                    parzysta /= 10;
                }
            }            
            parzyste = parzyste + parzysta + podsuma;
            /* printf("wez_sume - parzysta, cykl: %i, cyfra: %i\n", cykl, cyfra); */
        } else {
            /* Jeśli co pierwsza, nparzysta - DONE */
            nparzyste = nparzyste + cyfra;            
            /* printf("wez_sume - nparzyste: %i, cykl: %i, cyfra: %i\n", nparzyste, cykl, cyfra); */
        }
        /* Techniczne dla iterowania przez arg */
        arg /= 10;
        cykl += 1;
    };
    int rezultat = nparzyste + parzyste;
    /* printf("nparzyste: %i, parzyste: %i, ich suma: %i\n", nparzyste, parzyste, nparzyste + parzyste); */
    return rezultat;
};

int wez_dlugosc(long long arg){
    int l=1;
    while (arg != 0) {
        l++;
        arg/=10;
    };
    return l;
};

long long wez_numer(void){
    printf("Number: ");
    long long arg = get_long_long();
    return arg;
};
