#include <memory>
#include <random>
#include <omp.h>
#include "../Utils/vec3.h"
#include "../Utils/ray.h"
#include "../Utils/hit.h"
#include "../Utils/sphere.h"
#include "../Utils/camera.h"
#include "../Utils/image.h"
#include "../Utils/aggregate.h"


std::random_device rnd_dev;
std::mt19937 mt(rnd_dev());
std::uniform_real_distribution<> dist(0.0, 1.0);

inline double rnd(){
  return dist(mt);
}
int main(){
  const int N = 50;
  Image img(512, 512);
  PinholeCamera cam(Vec3(0.0), Vec3(0.0, 0.0, -1.0), 1.0);

  Aggregate aggregate;
  aggregate.add(std::make_shared<Sphere>(Vec3(0.0, 0.0, -3.0), 1.0));
  aggregate.add(std::make_shared<Sphere>(Vec3(0.0, -1000.0, -10.0), 999.0));

  Vec3 sunDir = normalize(Vec3(1.0, 1.0, 1.0));

  #pragma omp parallel for schedule(dynamic, 1)
    for(int k = 0; k < N; k++){
      for(int i = 0; i < img.width; i++){
        for(int j = 0; j < img.height; j++){
          double u = (2.0 * (j + rnd()) - img.width)/(double)img.width;
          double v = (2.0 * (i + rnd()) - img.height)/(double)img.height;
          Ray ray = cam.getRay(-u, -v);


          Vec3 col;
          Hit res;

          if(aggregate.intersect(ray, res)){
            Ray shadowRay(res.hitPos + 0.0001 * res.hitNormal, sunDir);
            Hit res_temp;
            if(!aggregate.intersect(shadowRay, res_temp)){
              //Vec3 eye = -1.0 * ray.direction;
              //eye = (eye + sunDir)*0.5;
              //float spec = std::max(dot(eye, res.hitNormal), 0.0);
              //spec = pow(spec, 50.0);
              col = std::max(dot(res.hitNormal, sunDir), 0.0) * Vec3(1.0);
            }
          }
          img.addPixel(i, j, col);
        }
      }
      std::cout << "N : " << k << std::endl;
    }
  img.divide(N);
  img.ppm_output("SSAA_parallel.ppm");
  return 0;
}
