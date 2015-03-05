/*
 ============================================================================
 Name        : crc16.c
 Author      : Eric V., based on sources from http://www.acooke.org/cute/16bitCRCAl0.html
 Version     :
 Description : crc16 CLI utility
 ============================================================================
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "crc.h"

int main(int argc, char **argv) {

	  if (argc < 2) {
		  printf("%u", 0);
		  exit(1);
	  }

	int crc = 0;
	const char* cData = argv[1];
	int nSize = atoi(argv[2]);

	crc = crc16((uint8_t*) cData, nSize);

	  printf("%u", crc);

	return 1;
}
