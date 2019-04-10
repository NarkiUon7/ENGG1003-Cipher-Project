
//  char message [100], ch;                             // assinging a char data type with  length 100. This will be the text that is encrypted. 
                                                                // ch is just the variable name and can be changed at anytime
            //int i, key;                                         // this is the encryption key, the "number of steps left", that the cipher uses. FOr example, a key of 5 will make
                                                                //a = e, b = f, c = g, e.t.c
                                                                // i and key are the int values repressenting the letter bring tested and the encryption key respectively
    
             //printf(" Enter a message to encrypt. ");            //User input for the message that they want to encrypt, 
             //fgets(message, sizeof(message), stdin);                                        //gets(message); // Takes input from user and stores it in a string variable.
             //printf(" Enter an Encryption key.");              // User input for encryption key
             //scanf("%d", &key);                                  // standard input holding the value for key tha the user wants under the variable 'key'.

                
             //for(i = 0; message[i]!='\0'; i++) {           // loop to execute the encryption commands for eact letter of text that the user imputs
                   // ch = message[i];
                     //if (ch >= 'a'&& ch <= 'z') {            // 'a' and 'z' are representitve of the ASCII values of lower case a and z. if the vale for ch is between those two values, 
                           // ch = ch + key;                      // then ch becomes ch plus whatever the encryption key is. These if statements are for testing and enctrypting if the letter 
                               /// if(ch > 'z'){                   // is a lower case letter. THis is because the ASCII values for Upper and Lower case letters are different 
                                // ch = ch - 'z' + 'a' - 1;    // NEED TO INVESTIGATE WHAT THIS LINE DOES
                            // }
                           // message[i] = ch;                // stores the encrypted letter forces loop to go to next letter
                    //} else if (ch >= 'A' && ch <= 'Z'){             // Same if statements as above but this time testing for 
                         //ch = ch + key;
                         //if (ch >'Z') {
                            // ch = ch - 'Z' + 'A' -1;             // NEED TO INVESTIGATE WHAT THIS LINE DOES
                           // }
                   // }
                        // message[i] = ch ;                           // stores the encrypted letter forces loop to go to next letter  
          //  } 

                    //printf("Encrypted Message: %s", message);    
//int main(void)
//{
  //  printf("hello, world\n");
//}

//Decryption of CAesar cipher

//char message[100], ch;  // assinging a char data type with  length 100. This will be the text that is encrypted. 
                            // ch is just the variable name and can be changed at anytime
//    int i, key;             // // this is the encryption key, the "number of steps left", that the cipher uses. FOr example, a key of 5 will make
                            //a = e, b = f, c = g, e.t.c
                            // i and key are the int values repressenting the letter bring tested and the encryption key respective
    
   // printf("Enter a message to decrypt: \n"); // user input for message to be decrypted
    //fgets(message, sizeof(message), stdin);   // 
    //printf("Enter a decryption key:  \n");    // user input for a decryption key 
    //scanf("%d", &key);                        // standard input holding the value for key that the user wants under the variable 'key'.  
    
    
    
    //for(i = 0; message[i]!='\0'; ++i ) {      //loop to execute the decryption commands for each letter of text that the user imputs.  
      //  ch = message[i];                         //'a' and 'z' are representitve of the ASCII values of lower case a and z. if the vale for ch is between those two values, 
      //  if(ch>='a' && ch <= 'z') {
      //      ch = ch - key;                    // Reverse of encryption, the enoded letter ascii value minus the key give the decrypted letter
          //  if(ch < 'a'){                     // if the ascii value exceeds 'a', the the below code is executed to 'loop' back to ascii values that are between 'a' and 'z'. 
             //   ch = ch + 'z' - 'a' + 1;
          //  }
           // message[i] = ch;                  // if above code is executed, the letter is stored in the string and the code moves on to the next letter  
        
     // } else if (ch >= 'A' && ch <= 'Z') {    // if the above code is not executed, i.e. the letter is a capital letter, then the below code is exectued.
           // ch = ch - key;                    // this block of code is the same as the code for the lower case, with the exeption of sing the upper case ASCII values for each letter
          //  if (ch < 'A'){
          //     ch = ch + 'Z' - 'A' + 1;
      //  }
      //  message[i] = ch ;                     // decrypted letter "ASCII value" is stored in the string and the code moves on to the next value.
  //  }
//}

//printf("Decrypted message %s", message);      // Decrypted message is displyed for the user.

//return 0;