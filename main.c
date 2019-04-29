
#include <stdio.h>

//functions declarations
void encryptRotationMessage(char string[], int key);
void decryptRotationMessage(char string[], int key);
void encryptSubstitutionMessage(char string[], int key);
void decryptSubstitutionMessage(char string[], int key);

int main()
{
    int continueAgain = 0;
    int menuChoice;
	char message[1000];
	int key;
	printf("Enter the message you want to encrypty or decrypt(MAX:1000): ");
	scanf("%[^\n]", &message);  //scanning the whole string, including the white spaces
	printf("Enter the key: ");
	scanf("%d", &key);
    printf("\n\n********** MENU **********\n");
    printf("1:\tRotation Cipher\n2:\tSubstitution Cipher\n");
    printf("\nEnter your choice(1 or 2) ");
    
    scanf("%d", &menuChoice);
    
    switch(menuChoice){
        case 1:
            printf("\n\t***** ROTATION CIPHER *****");
            printf("\n1:\tEncryption\n2:\tDecryption");
            printf("\nEnter your choice (1 or 2) ");
            menuChoice = 0;
            scanf("%d", &menuChoice);
            switch(menuChoice){
                case 1:
                    encryptRotationMessage(message, key);
                    break;
                case 2:
                    decryptRotationMessage(message, key);
                    break;
            }
            break;
        case 2:
            printf("\n\t***** SUBSTITUTION CIPHER *****");
            printf("\n1:\tEncryption\n2:\tDecryption");
            printf("\nEnter your choice (1 or 2) ");
            menuChoice = 0;
            scanf("%d", &menuChoice);
            switch(menuChoice){
                case 1:
                    encryptSubstitutionMessage(message, key);
                    break;
                case 2:
                    decryptSubstitutionMessage(message, key);
                    break;
            }
            break;
        default:
            printf("You enter invalid choice, exiting....");
    }

    return 0;
}

//functionsDefinitions
void encryptRotationMessage(char message[], int key){
	int length = strlen(message);
    char encrypted[length];
    int i = 0;
	char ch;
	for(i = 0; i<length; ++i){
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			encrypted[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			encrypted[i] = ch;
		}else{
			encrypted[i] = ch;
		}
	}
    printf("The encrypted string is: %s ", encrypted);
    
}
void decryptRotationMessage(char message[], int key){
		int length = strlen(message);
	    char decrypted[length];
	    int i = 0;
		char ch;
		for(i = 0; i<length; ++i){

		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			
			decrypted[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			
			decrypted[i] = ch;
		}else{
			decrypted[i] = ch;
		}
	}
	printf("The decrypted string is: %s ", decrypted);
    
}
void encryptSubstitutionMessage(char message[], int key){
	char cipherStringCapital[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char cipherStringSmall[26] = "qwertyuiopasdfghjklzxcvbnm";
	
	int length = strlen(message);
	    char encrypted[length];
	    int i = 0;
		char ch;
		for(i = 0; i<length; ++i){

		ch = message[i];
		int index=0;
		if(ch >= 'a' && ch <= 'z'){ // 97 to 122
			index = ch - 97;
			
			encrypted[i] = cipherStringSmall[index];
		}
		else if(ch >= 'A' && ch <= 'Z'){ //65 to 90
			index = ch - 65;
			
			encrypted[i] = cipherStringCapital[index];
		}else{
			encrypted[i] = ch;
		}
	}
	printf("The encrypted string is: %s ", encrypted);
	
    
}
void decryptSubstitutionMessage(char message[], int key){
//    char cipherStringCapital[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	char cipherStringSmall[26] = "abcdefghijklmnopqrstuvwxyz";
	char cipherStringCapital[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char cipherStringSmall[26] = "qwertyuiopasdfghjklzxcvbnm";
	
	int length = strlen(message);
    char decrypted[length];
    int i = 0;
    int j = 0;
	char ch;
	for(i = 0; i<length; ++i){
		ch = message[i];
		int index=-1;
		if(ch >= 'a' && ch <= 'z'){
			for(j=0; j<26;j++){
				if(cipherStringSmall[j] == ch){
					index = j;
					break;
				}
			}			
			decrypted[i] = index + 97;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			for(j=0; j<26;j++){
				if(cipherStringCapital[j] == ch){
					index = j;
					break;
				}
			}			
			decrypted[i] = index + 65;
		}else{
			decrypted[i] = ch;
		}
	}
	printf("The decrypted string is: %s ", decrypted);
}





