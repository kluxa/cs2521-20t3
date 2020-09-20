
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *str);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	bool result = isPalindrome(argv[1]);
	printf("%s\n", result ? "yes" : "no");
}

/*
Example of palindromes:
- racecar
- a
- bob
- madamimadam
- 
Examples of non-palindromes:
- ab
- abc
- abca
- jeff

PSEUDOCODE:
isPalindrome(S):
	Input  array S[0..n - 1] of characters
	Output true if S is a palindrome, false otherwise


*/

bool isPalindrome(char *S) {
	return false;
}
