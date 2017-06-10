#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kluczuj (int key);
int szyfruj(int key, int let);

int main(int argc, char* argv[]){
    int k;
    if (argc > 2 || argc < 2) {
        printf("DOES NOT COMPUTE\n");
        return 1;
    } else {
        k = atoi(argv[1]);
    }
    k = kluczuj(k);
    
    printf("plaintext:  ");
    string plain = get_string();
    printf("ciphertext: ");
    
    // Tutaj wchodzi pętla przez plain
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        // Zostaw same literki
        if (isalpha(plain[i])) {
            int chuj = szyfruj(k, plain[i]);
            printf("%c", chuj);
        } else {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}

// To się powtarza przy każdej literce
int szyfruj (int key, int let) {
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

// To się uruchamia tylko raz
int kluczuj (int key) {
    if (key > 26) {
        key = key % 26;
    }
    return key;
}
