#include "test.h"

void test_all() {
    unsigned int test_num = 0;
    unsigned int test_success_num = 0;

    // test_cus_strchr
    printf("Testing cus_strchr\n");
    test_num = 0;
    test_success_num = 0;
    for (int i = 0; i < 9; i++) {
        test_num++;
        if (test_cus_strchr("12345678", '0' + i) == TestResult::PASSED)
            test_success_num++;
        else
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
    }

    test_num++;
    if (test_cus_strchr("12345678", '\0') == TestResult::PASSED)
        test_success_num++;
    else
        printf(CONSOLE_RED("Test %u failed.\n"), test_num);

    print_section_test_results(test_num, test_success_num);

    // test_cus_strlen
    printf("Testing cus_strlen\n");
    test_num = 0;
    test_success_num = 0;
    const char* buf = "123456789";
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strlen(buf + i) == TestResult::PASSED)
            test_success_num++;
        else
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
    }
    print_section_test_results(test_num, test_success_num);

    // test_cus_strcpy
    printf("Testing cus_strcpy\n");
    test_num = 0;
    test_success_num = 0;
    buf = "123456789";
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strcpy(buf + i) == TestResult::PASSED)
            test_success_num++;
        else
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
    }
    print_section_test_results(test_num, test_success_num);

    // test_cus_strncpy
    printf("Testing cus_strncpy\n");
    test_num = 0;
    test_success_num = 0;
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strncpy("12345678", i) == TestResult::PASSED)
            test_success_num++;
        else
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
    }
    print_section_test_results(test_num, test_success_num);

    // test_cus_strcat
    printf("Testing cus_strcat\n");
    test_num = 0;
    test_success_num = 0;
    buf = "123456789";
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strcat(buf + i) == TestResult::PASSED)
            test_success_num++;
        else
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
    }
    print_section_test_results(test_num, test_success_num);

    // test_cus_strncat
    printf("Testing cus_strncat\n");
    test_num = 0;
    test_success_num = 0;
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strncat("12345678", i) == TestResult::PASSED)
            test_success_num++;
        else
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
    }
    print_section_test_results(test_num, test_success_num);

    // test_cus_strstr
    char str1[11];
    str1[10] = '\0';
    char str2[5];
    str2[4] = '\0';

    // test_cus_strstr_simple
    printf("Testing cus_strstr_simple\n");
    test_num = 0;
    test_success_num = 0;
    bruteforce_char(str1, 10, str2, 4, &test_num, &test_success_num, &cus_strstr_simple);
    print_section_test_results(test_num, test_success_num);

    // test_cus_strstr_bm
    printf("Testing cus_strstr_bm\n");
    test_num = 0;
    test_success_num = 0;
    bruteforce_char(str1, 10, str2, 4, &test_num, &test_success_num, &cus_strstr_bm);
    print_section_test_results(test_num, test_success_num);

    // test_cus_strstr_hash
    printf("Testing cus_strstr_hash\n");
    test_num = 0;
    test_success_num = 0;
    bruteforce_char(str1, 10, str2, 4, &test_num, &test_success_num, &cus_strstr_hash);
    print_section_test_results(test_num, test_success_num);

    // test_cus_strstr_kmp
    printf("Testing cus_strstr_kmp\n");
    test_num = 0;
    test_success_num = 0;
    bruteforce_char(str1, 10, str2, 4, &test_num, &test_success_num, &cus_strstr_kmp);
    print_section_test_results(test_num, test_success_num);
}

TestResult test_cus_strchr(const char* str, const int symbol) {
    assert(str);


    char* result = cus_strchr(str, symbol);
    char* result_ref = strchr(str, symbol);

    if (result_ref == nullptr || result == nullptr) {
        if (result == result_ref)
            return TestResult::PASSED;
        else {
            printf("Must be\n"
                   "%s\n"
                   "instead of\n"
                    "%s\n", result_ref, result);
            return TestResult::FAILED;
        }
    }

    if (strcmp(result, result_ref) != 0) {
        printf("Must be\n"
               "%s\n"
               "instead of\n"
               "%s\n", result_ref, result);
        return TestResult::FAILED;
    }
    return TestResult::PASSED;
}

TestResult test_cus_strlen(const char* str) {
    assert(str);

    size_t result_ref = strlen(str);
    size_t result = cus_strlen(str);

    if (result != result_ref) {
        printf("Must be %lld instead of %lld\n", result_ref, result);
        return TestResult::FAILED;
    }
    return TestResult::PASSED;
}

