#ifndef HASH_H_
#define HASH_H_

#include <math.h>
#include <assert.h>

/**
 * @brief Contains reversed polynomial hash informations
 *
 */
struct Hash {
    static const unsigned int COEFF = 257;
    static const unsigned long long MOD = 1000000000;

    unsigned long long coeff_pow_len = 1;
    unsigned long long hash = 0;
};

/**
 * @brief Calculates hash for str
 *
 * @param str
 * @param len
 * @return Hash
 */
Hash hash_create(const char* str, size_t len);

/**
 * @brief Calculates new hash from an old one for substring movement in string
 *
 * @param hash
 * @param remove removed symbol
 * @param add added symbol
 */
void hash_move(Hash* hash, char remove, char add);

#endif
