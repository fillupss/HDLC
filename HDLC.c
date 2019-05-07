/*
 * HDLC.c
 *
 *  Created on: Sep 25, 2018
 *      Author: philipchen
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

char data[1024];

int main(){
	initscr();
	int i = 0;
	int dataIndex = 0;
	printw("Enter a data(flag is 01111110): \n");
	char c;
	// Everytime a part of flag is detected in right index increment i until i is size of the flag which is 8
	// if a part of flag is detected then have to check subsequent inputs
	// if the subsequent input is not correct character in that specific index then reset i to 0
	while(i < 8){
		c = getch();
		if((i == 0) || (i == 7)){
			if(c == '0'){
				i++;
			}
			else{
				i = 0;
			}
		}
		else{
			if(c == '1'){
				i++;
			}
			// this is the case when a 0 is input at wrong index when a flag is being checked (Ex. "0110")
			// where the second zero is not on the right index
			else if (c == '0'){
				i = 1;
			}
			else{
				i = 0;
			}
		}
	}
	printw("\nFirst flag has been detected!\n");
	printw("Enter another flag to send data:\n");


	// same algorithm as the first flag except we need to keep track of the data that the user wants to send
	int j = 0;
	while(j < 8){
		c = getch();
		data[dataIndex] = c;
		dataIndex++;
		if(j == 0){
			if(c == '0'){
				j++;
			}
			else{
				j = 0;
			}
		}
		else if (j > 0 && j < 7){
			if(c == '1'){
				j++;
			}
			else if (c == '0'){
				j = 1;
			}
			else{
				j = 0;
			}
		}
		// j = 7
		else{
			if(c == '0'){
				printf("\n");
				for(int l = 0; l < dataIndex; l++){
					printf("\b");
				}
				printf("The data that was transferred was: ");
				for(int k = 0; k < dataIndex-8; k++){
					printf("%c", data[k]);
				}
				j++;

			}
			else{
				j = 0;
			}
		}

	}
	endwin();
	return 0;

}


