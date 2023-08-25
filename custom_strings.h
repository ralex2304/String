#ifndef CUSTOM_STRINGS_H_
#define CUSTOM_STRINGS_H_

#include <stdio.h>
#include <assert.h>

/**
 * @brief Puts string str to standart output. \\0 => \\n
 *
 * @param str string
 * @return int if succeed - '\n' else EOF
 */
int cus_puts(const char* str);

/**
 * @brief Finds first positions of symbol in str and returns it's pointer
 *
 * @param str
 * @param symbol
 * @return char* First symbol found in str pointer. If not found, returns nullptr
 */
char* cus_strchr(const char* str, const int symbol);

/**
 * @brief Counts str len
 *
 * @param str
 * @return size_t
 */
size_t cus_strlen(const char* str);

/**
 * @brief Copies src to target
 *
 * @param dest
 * @param src
 * @return char* dest
 */
char* cus_strcpy(char* dest, const char* src);

/**
 * @brief Copies max cnt symbols from src to target
 *
 * @param dest
 * @param src
 * @param cnt
 * @return char*
 */
char* cus_strncpy(char* dest, const char* src, size_t cnt);

/**
 * @brief Concatenates src to dest
 *
 * @param dest
 * @param src
 * @return char* dest
 */
char* cus_strcat(char* dest, const char* src);

/**
 * @brief Concatenates max cnt symbols from src to dest
 *
 * @param dest
 * @param src
 * @param cnt
 * @return char* dest
 */
char* cus_strncat(char* dest, const char* src, size_t cnt);

/**
 * @brief Reads max cnt-1 symbols from stream to str
 *
 * @param str
 * @param cnt
 * @param stream
 * @return char* if succeed str, else nullptr
 */
char* cus_fgets(char* str, int cnt, FILE* stream);

/**
 * @brief Allocates memory for str, copies it and returns pointer
 *
 * @param str
 * @return char*
 */
char* cus_strdup(const char* str);

/**
 * @brief Gets line from stream
 *
 * @param str
 * @param cnt
 * @param stream
 * @return ssize_t Number of characters were read. -1 in case of error
 */
ssize_t cus_getline(char** str, size_t* cnt, FILE* stream);

/**
 * @brief Geometric realloc for char*
 *
 * @param str
 * @param n
 * @return true if succeed
 * @return false if realloc failed
 */
bool geom_realloc(char** str, size_t* n);

#endif // #ifndef CUSTOM_STRINGS_H_
