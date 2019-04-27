#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//When it came to swapping the message input from hard coding to standard input, there are problems that i was unable to adress.//
//So the actual message to encrypt/decrypt is hard coded in, and the code used to encrypt/decrypt and the rotation key is still done from standard input.
// SO for the 'menu':
// Line 1 on the input file controls the menu, as in what option is selected.
//Line 2 controls the key for ROTATION CIPHERS (case 1 and 2), and  controls the substitution code for case 3 and 4.

// Case 5 is a day 1 provided piece of encrypted text so its hard coded in so i dont forget what the substitution code is.

//For case 3, CODE MUST BE IN CAPS to print the encrypted message in caps
// for case 4, CODE MUST BE IN LOWER CASE with text in upper case to print a message in upper case

//Begninning of function prototyping and definition. Becasue i am fairly new to coding, i found it easier to have the function prototype and definition in 
// the same place rather than the norm of having the prototype above the main code and the definition below the main code.

// Function to encrypt a message using a substitution cipher.
char* encrypt(char *message,char code[]){
  int length = strlen(message);
  char *encrypted_message = (char *) malloc(sizeof(char)*length);

  for(int i = 0; i < length; i++){
    int encryption_index = toupper(message[i]) - 'A';
    if(encryption_index >= 0 && encryption_index < 26){
      encrypted_message[i] = code[encryption_index];
    }else{
      encrypted_message[i] = message[i];
    }
  }
  return encrypted_message;
}

// FUnction to find the index of a character. (used in decryption only)
int find_index(char codeDecrypt[],char char_to_find){
  for(int i = 0 ; i < 26; i ++){
    if(codeDecrypt[i] == char_to_find){
      return i;
    }
  }
  return -1;
}

// FUnction to decrypt a message that has been encryped using a substitution cipher.
char *decrypt(char *message,char codeDecrypt[]){     //function prototype with name decrypt, char datatypes for the message
  int length = strlen(message);
  char *decrypted_message = (char *) malloc(sizeof(char)*length);
  for(int i = 0; i <length; i++){
    int decryption_index = toupper(message[i]) - 'A';
    if(decryption_index >= 0 && decryption_index < 26){
      int code_index = find_index(codeDecrypt,tolower(message[i]));
      decrypted_message[i] = 'A' + code_index;
    }else{
      decrypted_message[i] = message[i];
    }
  }
  return decrypted_message;
}

//Beginning of main body of code
int main()
{
   int n ;              // int n controls the menu selection for the below printf options.
               // char ch is the variable that is assinged the individual characters being tested in the message
   int key;             // int key represents the rotation key that is used to encrypt and decrypt rotation ciphers 
                  // int i represents  the individual string value that is being encrypted/decrypted
   printf("Please enter a valid Selection: \n");
   
   printf("1. Encryption using a Caesar Cipher\n");
   
   printf("2. Decryption using a Caesar Cipher (rotation key known or unknown)\n");
   
   printf("3. Encryption using a substitution Cipher\n");
   
   printf("4. Decryption using a substitution Cipher (substitutions are known or unknown)\n");
   
   printf("5. Decryption of a day 1 provided text piece encrypted with a substitution Cipher (rotation key unknown )\n");
   
     
   scanf("%d", &n);     //Reads the selection of n for the above options from input file.
   
   // menu system is controlled by a switch case where each of the above printf statements has code associated with it.
 
   switch (n)
   {
    case 1: printf("Encryption using a Caesar Cipher\n");
    
	
	char message_encrypt[1000] = "hello there its me";      //THis is the message to be encrypted. THe value 1000 is jsut to give a string length of 1000 characters so that large 
                                                            // large bodies of text can me encrypted without exeeding the string limit, which would cause the code to fail.
                                                            
	
	printf("Enter key: ");         // this requests user input for the key that they want to use to encrypt messages.
	scanf("%d", &key);             // reads the inputed key from line 2 of the input file.
	
		for( int i = 0; message_encrypt[i] != '\0'; i++) {
	    if (message_encrypt[i] >= 'A' && message_encrypt[i] <= 'Z'){
	        message_encrypt[i] = (message_encrypt[i] - 'A' + key) %26 + 'A';
	    }
	   if (message_encrypt[i] >= 'a' && message_encrypt[i] <= 'z') {
	       message_encrypt[i] = (message_encrypt[i] - 'a' + key) %26 + 'a';
	   }
	}
	
	printf("Encrypted message: %s", message_encrypt);
	
                
        break;
    case 2: printf("Decryption using a Caesar Cipher (rotation key known or unknown)\n"); 
    
    char message_decrypt[1000] = "khoor wkhuh lwv ph";

	printf("Enter key: ");
	scanf("%d", &key);
	
		for( int i = 0; message_decrypt[i] != '\0'; i++) {
	    if (message_decrypt[i] >= 'A' && message_decrypt[i] <= 'Z'){
	        message_decrypt[i] = (message_decrypt[i] - 'A' - key) %26 + 'A';
	    }
	   if (message_decrypt[i] >= 'a' && message_decrypt[i] <= 'z') {
	       message_decrypt[i] = (message_decrypt[i] - 'a' - key) %26 + 'a';
	   }
	}
	
	printf("Decrypted message: %s", message_decrypt);
       
    
        break;
        
    case 3: printf("Encryption using a substitution Cipher \n");
    
    char *message = " TEST MESSAGE";
    char code[26];
    
    printf("Enter Substitution code:  ");
    scanf("%s", &code);

    char *encrypted_message = encrypt(message,code);
    printf("Original Message: %s\nEncrypted Message: %s\n",message,encrypted_message);
      
        break;
    case 4: printf("Decryption using a substitution Cipher (substitutions are known)\n");
    
    char *Message_to_decrypt = "TSET MSEEAGS";
    printf("Encrypted Message: %s\n", Message_to_decrypt);
    char Substitution_code[26]; 

    printf("Enter Substitution Code \n");
    scanf("%s", &Substitution_code);
    
    char *decrypted_message = decrypt(Message_to_decrypt,Substitution_code);
    printf("Decrypted Message: %s\n",decrypted_message);

        break;
    case 5: printf("Decryption of a day 1 provided block of cipher encrypted with a substitution cipher\n");
    char *Day_1_message = "N KBP JLCBKFCMCL FXEFH RYBJ KYF FXCEOIH WV LYKGCKLCKQ CFJ YIIYKBKFJ NKR ONACKQ FHBO JBB FHB ZCQHF, WEF XNFHBX WBLNEJB CFJ YIIYKBKFJ BGBKFENZZV RCB, NKR N KBP QBKBXNFCYK QXYPJ EI FHNF CJ MNOCZCNX PCFH CF. - ONU IZNKLA \n";
    printf("Encrypted Message: %s\n", Day_1_message);
    
    char Day_1_Substitution_code[26] = {'n','w','l','r','b','m','q','h','c','d','a','z','o','k','y','i','s','x','j','f','e','g','p','u','v','t'};

    char *Day_1_decrypted_message = decrypt(Day_1_message,Day_1_Substitution_code);
    printf("Decrypted Message: %s\n",Day_1_decrypted_message);
     
        break;
           
    default: printf("Please make Valid Selection");
    
    
} 
return 0;
}


//= {'B','A','C','D','S','F','G','H','I','J','K','L','M','N','O','P','Q','R','E','T','U','V','W','X','Y','Z'};









