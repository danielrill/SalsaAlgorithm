#ifndef _SALSA20_H_
#define _SALSA20_H_

#include <stdint.h>
#include <stddef.h>


/**
 * return codes for s20_crypt
 */
 
enum s20_status_t
{
	S20_SUCCESS,
	S20_FAILURE
};

/**
 * Key size
 * Salsa20 only permits a 128-bit or 256-bit key, 
 * these are the only 2 options made available by this lib.
 */
 
 enum s20_keylen_t
 {
 	S20_KEYLEN_256,
 	S20_KEYLEN_128
 };
 
 /**
  * Encrypt / Decrypt messages up to 2^32 -1 bytes long, under a 256 or 128-bit key and 64-byte nonce.
  * permits seeking to any point within a message
  *
  * key		Pointer to either 128- or 256- bit key.
  *			No key-derivation function is applied to this key, and no
  *			entropy is gathered. It is expected that this key is already appropriate
  *			for direct use by the SALSA20 algo.
  
  * keylen	length of the key
  *			Must be S20_KEYLEN_256 || S20_KEYLEN_128
  *
  * nonce	Pointer to an 8-byte nonce
  *			Does not have to be random, but must be unique for every 
  *			message under a single key. Nonce reuse destroys message confidentiality
  *
  * si		Stream idx
  *			This is for seeking within a larger message. If you are only working with
  *			small messages that are encrypted/decrypted all at once (like TLS-records),
  *			this will always be 0.
  *
  * buf		The data to encrypt/decrypt
  *
  * buflen	Length of the data in buf.
  *
  *
  *	This function returns either S20_SUCCESS or S20_FAILURE.
  *	A return of S20_SUCCESS indicates that basic sanity checking on 
  *	parameters succeeded and ecryption/decryption was performed.
  * 	A return of S20_FAILURE indicates that basic sanity checking on param
  *	failed and ecryption/decryption was not performed
  */
  
enum s20_status_t s20_crypt(uint8_t *key,
							 enum s20_keylen_t keylen,
							 uint8_t nonce[static 8],
							 uint32_t si,
							 uint8_t *buf,
							 uint32_t buflen);

#endif 
