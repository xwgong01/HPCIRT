# ifndef PUSHER_HPP
# define PUSHER_HPP

#include <cmath>
#include <iostream>
#include <vector>
#include <array>
using real_t = double;
// EB is [E1, E2, E3, B1, B2, B3]
using EB_t = std::array<real_t, 6>;
using coord_t = std::array<real_t, 3>;

real_t NORM_SQR(const coord_t& v){
    return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
}

namespace pusher{
    

    template <typename T>
    class Pusher{
        public:
            Pusher( real_t dt, real_t q, real_t m, EB_t EB, coord_t x, coord_t v) :
                dt {dt}, 
                q {q},
                m {m},
                EB {EB},
                x {x},
                v {v}
                {}
            
            void updateV() {
                coord_t v_m, t1, v1_s, s, v1_p;
                real_t tsq;
                v_m[0] = v[0] + q/m * EB[0] * dt / 2;
                v_m[1] = v[1] + q/m * EB[1] * dt / 2;
                v_m[2] = v[2] + q/m * EB[2] * dt / 2;
                
                t1[0] = q/m * EB[3] * dt / 2;
                t1[1] = q/m * EB[4] * dt / 2;
                t1[2] = q/m * EB[5] * dt / 2;

                v1_s[0] = v_m[0] + (v_m[1] * t1[2] - v_m[2] * t1[1]);
                v1_s[1] = v_m[1] + (v_m[2] * t1[0] - v_m[0] * t1[2]);
                v1_s[2] = v_m[2] + (v_m[0] * t1[1] - v_m[1] * t1[0]);

                tsq = NORM_SQR(t1);
                s[0] = 2 * t1[0] / (1 + tsq);
                s[1] = 2 * t1[1] / (1 + tsq);
                s[2] = 2 * t1[2] / (1 + tsq);
                
                v1_p[0] = v1_s[0] + (v1_s[1] * s[2] - v1_s[2] * s[1]);
                v1_p[1] = v1_s[1] + (v1_s[2] * s[0] - v1_s[0] * s[2]);
                v1_p[2] = v1_s[2] + (v1_s[0] * s[1] - v1_s[1] * s[0]);  
                v1_p[0] += q/m * EB[0] * dt / 2;
                v1_p[1] += q/m * EB[1] * dt / 2;
                v1_p[2] += q/m * EB[2] * dt / 2;
                v[0] = v1_p[0];
                v[1] = v1_p[1];
                v[2] = v1_p[2];
                return;
            }
            

            auto ParticlePush() -> coord_t {
                updateV();
                return v;
            }
        private:
            real_t dt, q, m;
            EB_t EB;
            coord_t x, v;

    };

}
# endif