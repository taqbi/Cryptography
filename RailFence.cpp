#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char message[20],mat1[10],mat2[10],ciphertext[20];
	printf("Enter the PlianText");
	scanf("%s",&message);
	int i=0,j=0,k=0;
	while(message[i]!='\0')
	{


		{
		while(i%2==0)
		{
			mat1[j]=message[i];
			j++;	
			i++;
		}
		while(i%2==1)
		{
			mat2[j]=message[i];
			k++;	
			i++;
		}
	}
	}
	strcat(mat1,mat2);
	printf("Ciphertext is %s",mat1);
	
	
}
