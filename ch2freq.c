#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("  Usage: ch2freq <channel>\n");
		return -1;
	}
	const int nInput = atoi(argv[1]);

	int left = 0, right = sizeof(arrChannels) / sizeof(int);
	int center;
	while (left <= right) {
		center = (left + right) / 2;
		if (nInput > arrChannels[center])
			left = center + 1;
		else if (nInput < arrChannels[center])
			right = center - 1;
		else {
			// found the channel exists
			int nFreq;
			if (nInput < 14)	/* 2.4GHz    */
				nFreq = 2407 + 5 * nInput;
			else if (nInput > 14)	/* 5GHz      */
				nFreq = 5000 + 5 * nInput;
			else if (nInput == 14)  /* exception */
				nFreq = 2484;
			printf("The frequency of channel %d: %d Hz\n",
					nInput, nFreq);

			return 0;
		}
	}

	printf("ERROR: The channel %d doesn't exist\n", nInput);

	return -1;
}
