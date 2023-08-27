#include "hash.h"

Hash hash_create(const char* str, size_t len) {
    Hash hash = {};
    for (size_t i = 0; i < len; i++) {
        hash.coeff_pow_len = hash.coeff_pow_len * hash.COEFF % hash.MOD;
        hash.hash = (hash.hash * hash.COEFF + str[i]) % hash.MOD;
    }
    return hash;
}

void hash_move(Hash* hash, char remove, char add) {
    hash->hash = (hash->hash * hash->COEFF - hash->coeff_pow_len * remove + add) % hash->MOD;
}
