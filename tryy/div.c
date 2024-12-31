
// div.c
#include "operation.h"
 
int divide(int a, int b) {
    if (b == 0) {
        // Handle division by zero error
        return 0;
    }
    return a / b;
}