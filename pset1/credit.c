int get_dlugosc(long long arg);
int polacz(int x, int y);
int zsumujcyfry(int arg);
void checker(long long arg);
void firma(long long arg);
long long number;
int cykl = 1;
int nparzyste;
int parzyste;
int parzysta;
int podsuma;
int numerpoprawny;
int checksum;
int dlugosc;
int final_checksum;


/* DO TESTÓW
378282246310005

TA WERSJA JEST PODUPCONA


*/

int main(void){
    printf("Number: ");
    number = get_long_long();
    dlugosc = get_dlugosc(number);
    checker(number);
    printf("final z gluwnej pentli- %i", final_checksum);
    if (checksum == 0) {
        firma(number);    
    }
    return 0;
}

/* FUNKCJE */

void checker(long long arg){
    while (arg != 0) {
        int cyfra = arg % 10;
        if (cykl % 2 == 0) {
            parzysta = cyfra * 2;
            if (parzysta > 9) {
                while (parzysta != 0) {
                    int guwno = parzysta % 10;
                    podsuma = podsuma + guwno;
                    parzysta /= 10;
                }
            } else {    }
            parzyste = parzyste + parzysta + podsuma;
        } else {
            nparzyste = nparzyste + cyfra;
        }
        arg /= 10;
        cykl += 1;
    }
    checksum = nparzyste + parzyste;
    /* int dlugosc_sumy = get_dlugosc(checksum); */
    /* Tutaj podaj mi ostatnią cyfrę z checksuma */\
    /* Jak zrobić żeby podał tylko jedną!!! */
    while(checksum != 0) {
        /* do something */
        int dlugosc_sumy = get_dlugosc(final_checksum);
        if (dlugosc_sumy == 0) {
            final_checksum = checksum % 10;
            printf("final z malej pentli - %i", final_checksum);            
        }
        checksum /= 10;
    }
}

int get_dlugosc(long long arg){
  int l=1;
  while(arg>9){ l++; arg/=10; }
  return l;
}

int zsumujcyfry(int arg) {
    int suma = 0;
    while (arg != 0) {
        int cyferka = arg % 10;
        suma = suma + cyferka;
        arg /=10;
    }
    return suma;
}

int polacz(int x, int y) {
    int pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

/* STARE FUNKCJE */

void firma(long long arg){
    int cyfra1;
    int cyfra2;
    cykl = 1;
    while (arg != 0) {
        /* do something */
        if (cykl == dlugosc - 1) {
            cyfra2 = arg % 10;
        }
        if (cykl == dlugosc) {
            cyfra1 = arg % 10;
        }
        cykl = cykl + 1;
        arg /= 10;
    }
    int kodfirmy = polacz(cyfra1, cyfra2);
    if (final_checksum == 0) {
          switch(kodfirmy) {
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
         }
        } else {
            printf("INVALID\n");
        }
}
