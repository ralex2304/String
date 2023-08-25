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

    const char* output = nullptr;
    size_t i = 0;
    do {
        if (str[i] == symbol) {
            output = str + i;
            return const_cast<char*>(output);
        }
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
    str[i] = '\0';

    return i;
}

bool geom_realloc(char** str, size_t* n) {
    *n *= 2;
    *str = (char*)realloc(*str, (*n) * sizeof(char));
    if (*str == nullptr)
        return false;
    return true;
}
