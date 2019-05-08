/* Larisa Andrews, Section T, 10/22/15 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char AskToPlay(int numTimesPlayed);
int SelectRandNum();
void RunGame (int computerNum);

int main() {
	char playYesOrNo = '-';
	int timesPlayed, computerGuess = 0; 
	
	while(timesPlayed > -1){
		timesPlayed++;
		if(AskToPlay(timesPlayed)==1){
		
		printf("%d", timesPlayed);
		computerGuess = SelectRandNum();
        RunGame(computerGuess);		
			
			
		}
		else {
			printf("Thank you for playing!\n"); 
			break; 
		}
	//Put your code here
	
	
	
	
	}	
	return 0;

}
char AskToPlay(int numTimesPlayed){
	//Put your code for this function here
	char answer; 
	if(numTimesPlayed == 1){
		printf("Would you like to play a guessing game?\n"); 
		scanf("%c", &answer); 
		printf("\n"); 
		if(answer == 'y'){
				return 1; 
		}
		else {
			return 0; 
		}
	}
	else if(numTimesPlayed > 1) {
		printf("Would you like to play again?\n");
        fflush(stdout); 		
		scanf("%c", &answer);
		if(answer == 'y') {
			return 1; 
			
		}
		else if(answer == 'n') {
			return 0; 
		}
		
	}
	
	
	
}

int SelectRandNum() {
	//The statement below seeds rand() for you.  Please do not remove it from your function.
	srand((int)time(0));
	int money; 
	money = (rand()%76);
	return money; 
	
	
	//Put your code for this function here
	
	
	
	
}


void RunGame (int computerNum) {
	//Put your code for this function here
	int guess = 0; 
	
	
	printf("You are now guessing how much money I have in my wallet!\n");
	printf("The amount of money is between 1 dollar and 76 dollars, including $1 and $76.\n\n"); 
	printf("What is your guess? Again this is a whole number!\n"); 
	scanf("%d", &guess); 
	while(1){
		if((guess >= 1)&&(guess <= 76)){
				
			if(guess == computerNum){
					printf("Congratulations! That is the correct amount of money in my wallet!\n");
					printf("The correct amount of money was %d\n", computerNum);
					break; 
					
			}
			else if(guess < computerNum){
					printf("To low! Try again!\n");
					scanf("%d", &guess);
			}
			else {
					printf("To High! Try again!\n");
					scanf("%d", &guess);
			}
				
		}
		else{
			printf("That is not a number between 1 and 76! Try again!\n"); 
			scanf("%d", &guess); 
		}
	}
	



}