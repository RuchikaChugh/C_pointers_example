//gcc 4.9.3

#include  <stdio.h>

typedef unsigned char             u_int8;
typedef signed char               s_int8;

typedef unsigned short            u_int16;
typedef signed short              s_int16;

typedef unsigned long             u_int32;
typedef signed long               s_int32;

typedef unsigned long long        u_int64;
typedef signed long long          s_int64;

void printCode(int var) {
    printf("=== Pointer Setup ===\n");
    printf("------------------------------------------------------------------\n\n");
    printf("u_int8 var = %d;       // Ordinary variable\n", var);
    printf("u_int8 *ptr = NULL;    // Pointer to a unsigned 8-bit int location\n\n");
    printf("ptr = &var;            // Store address of 'var' in 'ptr'\n\n");
    printf("------------------------------------------------------------------\n\n\n");
}


int main(int argc, char *argv[]) {
    u_int8 var = 3;        // Ordinary variable
    u_int8 *ptr = NULL;    // Pointer to a unsigned 8-bit int location

    ptr = &var;            // Store address of 'var' in 'ptr'

    printCode(var);

    /*
        Can use %p to print full 48-bit address, but %x is acceptable to display
        32-bit address.
        48-bit form = canonical form address
        See: https://en.wikipedia.org/wiki/X86-64#Canonical_form_addresses
        Using %x will cause compiler to throw a warning as %x expects an
        unsigned int.
        Upper two bytes will always be the same for all variable's addresses
        anyway, not using enough memory to go to new page. (2^32 bits)
    */
    printf("Address of 'var':                   %x\n", &var);
    printf("Address of 'ptr':                   %x\n", &ptr);
    printf("Address/value stored in 'ptr':      %x\n",  ptr);
    printf("Value of 'var':                     %d\n",  var);
    printf("Value pointed to by '*ptr':         %d\n", *ptr);

    *ptr = 222;
    printf("\n\n*ptr = %d\n\n", *ptr);

    printf("Address of 'var':                   %x\n", &var);
    printf("Address of 'ptr':                   %x\n", &ptr);
    printf("Address/value stored in 'ptr':      %x\n",  ptr);
    printf("Value of 'var':                     %d\n",  var);
    printf("Value pointed to by '*ptr':         %d\n", *ptr);

    return 0;
}