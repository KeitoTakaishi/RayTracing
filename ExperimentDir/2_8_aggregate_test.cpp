#include<memory>
#include "../Utils/vec3.h"
#include "../Utils/ray.h"
#include "../Utils/hit.h"
#include "../Utils/sphere.h"
#include "../Utils/camera.h"
#include "../Utils/image.h"
#include "../Utils/aggregate.h"


int main(){
  Image img(512, 512);
  PinholeCamera cam(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, -1.0), 1);
  Aggregate aggregate;
  aggregate.add(std::make_shared<Sphere>(Vec3(0.0, 0.0, -10.0), 1.0));
  aggregate.add(std::make_shared<Sphere>(Vec3(0.0, -1000.0, -10.0), 999.0));


  //std::cout << aggregate.vp_spheres.size() << std::endl;
  //std::cout << aggregate.vp_spheres[0]->center << std::endl;
  //std::cout << aggregate.vp_spheres[1]->center << std::endl;
  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width; j++){
      //double u = (2.0 * i - img.width)/img.width;
      //double v = (2.0 * j - img.height)/img.height;

      double u = (2.0 * j - img.height)/img.height;
      double v = (2.0 * i - img.width )/img.width;
      Ray ray = cam.getRay(-u, -v);

      Hit res;
      if(aggregate.intersect(ray, res)){
        img.setPixel(i, j, (res.hitNormal + 1.0)/2.0);
      }else{
        img.setPixel(i, j, Vec3(0.0, 0.0, 0.0));
      }
    }
  }
  img.ppm_output("aggregate_test.ppm");

  return 0;
}
