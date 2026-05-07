#include <unistd.h>
#include <string.h>
#include <stdio.h>

void    *safe_memcpy(void *dest, const void *src, size_t n) {
    if (!dest || !src)
        return NULL;
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    size_t i = 0;
    /*for an optimized and safer version of this function
    I would also check for the case where the source is
    shorter than the destination to avoid overlaps but since
    this is a memmove behaviour i did not add it*/
    while (i < n) {
        d[i] = s[i];
        i++;
    }
    return dest;
}

/*
int	main(void)
{
	char *src = "Ola";
	char dest[20];
	printf("My Func : %s\n", (char *)safe_memcpy(dest, src, 3));
	printf("My Func : %s\n", (char *)memcpy(dest, src, 3));
	return (0);
}
*/

#include <iostream>
#include <cstring>

void* safe_memcpy(void* dest, const void* src, size_t n) {
    if (!dest && !src)
        return nullptr;

    unsigned char* d = static_cast<unsigned char*>(dest);
    const unsigned char* s = static_cast<const unsigned char*>(src);

    size_t i = 0;
    while (i < n) {
        d[i] = s[i];
        i++;
    }
    return dest;
}

int main() {
    const char* src = "Ola";
    char dest[20];

    safe_memcpy(dest, src, 3);
    dest[3] = '\0'; // null-terminate for printing

    std::cout << "My Func : " << dest << std::endl;

    std::memcpy(dest, src, 3);
    dest[3] = '\0';

    std::cout << "std::memcpy : " << dest << std::endl;

    return 0;
}