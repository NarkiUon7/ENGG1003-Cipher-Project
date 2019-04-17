#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Encryption code for Caesar Cipher
char Caesar_Encrypt( char ch, int i, int key) {
    char message [100], ch
    int i, key;

    for (i = 0; message[i] != '\0'; i ++ {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
         ch = ch + key%26;
            if ( ch > 'z') {
             ch = ch - 'z' + 'a' - 1;
         }
         message[i] = ch
      } else if (ch >= 'A' && ch <= 'Z' ) {
            ch = ch + key%26;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' -1;
            }
        } message[i] = ch
    }
return ch;
}

// Decryption code for Caesar Cipher

char Caesar_decryption(char ch, int i, int key) {
    char message[100], ch;
    int i, key;
    
    for(i = 0; message[i] != '\0'; ++ i) {
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key%26;
            if( ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
            
        } else if (ch >= 'A' && ch <= 'Z' ) {
            ch = ch - key%26;
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1; 
            }
        }
        message[i] = ch
    }
    return ch;
}

//find index of the character
int find_index(char code[], char char_to_find) {
    for(int i = 0; i < 26; i ++) {
        if(code[i] == char_to_find){
            return i;
        }
    }
    return -1;
}
// Encryption code for monoalphabetic substitution cipher

char encrypt(char message, char code []) {
    int length = strlen(message);
    char encrypted_message = (char *) malloc(sizeof(char)*length);
    
    for (int i = 0; i < length; i ++) {
        int encryption_index = tolower(message[i]) - 'a';
        if(encryption_index >= 0 && encryption_index < 26) {
            encrypted_message[i] = code[encryption_index];
        } else {
            encrypted_message[i] = message[i];
        }
    }
    return encrypted_message;
}

// Decryption code for monoalphabetic substitution cipher

char *decrypt(char *message, char code[]) {
    int length = strlen(message);
    char *decrypted_message = (char *) malloc(sizeof(char)*length);
    
    for (int i = 0; i < length; i ++) {
        int decryption_index = tolower(message[i]) - 'a'
        if(decryption_index >= 0 && decryption_index < 26) {
            int code_index = find_index(code, tolower(mesage[i]));
            decrypted_message = 'a' + code_index;
        } else {
            decrypted_message = message;
        }
    }
    return decrypted_message;
}