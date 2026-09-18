#include "Pusher.hpp"
#include <cmath>
#include <iostream>

using namespace pusher;

int main(){
    const real_t dt = 0.01;
    real_t t = 0.0;
    const real_t tmax = 100.0;
    const coord_t x0 = {0, 0, 0};
    const coord_t v0 = {0.1, 0, 0};
    const real_t q = 1;
    const real_t m = -1;
    const EB_t EB = {0, 0, 0, 0, 0, 1};

    coord_t v = v0;
    coord_t x = x0;

    Pusher<real_t> pusher(dt, q, m, EB, x, v);
    while (t < tmax) {
        v = pusher.ParticlePush();
        x[0] += v[0] * dt;
        x[1] += v[1] * dt;
        x[2] += v[2] * dt;
        t += dt;
        std::cout << "t: " << t << ", x: (" << x[0] << ", " << x[1] << ", " << x[2] << "), v: (" << v[0] << ", " << v[1] << ", " << v[2] << ")" << std::endl;
    }
    return 0;




}