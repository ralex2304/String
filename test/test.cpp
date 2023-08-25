#include "test.h"

void test_all() {
    unsigned int test_num = 0;
    unsigned int test_success_num = 0;

    for (int i = 0; i < 9; i++) {
        test_num++;
        if (test_cus_strchr("12345678", '0' + i) == TestResult::PASSED) {
            printf(CONSOLE_GREEN("Test %u passed!\n"), test_num);
            test_success_num++;
        } else {
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
        }
    }
    test_num++;
    if (test_cus_strchr("12345678", '\0') == TestResult::PASSED) {
        printf(CONSOLE_GREEN("Test %u passed!\n"), test_num);
        test_success_num++;
    } else {
        printf(CONSOLE_RED("Test %u failed.\n"), test_num);
    }


    const char* buf = "123456789";
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strlen(buf + i) == TestResult::PASSED) {
            printf(CONSOLE_GREEN("Test %u passed!\n"), test_num);
            test_success_num++;
        } else {
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
        }
    }

    buf = "123456789";
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strcpy(buf + i) == TestResult::PASSED) {
            printf(CONSOLE_GREEN("Test %u passed!\n"), test_num);
            test_success_num++;
        } else {
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
        }
    }

    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strncpy("12345678", i) == TestResult::PASSED) {
            printf(CONSOLE_GREEN("Test %u passed!\n"), test_num);
            test_success_num++;
        } else {
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
        }
    }

    buf = "123456789";
    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strcat(buf + i) == TestResult::PASSED) {
            printf(CONSOLE_GREEN("Test %u passed!\n"), test_num);
            test_success_num++;
        } else {
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
        }
    }

    for (int i = 0; i < 10; i++) {
        test_num++;
        if (test_cus_strncat("12345678", i) == TestResult::PASSED) {
            printf(CONSOLE_GREEN("Test %u passed!\n"), test_num);
            test_success_num++;
        } else {
            printf(CONSOLE_RED("Test %u failed.\n"), test_num);
        }
    }

    if (test_num == test_success_num) {
        printf(CONSOLE_GREEN("All %u tests passed\n"), test_success_num);
    }


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
