#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string obniz(string arg);
int szyfruj(int let, int key);

int main(int argc, char* argv[]){
    string k;

    if (argv[1] == NULL) {
        printf("DOES NOT COMPUTE\n");
        return 1;        
    }
    int klen = strlen(argv[1]);    
    if (argc > 2 || argc < 2) {
        printf("DOES NOT COMPUTE\n");
        return 1;
    } else {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) {
            if (!isalpha(argv[1][i])){
                printf("DOES NOT COMPUTE\n");
                return 1;                
            }
        }
        k = argv[1];
        k = obniz(k);
    }
    //printf("keycode: %s, len: %i\n", k, klen);
    int iarg[klen];
    for (int i = 0; i < klen; i++) {
        iarg[i] = k[i] - 97;
    }
    
    /*printf("cipher: ");
    for (int i = 0, n = klen; i < n; i++) {
        printf("%i ", iarg[i]);
    }
    printf("\n");
    */
    
    // TUTAJ ZACZYNA SIĘ AKCJA
    printf("plaintext:  ");
    string plain = get_string();
    printf("ciphertext: ");
    // Tutaj wchodzi pętla przez plain
    int cykl = 0;
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        // Zostaw same literki
        if (isalpha(plain[i])) {
            int chuj = szyfruj(plain[i], iarg[cykl]);
            printf("%c", chuj);
            
            cykl = cykl + 1;
            if (cykl == klen){
                cykl = 0;
            }
        } else {
            printf("%c", plain[i]);
        }
    }   
    
    printf("\n");
    return 0;
}

// DOTYKAJ
int szyfruj(int let, int key){
    int niska = islower(let);
    let = let + key;
    if (niska != 0) {
        if (let > 122) {
            let = let - 26;
        }
    } else {
        if (let > 90) {
            let = let - 26;
        }
    }
    return let;   
}

// NIE DOTYKAJ 
string obniz(string arg) {
    for (int i = 0, n = strlen(arg); i < n; i++){
        arg[i] = tolower(arg[i]);
    }
    return arg;
};
