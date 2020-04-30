/* Tomas Brazas
 * G00349242
 * MD5 Hash Generator
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
 
// These variables  will store the hash
uint32_t h0, h1, h2, h3;

int main(int argc, char **argv) {
	printf("Test\n");

	return 0;
}
