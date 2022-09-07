/*
 * main.c
 *
 *  Created on: 14 Apr 2022
 *      Author: yusuf
 */

#include <stdint.h>
#include <stdio.h>

//funct. defs
void waitKey(void);
void display_array(uint32_t const *const, uint32_t const);
void swap_arrays(uint32_t *const a1, uint32_t *const a2, uint32_t const len1, uint32_t const len2);

int main(){

	uint32_t arr_len1=0,
			arr_len2=0;

	printf("Enter array-1 size and array-2 size : ");
	if(scanf("%u %u", &arr_len1, &arr_len2) == 0){
		printf("Invalid entry !\n");
	}

	uint32_t arr1[arr_len1], arr2[arr_len2];


	for(uint32_t i = 0; i < arr_len1; i++){
		printf("\nEnter %u. element of array-1 : ", i);
		if(scanf("%u", &arr1[i]) == 0){
			printf("Invalid entry !\n");
		}
	}

	for(uint32_t i = 0; i < arr_len2; i++){
		printf("\nEnter %u. element of array-2 : ", i);
		if(scanf("%u", &arr2[i]) == 0){
			printf("Invalid entry !\n");
		}
	}
	printf("\nBEFORE SWAPPING\n");
	display_array(arr1, arr_len1);
	display_array(arr2, arr_len2);

	swap_arrays(arr1, arr2, arr_len1, arr_len2);

	printf("\nAfter SWAPPING\n");
	display_array(arr1, arr_len1);
	display_array(arr2, arr_len2);

	waitKey();
	return 0;
}

void waitKey(void){
	//Exit Section with wait KEY
	printf("\nPress 'Enter' key to EXIT..");
	while(getchar() != '\n'){};
	getchar();
}

void display_array(uint32_t const *const pArr, uint32_t const len){
	//print the swap result
	printf("\nContents : \n");
	for(uint32_t i = 0; i < len; i++){
		printf("%u\t",pArr[i]);
	}
}

void swap_arrays(uint32_t *const a1, uint32_t *const a2, uint32_t const len1, uint32_t const len2){
	uint32_t len = len1 < len2 ? len1 : len2;
	for(uint32_t i = 0; i < len; i++){
		uint32_t temp = a1[i];
		a1[i] = a2[i];
		a2[i] = temp;
	}
}

