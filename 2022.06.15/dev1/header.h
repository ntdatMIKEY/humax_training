// to look for min() function
#include "mylib.h"
// macros
#define SPEED_MAX 10 /* comment */
#define SPEED_INC 1 /* will be removed */
#define SPEED_UP(x) min((x) + SPEED_INC, SPEED_MAX)
