#include "custom_strings.h"

int cus_puts(const char* str) {
    assert(str);

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (putc(str[i], stdout) == EOF)
            return EOF;
    }
    return putc('\n', stdout);
}

char* cus_strchr(const char* str, const int symbol) {
    assert(str);

    size_t i = 0;
    do {
        if (str[i] == symbol)
            return const_cast<char*>(str) + i;

    } while (str[i++] != '\0');

    return nullptr;
}

size_t cus_strlen(const char* str) {
    assert(str);

    for (size_t i = 0;; i++) {
        if (str[i] == '\0')
            return i;
    }
}

char* cus_strcpy(char* dest, const char* src) {
    assert(dest);
    assert(src);

    size_t i = 0;
    do {
        dest[i] = src[i];
    } while (src[i++] != '\0');

    return dest;
}

char* cus_strncpy(char* dest, const char* src, size_t cnt) {
    assert(dest);
    assert(src);

    size_t i = 0;
    for (i = 0; src[i] != '\0' && i < cnt; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest;
}

char* cus_strcat(char* dest, const char* src) {
    assert(dest);
    assert(src);

    char* dest_cat = cus_strchr(dest, '\0');
    assert(dest_cat);

    cus_strcpy(dest_cat, src);

    return dest;
}

char* cus_strncat(char* dest, const char* src, size_t cnt) {
    assert(dest);
    assert(src);

    char* dest_cat = cus_strchr(dest, '\0');
    assert(dest_cat);

    cus_strncpy(dest_cat, src, cnt);

    return dest;
}

char* cus_fgets(char* str, int cnt, FILE* stream) {
    assert(str);
    assert(stream);

    size_t i = 0;
    int c = '\0';

    for (i = 0; i < (size_t)cnt - 1 && c != '\n'; i++) {
        c = getc(stream);
        if (c == EOF)
            return nullptr;
        str[i] = (char)c;
    }
    str[i] = '\0';

    return str;
}

char* cus_strdup(const char* str) {
    assert(str);

    char* output = (char*)malloc((cus_strlen(str) + 1) * sizeof(char));
    if (output == nullptr)
        return nullptr;

    cus_strcpy(output, str);
    return output;
}

ssize_t cus_getline(char** str, size_t* cnt, FILE* stream) {
    assert(str);
    assert(*str || *cnt); // check for *cnt > 0 if *str != nullptr
    assert(stream);

    static const size_t BEGIN_ALLOC_SIZE = 256;

    if (*str == nullptr) {
        *cnt = BEGIN_ALLOC_SIZE;
        *str = (char*)malloc(*cnt * sizeof(char));

        if (*str == nullptr)
            return -1;
    }

    size_t i = 0;
    int c = '\0';
    for (i = 0; c != '\n'; i++) {
        if (i >= *cnt - 1)
            if (!geom_realloc(str, cnt))
                return -1;

        c = fgetc(stream);
        if (c == EOF)
            return -1;
        *str[i] = (char)c;
    }
    *str[i] = '\0';

    return i;
}

bool geom_realloc(char** str, size_t* n) {
    *n *= 2;
    *str = (char*)realloc(*str, (*n) * sizeof(char));
    if (*str == nullptr)
        return false;
    return true;
}

char* cus_strstr_simple(const char* str, const char* substr) {
    assert(str);
    assert(substr);

    for (size_t i = 0; str[i] != '\0'; i++) {
        bool is_equal = true;
        char first_c = str[i];
        size_t same_len = 0;

        for (size_t j = 0; substr[j] != '\0'; j++) {
            if (str[i + j] != substr[j]) {
                is_equal = false;
                i += j - same_len;
                break;
            }

            if (str[i + j] == first_c)
                same_len++;
            else if (first_c != '\0') {
                same_len++;
                first_c = '\0';
            }

        }

        if (is_equal)
            return const_cast<char*>(str) + i;
    }
    return nullptr;
}

char* cus_strstr_kmp(const char* str, const char* substr) {
    assert(str);
    assert(substr);

    size_t substr_len = cus_strlen(substr);

    size_t str_len = cus_strlen(str);

    size_t* pref = (size_t*)calloc(str_len + substr_len + 1, sizeof(size_t)); ///< prefix function
    if (pref == nullptr)
        return nullptr;

    for (size_t i = 1; i < str_len + substr_len + 1; i++) {
        size_t j = pref[i - 1];

        while ((j > 0) && (*ptr_emulate(i, substr, str, substr_len, "") != *ptr_emulate(j, substr, str, substr_len, "")))
            j = pref[j - 1];

        if (*ptr_emulate(i, substr, str, substr_len, "") == *ptr_emulate(j, substr, str, substr_len, ""))
            j++;

        pref[i] = j;
        if (j == substr_len) {
            free(pref);
            return const_cast<char*>(str) + i - 2 * substr_len;
        }
    }

    free(pref);
    return nullptr;
}

const char* ptr_emulate(size_t i, const char* prefix, const char* str, size_t prefix_len, const char* empty) {
    if (i == prefix_len) return empty;
    else if(i < prefix_len) return prefix + i;
    else return str + i - prefix_len - 1;
}

char* cus_strstr_bm(const char* str, const char* substr) {
    assert(str);
    assert(substr);

    size_t preproc[256] = {};

    size_t substr_len = cus_strlen(substr);

    for (size_t i = 0; i < 256; i++)
        preproc[i] = substr_len;

    for (size_t i = 0; i < substr_len; i++) {
        preproc[(size_t)substr[i]] = __min(preproc[(size_t)substr[i]], substr_len - i - 1);
    }

    size_t str_len = cus_strlen(str);

    for (size_t i = substr_len - 1; i < str_len; i++) {
        while (i < str_len && preproc[(size_t)str[i]] != 0)
            i += preproc[(size_t)str[i]];

        if (i >= str_len) break;

        if (strncmp(substr, str + i - substr_len + 1, substr_len) == 0)
            return const_cast<char*>(str) + i - substr_len + 1;
    }

    return nullptr;
}


char* cus_strstr_hash(const char* str, const char* substr) {
    assert(str);
    assert(substr);

    size_t substr_len = cus_strlen(substr);

    Hash substr_hash = hash_create(substr, substr_len);

    Hash str_hash = hash_create(str, substr_len);

    for (size_t i = 0; str[i + substr_len - 1] != '\0' ; i++) {
        if (str_hash.hash == substr_hash.hash) {
            if (strncmp(str + i, substr, substr_len) == 0) {
                return const_cast<char*>(str) + i;
            }
        }
        hash_move(&str_hash, str[i], str[i + substr_len]);
    }
    return nullptr;
}
