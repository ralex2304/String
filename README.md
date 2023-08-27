# Custom stdio.h and string.h functions implementation

## Features

### Functions

Prefix `cus` means "custom"

- `int cus_puts(const char* str)`

- `char* cus_strchr(const char* str, const int symbol)`

- `size_t cus_strlen(const char* str)`

- `char* cus_strcpy(char* dest, const char* src)`

- `char* cus_strncpy(char* dest, const char* src, size_t cnt)`

- `char* cus_strcat(char* dest, const char* src)`

- `char* cus_strncat(char* dest, const char* src, size_t cnt)`

- `char* cus_fgets(char* str, int cnt, FILE* stream)`

- `char* cus_strdup(const char* str)`

- `ssize_t cus_getline(char** str, size_t* cnt, FILE* stream)`

- `strstr() implementations:`

    - `char* cus_strstr_simple(const char* str, const char* substr)` - O(n*m) algorithm

    - `char* cus_strstr_kmp(const char* str, const char* substr)` - O(n+m) Knutt Morris Pratt algorithm

    - `char* cus_strstr_bm(const char* str, const char* substr)` - O(n/m) - O(n*m) Boyer Moore algorithm

    - `char* cus_strstr_hash(const char* str, const char* substr)` - O(n+m) reversed polynomial hash algorithm

### Tests

Most of the functions above have functions with prefix `test_` for unit tests. cus_strstr() tests are generated recursively.

## Credits

MIPT summer school task
