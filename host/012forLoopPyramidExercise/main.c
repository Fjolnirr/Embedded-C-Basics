/*
 * main.c
 *
 *  Created on: 5 Apr 2022
 *      Author: yusuf
 */

#include<stdio.h>
#include<stdint.h>

//function defs
void waitKey(void);

int main()
{
	int16_t top;

	printf("Please enter Top number(int) of pyramid : ");
	if(scanf("%hd", &top) == 0){
		printf("Invalid entry !\n");
		waitKey();
		return 0;
	}

	for(int16_t i = 1; i <= top; i++){
		for(int16_t j = 1; j <= i; j++){
			printf("%5hd", i - j + 1);
		}
		printf("\n");
	}


	waitKey();
	return 0;
}

void waitKey(){
	//Exit Section with wait KEY
	printf("\nPress 'Enter' key to EXIT..");
	while(getchar() != '\n'){};
	getchar();
}

