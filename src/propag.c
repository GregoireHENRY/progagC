#include "propag.h"

double G = 6.67408e-11;

Propag new_propag(char* frame, double m, double* p, double t0, double tf, double dt) {
    Propag propag = {frame, m, p, t0, tf, dt, 0.};
    return propag;
}

void start_propag(Propag *propag) {
    for (int ii=0; fabs(propag->ti) < fabs(propag->tf); ii++) {
        propag->ti += propag->dt;
        double* k1 = rkfn(propag->p, propag->m, propag->dt, propag->p, 0.);
        double* k2 = rkfn(propag->p, propag->m, propag->dt, k1, 1./2.);
        double* k3 = rkfn(propag->p, propag->m, propag->dt, k2, 1./2.);
        double* k4 = rkfn(propag->p, propag->m, propag->dt, k3, 1.);
        rk_next(propag->p, k1, k2, k3, k4);
    }
}

void state_display(double *p) {
    for (int ii=0; ii<6; ii++) printf("%20.10f", p[ii]);
    printf("\n");
}

double* rkfn(double* p, double m, double dt, double* o_k, double f) {
    double* k = malloc(6 * sizeof(double));
    double* p_k = malloc(6 * sizeof(double));
    for (int ii=0; ii<6; ii++) {
        p_k[ii] = p[ii] + o_k[ii] * f;
    }
    double d = norm(p_k[0], p_k[1], p_k[2]);
    double d2 = d * d;
    double F = -G * m / d2 * dt;
    k[0] = p_k[3] * dt;
    k[1] = p_k[4] * dt;
    k[2] = p_k[5] * dt;
    k[3] = unitx(p_k[0], p_k[1], p_k[2]) * F;
    k[4] = unity(p_k[0], p_k[1], p_k[2]) * F;
    k[5] = unitz(p_k[0], p_k[1], p_k[2]) * F;
    return k;
}

void rk_next(double* p, double *k1, double *k2, double *k3, double *k4) {
    for (int ii=0; ii<6; ii++) {
        p[ii] = p[ii] + (k1[ii] + 2 * (k2[ii] + k3[ii]) + k4[ii]) / 6.;
    }
}
