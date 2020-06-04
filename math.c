#include "math.h"

double unitx(double x, double y, double z) {
    return x / norm(x, y, z);
}
double unity(double x, double y, double z) {
    return y / norm(x, y, z);
}
double unitz(double x, double y, double z) {
    return z / norm(x, y, z);
}
double dot(double x1, double y1, double z1, double x2, double y2, double z2) {
    return x1 * x2 + y1 * y2 + z1 * z2;
}
double norm(double x, double y, double z) {
    return sqrt(dot(x, y, z, x, y, z));
}
