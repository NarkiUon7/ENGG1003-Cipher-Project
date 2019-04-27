#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//When it came to swapping the message input from hard coding to standard input, there are problems that i was unable to adress.//
//So the actual message to encrypt/decrypt is hard coded in, and the code used to encrypt/decrypt and the rotation key is still done from standard input.

// Any input required from this user is to be put in the input file and run using the runEncryption command.

//SO for the 'menu':
//Line 1 on the input file controls the menu, as in what option is selected.
//Line 2 controls the key for ROTATION CIPHERS (case 1 and 2), and  controls the substitution code for case 3 and 4.

//Case 5 is a day 1 provided piece of encrypted text so its hard coded in so i dont forget what the substitution code is.

//For case 3, CODE MUST BE IN CAPS to print the encrypted message in caps
//For case 4, CODE MUST BE IN LOWER CASE with text in upper case to print a message in upper case

//Begninning of function prototyping and definition. Becasue i am fairly new to coding, i found it easier to have the function prototype and definition in 
//The same place rather than the norm of having the prototype above the main code and the definition below the main code.

//Function to encrypt a message using a substitution cipher.
char* enigma_encrypt(char *message,char code[]){                                           
  int length = strlen(message);                                             //This line gets the length of the message 
  char *encrypted_message = (char *) malloc(sizeof(char)*length);           // Allocating space for encrypted message. 

  for(int i = 0; i < length; i++){
    int encryption_index = toupper(message[i]) - 'A';                    //Converts the message and code to upper case to eleminate lower case letters and obtains the encryption index.
    if(encryption_index >= 0 && encryption_index < 26){                  //Code in this if statement is exectued if the encryption index is betweeen 0 and 26  
      encrypted_message[i] = code[encryption_index];                     //THe unencrypted message/letter becomes whatever the corresponding to the code. Basically mapping characters to an array
    }else{
      encrypted_message[i] = message[i];                                 // If the value for the encryption index is anything less than 0 or equal to and greater than 26, the letter is left unencrypted.
      // This last line is for reading spcial characters and whitespaces as they have their own unique ASCII values that would be outside of the 0-26 range. hence they appear unencrypted.
    }
  }
  return encrypted_message;         //Once the function is complete, the encrypted message is the value that is returned.
}

//FUnction to find the index of a character. (used in decryption only)
//This function is bascially here to find what the character being decrypted is substituted for in the substitution code.
// The varaible that this is associated with is codeDecrypt found in the enigma_decrypt function.
int find_index(char codeDecrypt[],char char_to_find){
  for(int i = 0 ; i < 26; i ++){
    if(codeDecrypt[i] == char_to_find){
      return i;
    }
  }
  return -1;
}

//FUnction to decrypt a message that has been encryped using a substitution cipher.
char *enigma_decrypt(char *message,char codeDecrypt[]){                  //Function prototype with name decrypt, char datatypes for the message
  int length = strlen(message);                                          //This line gets the length of the message 
  char *decrypted_message = (char *) malloc(sizeof(char)*length);        // Allocating space for decrypted message.     
  for(int i = 0; i <length; i++){
    int decryption_index = toupper(message[i]) - 'A';                    //Converts the message and code to upper case to eleminate lower case letters and obtains the decryption index.
    if(decryption_index >= 0 && decryption_index < 26){                  //Code in this if statement is exectued if the decryption index is betweeen 0 and 26 
      int code_index = find_index(codeDecrypt,tolower(message[i]));      //Takes the characer found from the subtitution code that is equivalant to the letter being decrypted. e.g. Encrypted A = unencrypted J
      decrypted_message[i] = 'A' + code_index;                          //THe unencrypted message/letter becomes whatever the corresponding to the code by adding the code index which is a number between 0 and 25 to the ASCII value of A
      }else{
          decrypted_message[i] = message[i];                            // If the value for the encryption index is anything less than 0 or equal to and greater than 26, the letter is left unencrypted.
      // This last line is for reading spcial characters and whitespaces as they have their own unique ASCII values that would be outside of the 0-26 range. hence they appear unencrypted.
    }
  }
  return decrypted_message;         //Once the function is complete, the decrypted message is the value that is returned.
}

