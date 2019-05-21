#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include "vec3.h"
#include "ray.h"
#include "hit.h"

class Sphere{
    public:
        Vec3 center;
        double radius;
        Sphere(const Vec3& _center, const double _radius): center(_center), radius(_radius){};
        
        bool intersect(const Ray& ray, Hit& res) const{
            double b = dot(ray.direction, ray.original - center);
            std::cout << "ray.direction = " << ray.direction << ", " << "ray.original = "  << ray.original << std::endl;
            double c = (ray.original - center).length2() - radius*radius;
            std::cout << "ray.original = " <<ray.original << ", " << "spheres center := " << center << ", " << "radius = " << radius << std::endl;

            double D = b*b - c;

            //解の候補距離
            double t1 = -b - std::sqrt(D);
            double t2 = -b + std::sqrt(D);

            std::cout << "t1 = " << t1 << ", " <<  "t2 = " << t2 << std::endl;
            if(t1 > 10000 | t2 < 0) return false;
            double t = t1;
            if(t < 0){
                t = t2;
                if(t2 > 10000) return false;
            }

            res.t = t;
            res.hitPos = ray(t);
            res.hitNormal = normalize(res.hitPos - center);
            res.hitSphere = this;

            return true;
        };
};
#endif
