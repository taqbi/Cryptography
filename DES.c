#include<stdio.h>
#include<string.h>
int binary_conversion(int);

int main()
{
	int key,i=0,j=0,key_bin,key_arr[56],red_arr_key[48];
	char plaintext[10];
	printf("Enter the key");
	scanf("%d",&key);
	key_bin = binary_conversion(key);
	printf("The key in binary is %056d \n",key_bin);
	while(j<56)
{
    key_arr[i]=key_bin % 10;
    key_bin/= 10;
    i++;
    j++;
}
	printf("Enter the text to be encrypted  ");
	scanf("%s",&plaintext);
	printf("The plaintext is ");
	puts(plaintext);
	printf("The 56 bit key is: \n");
	j=0;
	for(i=0;i<=55;i++)
	{
		if(i>0&&i%8==0)
		printf("\n");
		else
		{
			printf("%d ",key_arr[i]);
			
		}
	}
	printf("\n");
	for(i=0;i<=55;i++)
	{
		if(i>0&&i%7==0)
		printf("\n");
		else
		{
		red_arr_key[j]=key_arr[i];
	
		
		printf("%d  ",red_arr_key[j]);
			j++;
	    }
	}
	return 0;
}
int binary_conversion(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 2) + 10 * binary_conversion(num / 2);
    }
}