TestResult test_cus_strcpy(const char* src) {
    char buf[1000] = "";
    char buf_ref[1000] = "";

    char* result_ref = strcpy(buf_ref, src);
    char* result = cus_strcpy(buf, src);

    if (result_ref == nullptr || result == nullptr) {
        if (result == result_ref)
            return TestResult::PASSED;
        else {
            printf("Must be\n"
                   "%s\n"
                   "instead of\n"
                    "%s\n", result_ref, result);
            return TestResult::FAILED;
        }
    }

    if (strcmp(result, result_ref) != 0) {
        printf("Must be\n"
               "%s\n"
               "instead of\n"
               "%s\n", result_ref, result);
        return TestResult::FAILED;
    }
    return TestResult::PASSED;
}

TestResult test_cus_strncpy(const char* src, size_t cnt) {
    char buf[1000] = "";
    char buf_ref[1000] = "";

    char* result_ref = strncpy(buf_ref, src, cnt);
    char* result = cus_strncpy(buf, src, cnt);

    if (result_ref == nullptr || result == nullptr) {
        if (result == result_ref)
            return TestResult::PASSED;
        else {
            printf("Must be\n"
                   "%s\n"
                   "instead of\n"
                    "%s\n", result_ref, result);
            return TestResult::FAILED;
        }
    }

    if (strcmp(result, result_ref) != 0) {
        printf("Must be\n"
               "%s\n"
               "instead of\n"
               "%s\n", result_ref, result);
        return TestResult::FAILED;
    }
    return TestResult::PASSED;
}

TestResult test_cus_strcat(const char* src) {
    char buf[1000] = "123";
    char buf_ref[1000] = "123";

    char* result_ref = strcat(buf_ref, src);
    char* result = cus_strcat(buf, src);

    if (result_ref == nullptr || result == nullptr) {
        if (result == result_ref)
            return TestResult::PASSED;
        else {
            printf("Must be\n"
                   "%s\n"
                   "instead of\n"
                    "%s\n", result_ref, result);
            return TestResult::FAILED;
        }
    }

    if (strcmp(result, result_ref) != 0) {
        printf("Must be\n"
               "%s\n"
               "instead of\n"
               "%s\n", result_ref, result);
        return TestResult::FAILED;
    }
    return TestResult::PASSED;
}

TestResult test_cus_strncat(const char* src, size_t cnt) {
    char buf[1000] = "123";
    char buf_ref[1000] = "123";

    char* result_ref = strncat(buf_ref, src, cnt);
    char* result = cus_strncat(buf, src, cnt);

    if (result_ref == nullptr || result == nullptr) {
        if (result == result_ref)
            return TestResult::PASSED;
        else {
            printf("Must be\n"
                   "%s\n"
                   "instead of\n"
                    "%s\n", result_ref, result);
            return TestResult::FAILED;
        }
    }

    if (strcmp(result, result_ref) != 0) {
        printf("Must be\n"
               "%s\n"
               "instead of\n"
               "%s\n", result_ref, result);
        return TestResult::FAILED;
    }
    return TestResult::PASSED;
}

TestResult test_cus_strstr(const char* str, const char* substr, char* (*test_func)(const char* str, const char* substr)) {
    char* result_ref = strstr(str, substr);
    char* result = (*test_func)(str, substr);

    if (result == result_ref)
        return TestResult::PASSED;
    else {
        printf("str:    %s\n", str);
        printf("substr: %s\n", substr);
        printf("Must be\n"
                "%s\n"
                "instead of\n"
                "%s\n", result_ref, result);
        return TestResult::FAILED;
    }

    return TestResult::PASSED;
}

void bruteforce_char(char* str1, size_t depth1, char* str2, size_t depth2,
                     unsigned int* test_num, unsigned int* test_success_num,
                     char* (*test_func)(const char* str, const char* substr)) {
    if (depth1 == 0 && depth2 == 0) {
        (*test_num)++;
        if (test_cus_strstr(str1, str2, test_func) == TestResult::PASSED) {
            (*test_success_num)++;
        } else {
            printf(CONSOLE_RED("Test %u failed.\n"), *test_num);
        }
        return;
    }
    else if (depth1 == 0) {
        depth2--;
        for (size_t i = 0; i < 3; i++) {
            str2[depth2] = 'a' + (char)i;
            bruteforce_char(str1, depth1, str2, depth2, test_num, test_success_num, test_func);
        }
        return;
    }
    depth1--;
    for (size_t i = 0; i < 3; i++) {
        str1[depth1] = 'a' + (char)i;
        bruteforce_char(str1, depth1, str2, depth2, test_num, test_success_num, test_func);
    }
}
