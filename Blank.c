#include <stdio.h>
#include <math.h>


int main() {
    
    char message [100], ch; // assinging a char data type with ... to limit the string. This will be the text that is encrypted
    int i, key; // this is the encryption key, the "number of steps left", that the cipher uses. FOr example, a key of 5 will make
                //a = e, b = f, c = g, e.t.c
    
        printf(" Enter a message to encrypt. ");    //User input for the message that they want to encrypt, 
        gets(message);                              // Takes input from user and stores it in a string variable.
        printf(" Enter an Encryption key.  ");      // user input for encryption key
        scanf("%d", &key);                          // standard input holding the value for key tha thte user wants.

                
            for(i = 0; message[i]! = '\0'; i++) {   // loop to execute the encryption commands for eact letter of text that the user imputs
                ch = message[i];
                    if (ch >= 'a'&& ch <= 'z') {    // 'a' and 'z' are representitve of the ASCII values of 
                        ch = ch + key;
                            if(ch > 'z'){
                                ch = ch - 'z' + 'a' - 1;
                            }
                            message[i] = ch
                    }
            } else if (ch >= 'A' && ch <= 'Z'){
                ch = ch + key;
                    if (ch >'Z') {
                        ch = ch - 'Z' + 'A' -1;
                    }
                message[i] = ch    
            } 

    printf(" Encrypted Message: %s", message)
    printf("Let the Games Begin :) \n");

    
    return 0;
}