#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int find_index(char codeDecrypt[],char char_to_find){
  for(int i = 0 ; i < 26; i ++){
    if(codeDecrypt[i] == char_to_find){
      return i;
    }
  }
  return -1;
}

char *decrypt(char *message,char codeDecrypt[]){
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


int main()
{
   int n ;
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
   
   scanf("%d", &n);
 
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
    case 2: printf("Decryption using a Caesar Cipher (rotation key known or unknown)\n");

	
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
    case 3: printf("Encryption using a substitution Cipher \n");
    
    char *message = " TEST MESSAGE";
    char code[26];
    
    printf("Enter Substitution code:  ");
    scanf("%s", &code);

    char *encrypted_message = encrypt(message,code);
    printf("Original Message: %s\nEncrypted Message: %s\n",message,encrypted_message);
      
        break;
    case 4: printf("Decryption using a substitution Cipher (substitutions are known)\n");
    
    char *Message_to_decrypt = "Tset Mseebgs";
    printf("Encrypted Message: %s\n", Message_to_decrypt);
    char Substitution_code[26] = {'b','a','c','d','s','f','g','h','i','j','k','l','m','n','o','p','q','r','e','t','u','v','w','x','y','z'};

    printf("Enter Substitution Code \n");
    scanf("%s", &Substitution_code);
    
    char *decrypted_message = decrypt(Message_to_decrypt,Substitution_code);
    printf("Decrypted Message: %s\n",decrypted_message);

        break;
    case 5: printf("Decryption of a day 1 provided block of cipher encrypted with a substitution cipher\n");
    char *Day_1_message = "N KBP JLCBKFCMCL FXEFH RYBJ KYF FXCEOIH WV LYKGCKLCKQ CFJ YIIYKBKFJ NKR ONACKQ FHBO JBB FHB ZCQHF, WEF XNFHBX WBLNEJB CFJ YIIYKBKFJ BGBKFENZZV RCB, NKR N KBP QBKBXNFCYK QXYPJ EI FHNF CJ MNOCZCNX PCFH CF. - ONU IZNKLA \n";
    printf("Encrypted Message: %s\n", Day_1_message);
    
    char Day_1_Substitution_code[26] = {'n','w','l','g','b','m','q','h','c','d','a','z','o','k','y','i','s','x','j','f','e','p','u','v','t'};

    char *Day_1_decrypted_message = decrypt(Day_1_message,Day_1_Substitution_code);
    printf("Decrypted Message: %s\n",Day_1_decrypted_message);
     
        break;
    case 6: printf("Decryption of a text message encrypted with a substitution Cipher (substitutions unknown)");
    
    
        break;
        
    default: printf("Please make Valid Selection");
    
    
} 
return 0;
}


//= {'B','A','C','D','S','F','G','H','I','J','K','L','M','N','O','P','Q','R','E','T','U','V','W','X','Y','Z'};









