
// Q10 using a conditional expression

int ch = getchar();

char *type;
type = isdigit(ch) ? "digit" : "non-digit";

printf("'%c' is a %s\n", ch, type);

// What if you have multiple branches?
// You can nest conditional expressions, but this
// is bad style, don't do it :)

type = isdigit(ch) 
     ? "digit"
	 : (isalpha(ch) ? "letter" : "non-letter");

// Note: isdigit and isalpha are standard C functions,
//       available through <ctype.h>
