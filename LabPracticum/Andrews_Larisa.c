//THURSDAY
/* Larisa Andrews, Section T, 12/10/15 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* 
Pre: The original plaintext phrase with spaces is passed in.
The function searches for a space.  When found,
the spece is removed by shifting all remaining elements 
in the array one space to the left.  
Post: The plaintext phrase has been modified so it no longer
contains spaces.
*/
void RmSpaces (char plaintext[]);

/* 
Pre: The plaintext phrase with the spaces removed is passed in.
Each character in the plaintext phrase is converted to lowercase.  
Post: The plaintext phrase has been modified so it no longer
has any uppercase letters in it.
*/

void MkLowerCase (char plaintext[]);

/* 
Pre: The plaintext phrase with the spaces removed, the key, the alphabet, 
the array to store the secret phrase, and the flag are passed in.  A true flag value
means the function should encrypt the plaintext phrase.  A false flag value 
means the function should decrypt the plaintext phrase.  
Post: Both the plaintext and the secret phrase arrays are filled.
*/

void EncryptDecrypt (char encryption[], char plaintext[], char secretkey[], char alphaList[], int flag); 

/* 
Pre: The plaintext phrase and the secret phrase are passed in.  
Post: The plaintext phrase and the secret phrase are printed.
*/
void PrintOutput (char plaintext[], char encryption[]);


int main (int argc, char* argv[]) {
	char alphabet[26] = 
	{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char key[26] = 
	{'d', 'e', 'f', 'j', 'k', 'l', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'm', 'n', 'o', 'a', 'b', 'c', 'p', 'q', 'r', 'g', 'h', 'i'};
	
	char phrase[100] = "Help me Obi Wan Kenobi You are my only hope";
	char secretphrase[100];
	int flag = 1;
    int whichTime = 0; 	
	
	RmSpaces(phrase);//Write your function calls here.
    
	MkLowerCase(phrase);  	
	
	if(whichTime == 0){
		EncryptDecrypt(key, phrase, secretphrase, alphabet, flag); 
		whichTime = 1; 
	}
	
	else if(whichTime == 1){
		flag = 0; 
		EncryptDecrypt(key, phrase, secretphrase, alphabet, flag); 
		whichTime = 0; 
	}
	PrintOutput(phrase,secretphrase); 
	
	
	return 0;
	
}

void RmSpaces (char plaintext[]){
	int i; 
	int j; 
	int length; 
		
	for(i = 0; i < 100; i++ ){
		if(isspace(plaintext[i])){
			
			plaintext[i] = plaintext[i-1]; 
			
		}
		
		 

		
		
	}
    
}
void MkLowerCase (char plaintext[]){
	int i;
	for(i = 0; i < 100; i++){
		plaintext[i] = tolower(plaintext[i]); 
	}
	
}
void EncryptDecrypt (char encryption[], char plaintext[], char secretkey[], char alphaList[], int flag){
	int i,j; 
	char letterChange; 
	if(flag == 1){
		for(i = 0; i < 100; i++){
		   if(strchr(plaintext,alphaList[i])){
			   secretkey[i] = encryption[i];
		   }
           else if(strrchr(plaintext,alphaList[i])){
				secretkey[i] = encryption[i];
			}		   
		 
		  
		}
		for(j = 100; j > 0; j--){
		   if(strchr(plaintext,alphaList[i])){
			   secretkey[j] = encryption[j];
		   }
           else if(strrchr(plaintext,alphaList[i])){
				secretkey[j] = encryption[j];
			}		   
		 
		  
		}
		
	}
	else{
		for(i = 0; i < 100; i++){
		   if(strchr(secretkey,encryption[i])){
			   plaintext[i] = alphaList[i];
		   }
           else if(strrchr(secretkey,encryption[i])){
				plaintext[i] = alphaList[i];
			}		   
		 
		  
		}
		for(j = 100; j > 0; j--){
		   if(strchr(plaintext,encryption[i])){
			   plaintext[j] = alphaList[j];
		   }
           else if(strrchr(plaintext,encryption[i])){
				plaintext[j] = alphaList[j];
			}		   
		 
		  
		}
		
	}
}
void PrintOutput (char plaintext[], char encryption[]){
	printf("The Plaintext is %s\n", plaintext);
	printf("The secret phrase is %s\n", encryption); 
}
//Write your functions here.  