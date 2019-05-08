
// Lab 10 ExTalker Skeleton Code
// Question 1: I keep track of the word on the screen by adding the x and y coordinates which I get from the cursor. 
// I think this interface reasonable. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define ARROW 2
#define DEBUG 0   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) ;
void updatebuffer(char buffer[], int length, int new_item); 



int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i,j;
	int x = 0; 
	int y = 0;
    int posX = 0; 
    int posY = 0; 	
	int print = 0; 
	int arrow = 0;
	int var = 0;
    int length = 0; 	
	char chars = '<';
    char space = ' ';
    int t, downB, upB, leftB, rightB, non1, non2, jDown, jUp, jLeft, jRight, jStuff1, jStuff2; 
	int time2, time3, timeSec = 0; 
	char array[200][200]; 
	char word[100]; 
	int lastWordArray[100]; 
	int index = 0; 
	
	initscr();
	refresh();
	
	wordCount = readWords(wordlist, argv[1]);
    scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t,&downB,&upB, &leftB, &rightB, &non1, &non2, &jDown, &jUp, &jLeft, &jRight, &jStuff1, &jStuff2);
	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%s,", wordlist[i]);

			}
		printf("\n");
		}
   time3 = t; 
   while(1){
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t,&downB,&upB, &leftB, &rightB, &non1, &non2, &jDown, &jUp, &jLeft, &jRight, &jStuff1, &jStuff2);
	mvprintw(y,x+WORDLEN,"%c",chars);
	refresh();
	
		if(print == 0){
			var = 0;
			for(j = 0; j < 5 && var < wordCount; j++){
				for(i = 0; i < 15 && var < wordCount; i++){
					mvprintw(i,j*15,"%s",wordlist[var]);
                    var++;					
					refresh();
				
				}
				
				
			} 
			
		} 
	
		print = 1;
		

		
		
		time2 = t; 
        if(time2 - time3 > 150){   				  
			
			 refresh();
			if(non1 == 1){
				updatebuffer(word, length,length); 
				mvprintw(18, 0, "%s", word);
				refresh(); 
				
			}
			if((jDown == 1)&&(y != 14)){
				mvprintw(y,x+WORDLEN,"%c",space);
			    y++;
				mvprintw(y,x+WORDLEN,"%c",chars);
				refresh(); 				
			}
			if((jUp == 1)&&(y != 0)){
				mvprintw(y,x+WORDLEN,"%c",space);
				y--;
				mvprintw(y,x+WORDLEN,"%c",chars);
				refresh(); 				
		    }
			if((jRight == 1)&&(x != 60)){
				mvprintw(y,x+WORDLEN, "%c", space);
				x = x + 15; 
				mvprintw(y,x+WORDLEN, "%c", chars);
				refresh(); 
			}
			if((jLeft == 1)&&(x != 0)){
				mvprintw(y,x+WORDLEN, "%c", space);
				x = x - 15; 
				mvprintw(y,x+WORDLEN, "%c", chars);
				refresh(); 
			}
			if(leftB == 1){
              posX = x;
              posY = y; 			  
			  arrow = ((posX)+(posY));
			  lastWordArray[index] = strlen(wordlist[arrow]);
			  index++;
			  strcat(word, wordlist[arrow]); 
              length = strlen(word);			  
              mvprintw(18, 0, "%s", word);
              refresh(); 	 			   
			}
			if(upB == 1){
				posX = x;
				posY = y; 			  
				arrow = ((posX)+(posY));
				lastWordArray[index] = strlen(wordlist[arrow])+1;
				index++; 
				strcat(word, " "); 
				strcat(word, wordlist[arrow]); 
                length = strlen(word); 				
				mvprintw(18, 0, "%s", word);
				refresh();
			}
			if(downB == 1){
				
				index--; 
				updatebuffer(word, length, lastWordArray[index]);
				length = strlen(word);
				mvprintw(18, 0, "%s", word);
				refresh();
				
			}
			/*if(rightB == 1){
				posX = x;
				posY = y; 			  
				arrow = ((posX)+(posY));
				lastWordArray[index] = strlen(wordlist[arrow])+1;
				strcat(word, " "); 
				strcat(word, wordlist[arrow]); 
				word[lastWordArray[index]] = toupper(word[lastWordArray[index]]);
                index++; 				
                length = strlen(word); 				
				mvprintw(18, 0, "%s", word);
				refresh();
			}*/
			
			
			time3 = t;
        }
        
        refresh(); 		
				
				
					
	}
	
	
// most of your code goes here. Don't forget to include the ncurses library 
    endwin();
}

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }


// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}

void updatebuffer(char buffer[], int length, int new_item){
	int i; 
	for(i = length - 1; i >= length - new_item; i--){
			buffer[i] = ' ';
			mvprintw(18, i, " ");
					
			
	}
	buffer[i+1] = '\0';
	
	
}


