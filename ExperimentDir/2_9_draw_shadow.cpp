#include <memory>
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
  aggregate.add(std::make_shared<Sphere>(Vec3(0.0, 0.0, -3.0), 1.0));
  aggregate.add(std::make_shared<Sphere>(Vec3(0.0, -1000.0, -10.0), 999.0));

  Vec3 sunDir = normalize(Vec3(1.0, 1.0, 1.0));

  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width; j++){
      double u = (2.0 * j - img.width)/(double)img.width;
      double v = (2.0 * i - img.height)/(double)img.height;
      Ray ray = cam.getRay(-u, -v);

      Vec3 col;
      Hit res;

      if(aggregate.intersect(ray, res)){
        Ray shadowRay(res.hitPos + 0.0001 * res.hitNormal, sunDir);
        Hit res_temp;
        if(!aggregate.intersect(shadowRay, res_temp)){
          col = std::max(dot(res.hitNormal, sunDir), 0.0) * Vec3(1.0);
        }
      }
      img.setPixel(i, j, col);
    }
  }
  img.ppm_output("draw_shadow.ppm");
  return 0;
}
