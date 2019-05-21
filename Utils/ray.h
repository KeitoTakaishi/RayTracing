#ifndef RAY_H
#define RAY_H 
#include <iostream>
#include "vec3.h"

class Ray {
    public:
        Vec3 original;
        Vec3 direction;

        //: 初期化
        Ray(const Vec3& _original, const Vec3& _direction) : original(_original), direction(_direction){};

        //()関数のように呼び出しできるように
        Vec3 operator()(double t) const{
            return original + t * direction;
        };
};

std::ostream& operator<<(std::ostream& stream, const Ray& ray){
    stream << "origin: " << ray.original << "directopn:" << ray.direction;  
    return stream;
}
#endif