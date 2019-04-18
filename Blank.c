#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>











int main()
{
   int n = 2 ;
   char message[1000];
   char ch;
   int key;
   int i;
   printf("Please enter a valid Selection: \n");
   
   printf("1. Encryption using a Caesar Cipher\n");
   
   printf("2. Decryption using a Caesar Cipher (rotation key known)\n");
   
   printf("3. Encryption using a substitution Cipher\n");
   
   printf("4. Decryption using a substitution Cipher (substitutions are known)\n");
   
   printf("5. Decryption of an unknown text piece encrypted with a Rotation Cipher (rotation key unknown )\n");
   
   printf("6. Decryption of a text message encrypted with a substitution Cipher (substitutions unknown)\n"); 
   
   
   //insert scanf here to control menu options
 
   switch (n)
   {
    case 1: printf("Encryption using a Caesar Cipher\n");
    
	
	printf("Enter a message to encrypt:  \n");
	fgets(message, sizeof(message), stdin);
	
	printf("Enter key: \n");
	scanf("%d", &key);
	
	for( int i = 0; message[i] != '\0'; i++) {
	    if (message[i] >= 'A' && message[i] <= 'Z'){
	        message[i] = (message[i] - 'A' + key) %26 + 'A';
	    }
	    if (message[i] >= 'a' && message[i] <= 'z') {
	       message[i] = (message[i] - 'a' + key) %26 + 'a';
	    }
	}
	printf("Encrypted message: %s", message);
            
        break;
    case 2: printf("Decryption using a Caesar Cipher (rotation key known)\n");

	
	printf("Enter a message to decrypt: \n");
	fgets(message, sizeof(message), stdin);
	printf("Enter key: \n");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Decrypted message: %s", message);    
        break;
    case 3: printf("Encryption using a substitution Cipher");
    
    
        break;
    case 4: printf("Decryption using a substitution Cipher (substitutions are known)");
    
    
        break;
    case 5: printf("Decryption of an unknown text piece encrypted with a Rotation Cipher (rotation key unknown");
    
    
        break;
    case 6: printf("Decryption of a text message encrypted with a substitution Cipher (substitutions unknown)");
    
    
        break;
        
    default: printf("Please make Valid Selection");
    
    
} 
return 0;
}












