
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

	l = 0                       > 1
	r = n - 1                   > 1
	while l < r do              > n / 2
		if S[l] =/= S[r] then   > n / 2
			return false        > 1
		end if
		
		l = l + 1               > n / 2
		r = r - 1               > n / 2
	end while
	
	return true                 > 1

Time complexity: O(n)
*/

bool isPalindrome(char *S) {
	int n = strlen(S);

	int l = 0;
	int r = n - 1;
	while (l < r) {
		if (S[l] != S[r]) {
			return false;
		}
		l++;
		r--;
	}
	return true;
}
