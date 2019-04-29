#include <stdio.h>
#include <string.h>


void encryptMessage(char str[]);

int main()
{
   
    encryptMessage("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    return 0;
}

// may declare key at the top and have more options
void encryptMessage(char string[]){
    int length = strlen(string);
    char encrypted[length];
    int i = 0;
    int count = 0;
    for(i=0; i<length; i++){
        if(string[i] == 65){
            encrypted[i] = 90;
        }
        else if(string[i] == 90){
            encrypted[i] = 65;
            count++;
        }else {
            encrypted[i] = string[i] - 1;    
        }
        
    }
    printf("The String is: %s and its count is %d",encrypted,count);
}

