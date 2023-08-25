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

#endif // #ifndef TEST_H_
