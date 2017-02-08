#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("  Usage: freq2ch <frequency>\n");
		return -1;
	}
	const int nInput = atoi(argv[1]);

	int nChannel = 0, nBase = -1;
	if (nInput >= 2412 && nInput <= 2472) {
		nBase = nInput - 2407;
	}
	else if (nInput >= 5180 && nInput <= 5825) {
		nBase = nInput - 5000;
	}
	else if (nInput == 2484) {
		nChannel = 14;
	}

	if (!(nBase % 5)) {
		nBase /= 5;

		int left = 0, right = sizeof(arrChannels) / sizeof(int);
		int center;

		while (left <= right) {
			center = (left + right) / 2;
			if (nBase > arrChannels[center])
				left = center + 1;
			else if (nBase < arrChannels[center])
				right = center - 1;
			else {
				nChannel = nBase;
				break;
			}
		}
	}

	if (nChannel) {
		printf("The channel of frequency %d Hz: %d\n", nInput, nChannel);

		return 0;
	}

	printf("ERROR: The frequency %d is invalid\n", nInput);

	return -1;
}
