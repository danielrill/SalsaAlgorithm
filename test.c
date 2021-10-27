#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "salsa20.h"

int main()
{
	uint32_t len = 100000000;
	
	//encrypt 100MB of mem
	uint8_t *data = (uint8_t *) malloc(len);
	if (data == NULL)
	{
		puts("100MB malloc failed");
		exit(1);
	}
	
	uint8_t key[16] = { 0 };
	uint8_t nonce[8] = { 0 };
	
	if (s20_crypt(key, S20_KEYLEN_128, nonce, 0, data, len))
		puts("Error: encryption failed");
		
	if (s20_crypt(key, S20_KEYLEN_128, nonce, 0, data, len))
		puts("Error: encryption failed");
		
	return 0;
}
