#include <stdio.h>
#include <math.h>

int main() {
    
    char message [100], ch; // assinging a char data type with  length 100. This will be the text that is encrypted. 
                            // ch is just the variable name and can be changed at anytime
    int i, key; // this is the encryption key, the "number of steps left", that the cipher uses. FOr example, a key of 5 will make
                //a = e, b = f, c = g, e.t.c
                // i and key are the int values repressenting the letter bring tested and the encryption key respectively
    
        printf(" Enter a message to encrypt. ");            //User input for the message that they want to encrypt, 
        fgets(message, sizeof(message), stdin);                                        //gets(message);                                      // Takes input from user and stores it in a string variable.
        printf(" Enter an Encryption key.");              // User input for encryption key
        scanf("%d", &key);                                  // standard input holding the value for key tha the user wants under the variable 'key'.

                
            for(i = 0; message[i]!='\0'; i++) {           // loop to execute the encryption commands for eact letter of text that the user imputs
                ch = message[i];
                    if (ch >= 'a'&& ch <= 'z') {            // 'a' and 'z' are representitve of the ASCII values of lower case a and z. if the vale for ch is between those two values, 
                        ch = ch + key;                      // then ch becomes ch plus whatever the encryption key is. These if statements are for testing and enctrypting if the letter 
                            if(ch > 'z'){                   // is a lower case letter. THis is because the ASCII values for Upper and Lower case letters are different 
                                ch = ch - 'z' + 'a' - 1;    // NEED TO INVESTIGATE WHAT THIS LINE DOES
                            }
                            message[i] = ch;                 // stores the encrypted letter forces loop to go to next letter
            } else if (ch >= 'A' && ch <= 'Z'){             // Same if statements as above but this time testing for 
                ch = ch + key;
                    if (ch >'Z') {
                        ch = ch - 'Z' + 'A' -1;             // NEED TO INVESTIGATE WHAT THIS LINE DOES
                            }
                    }
                message[i] = ch ;                     // stores the encrypted letter forces loop to go to next letter  
            } 

    printf("Encrypted Message: %s", message);            // Displays the encrypted message for the user
   

    
    return 0;
}