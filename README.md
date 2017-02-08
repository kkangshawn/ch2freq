# ch2freq

Algorithm to transform Wi-Fi channel to frequency and vice versa
----------------------------------------------------------------

Comparing with using a dictionary storing channel-frequency pairs,
this algorithm - using binary search and equation with array - is faster and saves memory space.
- worst-case time complexity: O(log N)
- worst-case space complexity: O(1)

##Files
- common.h: Wi-Fi Channel list map (20MHz bandwidth based)
- ch2freq.c: Transform input value to frequency if valid
- freq2ch.c: Transform input value to channel if valid
- Makefile

##Usage
```sh
$ ch2freq <channel>
$ freq2ch <frequency>
```
