
// Q8
// numToDay using switch statements

char *numToDay(int n)
{
	assert(0 <= n && n <= 6);
	char *day;
	switch (n) {
		case 0: day = "Sun"; break;
		case 1: day = "Mon"; break;
		case 2: day = "Tue"; break;
		case 3: day = "Wed"; break;
		case 4: day = "Thu"; break;
		case 5: day = "Fri"; break;
		case 6: day = "Sat"; break;
	}
	return day;
}
