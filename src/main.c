#include <stdio.h>
#include "propag.h"
#include "toolbox.h"

int main() {
    double p[6] = {-5.e3, 0., 0., 0., 1., 0.};
    Propag propag = new_propag("ICRS", 1.e13, p, 0., -86400. * 15., -10.);

    state_display(propag.p);
    printf("Time elapsed..");
    clock_t tic = clock();
    start_propag(&propag);
    clock_t toc = clock();
    printf(" %f\n", elapsed(tic, toc));
    state_display(propag.p);
}
