#ifndef TEST_H_
#define TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../custom_strings.h"
#include "../console.h"

/**
 * @brief Specifies test results
 */
enum class TestResult {
    ERROR  = -1, ///< Error happened
    FAILED =  0, ///< Test failed
    PASSED =  1, ///< Test passed
};

/**
 * @brief Tests all
 */
void test_all();

/**
 * @brief Prints test results of section
 *
 * @param test_num
 * @param test_success_num
 */
inline void print_section_test_results(unsigned int test_num, unsigned int test_success_num) {
    if (test_num == test_success_num)
        printf(CONSOLE_GREEN("All %d tests of this section passed!\n"), test_num);
    else
        printf(CONSOLE_RED("%u of %u tests of this section failed!\n"), test_num - test_success_num, test_num);
}

/**
 * @brief Tests cus_strchr()
 *
 * @param str
 * @param symbol
 * @param ptr_ref
 * @return TestResult
 */
TestResult test_cus_strchr(const char* str, const int symbol);

/**
 * @brief Tests cus_strlen()
 *
 * @param str
 * @return TestResult
 */
TestResult test_cus_strlen(const char* str);

/**
 * @brief Tests cus_strcpy
 *
 * @param src
 * @return TestResult
 */
TestResult test_cus_strcpy(const char* src);


/**
 * @brief Tests cus_strncpy
 *
 * @param src
 * @param cnt
 * @return TestResult
 */
TestResult test_cus_strncpy(const char* src, size_t cnt);

/**
 * @brief Tests cus_strcat()
 *
 * @param src
 * @return TestResult
 */
TestResult test_cus_strcat(const char* src);

/**
 * @brief Tests cus_strncat
 *
 * @param src
 * @param cnt
 * @return TestResult
 */
TestResult test_cus_strncat(const char* src, size_t cnt);

/**
 * @brief Tests cus_strstr
 *
 * @param str
 * @param substr
 * @param test_func pointer to the funstion that is being tested
 * @return TestResult
 */
TestResult test_cus_strstr(const char* str, const char* substr,
                           char* (*test_func)(const char* str, const char* substr));

/**
 * @brief Recursively generates 2 strings
 *
 * @param str1 pointer to first string buffer
 * @param depth1 length of str1
 * @param str2 pointer to second string buffer
 * @param depth2 length of str2
 * @param test_num pointer
 * @param test_success_num pointer
 * @param test_func pointer to the funstion that is being tested
 */
void bruteforce_char(char* str1, size_t depth1, char* str2, size_t depth2,
                     unsigned int* test_num, unsigned int* test_success_num,
                     char* (*test_func)(const char* str, const char* substr));

#endif // #ifndef TEST_H_
