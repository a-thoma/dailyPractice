#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

	/* our input consists of a string of chars, with repeating possible */
	/* TODO: Change use of testinput to use of anything coming in */
	const char* test = "AAAABBBCCDAA";
	const int len = strlen(test);
	char prev = 0; /* should initially be zero */
	char curr = 0; /* should initially be zero */
	int count = 0; /* should initially be zero */

	// printf("%d\n", len);
	/* we want to have a loop that iterates through every char in the string,
	 * and counts the number of recurring chars, and encoding that information
	 * as another string.
	 * i.e. AAAABBBCCDAA -> 4A3B2C1D2A
	 */

	int i;
	for(i = 0; i <= len; i++) {

		curr = test[i]; /* grab a char */
		// printf("%c\n", temp);

		/* case 1: same character
		 * in this case, we increment the counter, update our previous char,
		 * and continue through the string.
		 *
		 * case 2: new character
		 * in this case, we concatenate our previous character to our result
		 * string (if prev != 0), reset the counter to 1, update our previous
		 * char, and continue through the string.
		 */

		if(curr == prev) { /* same character case */

			count++;
			prev = curr;
		} else {           /* new character case */

			/* TODO: instead of just printing, put in result string & print */
			if(prev != 0) printf("%d%c",count, prev);
			count = 1;
			prev = curr;
		}
	}

	/* TODO: won't need this if we're using a result string */
	printf("\n");

	return EXIT_SUCCESS;
}