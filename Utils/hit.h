#ifndef HIT_H
#define HIT_H
#include "vec3.h"

class Sphere;

class Hit {
    public:
        double t;//衝突距離
        Vec3 hitPos;
        Vec3 hitNormal;
        const Sphere* hitSphere;

        Hit(){
            t = 10000;
        };
};
#endif
