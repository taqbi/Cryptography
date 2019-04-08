#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char message[20],key[20],ciphertext[20];
	printf("Enter the PlaihnText");
	scanf("%s",&message);
	printf("Enter the key");
	scanf("%s",&key);

	while(strlen(key)<strlen(message))
	{
		strcat(key,key);
		
	}
	int i=0;
	while(message[i]!='\0')
	{
		
		 ciphertext[i] = ((message[i] + key[i]) % 193) + 97;
	/*	if(ciphertext[i]>218)
		 {
		 	ciphertext[i] = (ciphertext[i] % 219) + 97;
		 }*/
		i++;
	}

	printf("CipherText is %s \n",ciphertext);
i=0;
while(ciphertext[i]!='\0')
{
	printf("%d ",ciphertext[i]);
	i++;
}
}
