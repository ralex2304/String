#ifndef HASH_H_
#define HASH_H_

#include <math.h>
#include <assert.h>

struct Hash {
    static const unsigned int COEFF = 257;
    static const unsigned long long MOD = 1000000000;

    unsigned long long coeff_pow_len = 1;
    unsigned long long hash = 0;
};



Hash hash_create(const char* str, size_t len);

void hash_move(Hash* hash, char remove, char add);

#endif
