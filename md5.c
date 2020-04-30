/* Tomas Brazas
 * G00349242
 * MD5 Hash Generator
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
 
// These variables  will store the hash
uint32_t h0, h1, h2, h3;

// Main MD5 function 
void md5(uint8_t *initial_msg, size_t initial_len) {
	
	// Message
	uint8_t *msg = NULL;
	
	// Per-round shift amounts
	uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                    5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
	
	// Using binary integers part of the sines of intergers (in radians) as constants
	uint32_t k[] = {
        	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

	// Initializing
	h0 = 0x67452301;
	h1 = 0xefcdab89;
	h2 = 0x98badcfe;
	h3 = 0x10325476;
	
	// Pre-processing
	// Appending 1 bit to message
	// Padding with zeros
	// Append 0 bit until msg length in bits = 448 (mod 512)
	// Append length mod (2 pow 64) to message
	int new_len = ((((initial_len + 8) / 64) + 1) * 64) - 8;
	
	msg = calloc(new_len + 64, 1); // 
	memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = 128;

	// Append len, copy in bits at the end of the buffer
	uint32_t bits_len = 8*initial_len; 
	memcpy(msg + new_len, &bits_len, 4);      
	
	// Process the message in successive 512-bit chunks
	int offset;
	for(offset=0; offset<new_len; offset += (512/8)) {
	
	// Breaks the chunk into 16 32-bit words
        uint32_t *w = (uint32_t *) (msg + offset);

	// Initializing hash value for the chunk
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;

        uint32_t i;

	// Main loop, rounds 
        for(i = 0; i<64; i++) {

#ifdef ROUNDS
        uint8_t *p;
        printf("%i: ", i);
        p=(uint8_t *)&a;
        printf("%2.2x%2.2x%2.2x%2.2x ", p[0], p[1], p[2], p[3], a);

	p=(uint8_t *)&b;
	printf("%2.2x%2.2x%2.2x%2.2x ", p[0], p[1], p[2], p[3], b);

        p=(uint8_t *)&c;
        printf("%2.2x%2.2x%2.2x%2.2x ", p[0], p[1], p[2], p[3], c);

	p=(uint8_t *)&d;
	printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], d);
        puts("");
#endif

	uint32_t f, g;

        if (i < 16) {
        	f = (b & c) | ((~b) & d);
                g = i;
        } else if (i < 32) {
                f = (d & b) | ((~d) & c);
                g = (5*i + 1) % 16;
        } else if (i < 48) {
                f = b ^ c ^ d;
                g = (3*i + 5) % 16;
       	} else {
                f = c ^ (b | (~d));
                g = (7*i) % 16;
       	}

#ifdef ROUNDS
        printf("f=%x g=%d w[g]=%x\n", f, g, w[g]);
#endif
        uint32_t temp = d;
       	d = c;
        c = b;
        b = b + LEFTROTATE((a + f + k[i] + w[g]), r[i]);
        a = temp;

	

        }
	
	// Chunk's of hash added to the result
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;

    }
    // deallocates the memory previously allocated
    free(msg);
}

// Tests
static char *val[] = {
    "d41d8cd98f00b204e9800998ecf8427e",
    "0cc175b9c0f1b6a831c399e269772661",
    "900150983cd24fb0d6963f7d28e17f72",
    "f96b697d7cb7938d525a2f31aaf161d0",
    "c3fcd3d76192e4007dfb496cca67e13b",
    "d174ab98d277d9f5a5611c2c9f419d9f",
    "57edf4a22be3c955ac49da2e2107b67a"
};

static char *tests[] = {
    "",
    "a",
    "abc",
    "message digest",
    "abcdefghijklmnopqrstuvwxyz",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
    "12345678901234567890123456789012345678901234567890123456789012" \
        "345678901234567890"
};

// Main 
int main(int argc, char **argv) {
	
	char *msg = "";
	// If/else if/else to compare command line arguments
	if(!strcmp(argv[1], "--help")){

		printf("Information on how to run the application:\n");
		printf("\n");
		printf("To Run Type: ./md5 --run ''your string here''\n");
		printf("For Tests Type: ./md5 --x\n" );
		printf("For Time Trial Type: ./md5 --t ''your string here''\n");

	}
	else if(!strcmp(argv[1], "--run")){
			
		char *msg = argv[2];
    		size_t len = strlen(msg);
		
		// passed into MD5
        	md5(msg, len);
		// Little Edian output
    		uint8_t *p;

    		// Output
    		p=(uint8_t *)&h0;
    		printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], h0);

    		p=(uint8_t *)&h1;
    		printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], h1);

    		p=(uint8_t *)&h2;
    		printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], h2);

    		p=(uint8_t *)&h3;
    		printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], h3);
    		puts("");

    		return 0;
	}
	else if(!strcmp(argv[1], "--x")){
	// Tests
	/*	char *msg = tests[1];
    		size_t len = strlen(msg);

		int i = 0,j;

		if (memcmp( *p, val[i], 32))
		{
			printf( "failed\n");
			return(1);
		}
		printf("passed");*/

    	return 0;
   	 }
	else if(!strcmp(argv[1], "--t")){ // Time from C libraries

		clock_t start, end;
		double cpu_time_used;
		
		// start time
		start = clock();
		char *msg = argv[2];
    		size_t len = strlen(msg);

        	md5(msg, len);
   
    		uint8_t *p;
		
		// stop time
    		end = clock();
		
		// Time in seconds
    		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    		printf("Time taken to hash the string:  %f\n", cpu_time_used);
    	return 0;
	}
	else{
		
		printf("Invalid arguments, type --help on information how to successfully run the application.\n");
	}

}
