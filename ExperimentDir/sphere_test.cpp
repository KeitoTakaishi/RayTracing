#include "../Utils/vec3.h"
#include "../Utils/ray.h"
#include "../Utils/hit.h"
#include "../Utils/sphere.h"

int main(){
    Sphere s(Vec3(0.0, 0.0, 0.0), 1.0);
    Ray ray(Vec3(0.0, 0.0, -3.0), Vec3(0.0, 0.0, 1.0));
    Hit res;

    if(s.intersect(ray, res)){
        std::cout << "coef  : " << res.t << std::endl;
        std::cout << "Hit pos : " << res.hitPos << std::endl;
    }

    return 0;
}