//Beginning of main body of code
int main()
{
   int n ;              //int n controls the menu selection for the below printf options.               
   int key;             //int key represents the rotation key that is used to encrypt and decrypt rotation ciphers 
                        //int key is outside the swtich case because che gave a redefinition error if it was used in 2 cases. 
                        
                        
   //Below is a 'menu' system, which is a series of printf statements that are the titles for each case. Each case handles a specific part of the assingment based on the value its corresponds to in each printf statemnt.
   //Any other value outside of the 5 that are shown below, e.g.  7, the code will print please make a valid selection.
   
   printf("Please enter a valid Selection: \n");
   
   printf("1. Encryption using a Caesar Cipher\n");
   
   printf("2. Decryption using a Caesar Cipher (rotation key known or unknown)\n");
   
   printf("3. Encryption using a substitution Cipher\n");
   
   printf("4. Decryption using a substitution Cipher (substitutions are known or unknown)\n");
   
   printf("5. Decryption of a day 1 provided text piece encrypted with a substitution Cipher (rotation key unknown )\n");
   
     
   scanf("%d", &n);     //Reads the selection of n for the above options from input file.
   
   //Menu system is controlled by a switch case where each of the above printf statements has code associated with it.
 
   switch (n)
   {
    case 1: printf("Encryption using a Caesar Cipher\n");
    
	
	char message_encrypt[1000] = "hello there its me";     
	// Message_encrypt to be encrypted. THe value 1000 is jsut to give a string length of 1000 characters so that large 
    //Large bodies of text can be encrypted without exeeding the string limit, which would cause the code to fail.
                                                            
	
	printf("Enter key: ");          // this requests user input for the key that they want to use to encrypt messages.
	scanf("%d", &key);             // reads the inputed key from line 2 of the input file.
	
	// The below for loop executes various code for upper and lower case letters startig at the first letter, i = 0. Once the code is executed, i is incrememted by 1 to the next letter and the code is tested again.
	// Once there are no more letters to test (the end of the string has been reached), the code terminates. This is due to the condition in the for loop. As long as there are values to test. THis code will keep running/
	//the '\0' in the condition is equivilant to null. THat is, there is no value to be tested
	
		for( int i = 0; message_encrypt[i] != '\0'; i++) {                          // for loop sets up the testing conditions for the string being tested starting at the first character. 
	    if (message_encrypt[i] >= 'A' && message_encrypt[i] <= 'Z'){                // if statement for the values being tested between the ASCII values for upper case A and upper case Z
	        message_encrypt[i] = (message_encrypt[i] - 'A' + key) %26 + 'A';        // the letter being encryped plus the key gives the encrypted letter.
	    }  
	    
	// For the assingment, the above loop is necessary to deal with upper case letters. For lower case letters, the ASCII values in green are simply replaces with the lower case versions. 
	// The if statement below is the same as the if statement above
	    
	   if (message_encrypt[i] >= 'a' && message_encrypt[i] <= 'z') {
	       message_encrypt[i] = (message_encrypt[i] - 'a' + key) %26 + 'a';
	   }
	}
	
	printf("Encrypted message: %s", message_encrypt);       // THe encrypted message is the printed to the machine using the runEncryption command.
   
        break;      // Case has ended at this point so the code ends here at the break statement.
        
        
    case 2: printf("Decryption using a Caesar Cipher (rotation key known or unknown)\n"); 
    
    char message_decrypt[1000] = "khoor wkhuh lwv ph";       
    //Message_decrypt that is to be decrypted. it is a string with a length of 1000 so as to well exceed the length of any possible text that could be given to endocde/decode.
    //If the length of a message exceeds the string length, the code will fail. IF this happens, simply increase the vaule located in [] to a larger value.
                
	printf("Enter key: ");
	scanf("%d", &key);
	
	// The below for loop executes various code for upper and lower case letters startig at the first letter, i = 0. Once the code is executed, i is incrememted by 1 to the next letter and the code is tested again.
	// Once there are no more letters to test (the end of the string has been reached), the code terminates. This is due to the condition in the for loop. As long as there are values to test. THis code will keep running/
	//the '\0' in the condition is equivilant to null. THat is, there is no value to be tested
	
		for( int i = 0; message_decrypt[i] != '\0'; i++) {                          // for loop sets up the testing conditions for the string being tested starting at the first character.             
	    if (message_decrypt[i] >= 'A' && message_decrypt[i] <= 'Z'){                // if statement for the values being tested between the ASCII values for upper case A and upper case Z
	        message_decrypt[i] = (message_decrypt[i] - 'A' - key) %26 + 'A';        // the encrypted letter minus the key gives the decoded letter.
	    } 
	    
	// For the assingment, the above loop is necessary to deal with upper case letters. For lower case letters, the ASCII values in green are simply replaces with the lower case versions. 
	// The if statement below is the same as the if statement above.
	   if (message_decrypt[i] >= 'a' && message_decrypt[i] <= 'z') {
	       message_decrypt[i] = (message_decrypt[i] - 'a' - key) %26 + 'a';
	   }
	}
	
	printf("Decrypted message: %s", message_decrypt);          // The decrypted message is printed to the machine using the run Encryption command.         
       
    
        break;      // Case has ended at this point so the code ends here at the break statement.
        
        
    case 3: printf("Encryption using a substitution Cipher \n");
    
    char *message = " TEST MESSAGE";            //This is the message to be encrypted set up as a string of ASCII values. The text must me in upper case
    char code[26];                              //this variable represents the substitution code.  
    
    //For substitution ciphers. A letter of the alphabet is replaced or substituted with antoher. In coding, this can be represented numerically using ASCII values.
    // THis code opperates on the assumption that the substitution cipher is a monoalphabetic substitution cipher as opposed to a polyalphabetic substitutino cipher.
    
    printf("Enter Substitution code:  ");       //This printf statemnt requests the user to input a substitution code    
    scanf("%s", &code);                         //Using scanf, so long as there are no spaces in the substitution code being inputed the code will work.
    
    //Other alternatives to avoid using scanf could be to use fscanf and read the substitution code from a file. From testing using scanf, as long as there are no spaces the use of scanf is fine.

    char *encrypted_message = enigma_encrypt(message,code);                                            // This line calls the function titled 'encrypt' to ercrypt the message using the substitution code that is provided
    printf("Original Message: %s\nEncrypted Message: %s\n",message,encrypted_message);          // Prints the original message and the encrypted message to the machine using the runEncryption command. 
      
        break;      // Case has ended at this point so the code ends here at the break statement.
        
        
    case 4: printf("Decryption using a substitution Cipher (substitutions are known)\n");
    
    char *Message_to_decrypt = "TSET MSEEAGS";                      //THis variable represents the message to be decoded. The text must be in upper case.
    printf("Encrypted Message: %s\n", Message_to_decrypt);          //THis line simply prints the message from the previous line to the machine.
    char Substitution_code[26];                                     //This variable respresents the substitution code the message is encrypted with.

    printf("Enter Substitution Code \n");                           //Asks for user input for substitution code 
    scanf("%s", &Substitution_code);                                //This line reads substitution code from input file and stores it as a string variable
    
    char *decrypted_message = enigma_decrypt(Message_to_decrypt,Substitution_code);            //THis line calls the function titled 'decrypt' to decrypt the message using the provided substitution code
    printf("Decrypted Message: %s\n",decrypted_message);                                //The decrypted message is printed to the machine using the runEncryption command.

        break;      // Case has ended at this point so the code ends here at the break statement.
        
        
    //The below case is a hard coded example of solving a substitution cipher. This uses a day one provided piece of text with the substitution code unknown. This is simply here to show that I have solved a day one provided piece of text.
    //Before solving a substitution cipher, it is best to perform statistical analysis on the text to try and identify common words to attepmt to identify some of the substitution code.
    //In this example there are 22 letters used, so the 4 remaining letters were guessed. 
    case 5: printf("Decryption of a day 1 provided block of cipher encrypted with a substitution cipher\n");
    
    
    char *Day_1_message = "N KBP JLCBKFCMCL FXEFH RYBJ KYF FXCEOIH WV LYKGCKLCKQ CFJ YIIYKBKFJ NKR ONACKQ FHBO JBB FHB ZCQHF, WEF XNFHBX WBLNEJB CFJ YIIYKBKFJ BGBKFENZZV RCB, NKR N KBP QBKBXNFCYK QXYPJ EI FHNF CJ MNOCZCNX PCFH CF. - ONU IZNKLA \n";
    printf("Encrypted Message: %s\n", Day_1_message);
    
    char Day_1_Substitution_code[26] = {'n','w','l','r','b','m','q','h','c','d','a','z','o','k','y','i','s','x','j','f','e','g','p','u','v','t'};

    char *Day_1_decrypted_message = enigma_decrypt(Day_1_message,Day_1_Substitution_code);
    printf("Decrypted Message: %s\n",Day_1_decrypted_message);
     
        break;
           
    default: printf("Please make Valid Selection");         //This is the default statement that is used atthe end of a switch case when a value that is not associated with a case is chosen, or no break statements are found.
    
    
} 
return 0;
}


//= {'B','A','C','D','S','F','G','H','I','J','K','L','M','N','O','P','Q','R','E','T','U','V','W','X','Y','Z'};









