#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char Caesar_Encrypt( char ch, int i, int key);

char Caesar_Decryption (char ch, int i, int key)


int main() {
    int input;
    
    printf(" Please make a selection \n");
    printf(" 1. Encrypt a message using a Caesar Cipher \n");
    printf(" 2. Decrypt a message using a Caesar Cipher \n");
    printf(" Selection \n");
    scanf ("%d", &input);
    
    switch (input) {                                            // As fucntions are creadted, add extra switch cases 
         case 1 (input = 1):  
            printf(" Enter a message to encrypt. ");            // User input for the message that they want to encrypt, 
            fgets(message, sizeof(message), stdin);             // fgets(message); // Takes input from user and stores it in a string variable.
            printf(" Enter an Encryption key.");                // User input for encryption key
            scanf("%d", &key);                                  // standard input holding the value for key tha the user wants under the variable 'key'
            
            Caesar_Encrypt( char ch, int i, int key);  
            printf("Encrypted Message: %s", message); 
                break;
         case 2 (input = 2);
            printf("Enter a message to decrypt: \n"); 
            fgets(message, sizeof(message), stdin);   
            printf("Enter a decryption key:  \n");     
            scanf("%d", &key);       
         
            Caesar_Decryption( char ch, int i, int key);
            printf("Decrypted message %s", message);
                break;
        case 3 (input = 3);
             char *message = " Test message";
             char code[26] = {'b', 'a', 'c', 'd', 's', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 'e', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
             
             char *encrypted_message = encrypt(message, code);
             printf(" Original Message: %s\nEncrypted Message: %/s\n", message, encrypted_message);
             break;
        case 4 (input = 4);
             char *message = " Test message";
             char code[26] = {'b', 'a', 'c', 'd', 's', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 'e', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
             
             char *decrypted_message = decrypt(encrypted_message, code)
             printf(" Original Message: %s\nDecrypted Message: %s\n", message, decrypted_message);
             break;
                
         default: printf("Please Make Valid Selection")
        }
 }
//End of Code
//Begninning of Function Definitions
//With function definitions give fuctions an appropriate name, making sure to comment them well.

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

char *encrypt(char *message, char code []) {
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
  












