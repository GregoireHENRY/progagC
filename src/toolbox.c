#include "time.h"

double elapsed(clock_t tic, clock_t toc) {
    return (toc - tic) / CLOCKS_PER_SEC;
}
