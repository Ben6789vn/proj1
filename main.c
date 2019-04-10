#include<tdio.h>
#include<string.h>


    
    void encryptMessage (char str[]);
    
int main() {
    
    void encryptMessage( char string[]){
        int length = strlength(string);
        char encrypt[length];
        int i=0;
        int count=0;
        
        for (i=0;i<length; i++)
        {
            if (string[i]=65)
            {
                encrypted[i]=90;
                
            }
            else if (string[i]=90)
            {
                encrypted[i]=65;
            
            }
            else
            {
                encrypted[i]= tring[i]-1;
                
            }
            printf("")
        }
    }
   
return 0;
}
