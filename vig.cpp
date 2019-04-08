#include<stdio.h>
#include<string.h>
 
int main(){
    char msg[20],key[10];
    	printf("Enter the PlainText");
	scanf("%s",&msg);
	printf("Enter the key");
	scanf("%s",&key);
	int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 

    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 

    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A'+1;
 
    encryptedMsg[i] = '\0';
 
    
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[i] = '\0';
 
    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
 
 i=0;
while(encryptedMsg[i]!='\0')
{
	printf("%d ",encryptedMsg[i]);
	i++;
}
    return 0;
}
