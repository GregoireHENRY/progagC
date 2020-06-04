#ifndef PROPAG_H
#define PROPAG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"

extern double G;

typedef struct {
    char* frame;
    double m;
    double* p;
    double t0, tf, dt, ti;
} Propag;

Propag new_propag(char*, double, double*, double, double, double);
void start_propag(Propag *propag);
void state_display(double* p);
double* rkfn(double *, double, double, double *, double);
void rk_next(double *, double *, double *, double *, double *);

#endif
