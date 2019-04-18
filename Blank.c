#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
   int n = 1 ;
   printf("Please enter a valid Selection: \n");
   printf("1. Encryption using a Caesar Cipher\n");
   printf("2. Decryption using a Caesar Cipher (rotation key known)\n");
   printf("3. Encryption using a substitution Cipher\n");
   printf("4. Decryption using a substitution Cipher (substitutions are known)\n");
   printf("5. Decryption of an unknown text piece encrypted with a Rotation Cipher (rotation key unknown\n");
   printf("6. Decryption of a text message encrypted with a substitution Cipher (substitutions unknown)\n");
   
   
     
   switch (n)
   {
    case 1: printf("Encryption using a Caesar Cipher");
        break;
    case 2: printf("Decryption using a Caesar Cipher (rotation key known)");
        break;
    case 3: printf("Encryption using a substitution Cipher");
        break;
    case 4: printf("Decryption using a substitution Cipher (substitutions are known)");
        break;
    case 5: printf("Decryption of an unknown text piece encrypted with a Rotation Cipher (rotation key unknown");
        break;
    case 6: printf("Decryption of a text message encrypted witha  substitution Cipher (substitutions unknown)");
        break;
    default: printf("Please make Valid Selection");
    
    
} 
return 0;
}












