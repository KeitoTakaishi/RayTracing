#include "../Utils/vec3.h"
#include "../Utils/ray.h"
#include "../Utils/hit.h"
#include "../Utils/camera.h"
#include "../Utils/image.h"
#include "../Utils/sphere.h"

int main(){
    Image img(512, 512);
    PinholeCamera cam(Vec3(0, 0, 0), Vec3(0, 0, -1), 1.0);
    Sphere sphere(Vec3(3.0, 0.0, -10.0), 1.0);

    //画像を生成
    for(int i = 0; i < img.height; i++){
        for(int j = 0; j < img.width; j++){
            double u = (2.0 * j - img.width) / img.width;
            double v = (2.0 * i - img.height) / img.height;


            Ray ray = cam.getRay(-u, -v);


            Vec3 col;
            Hit res;
            if(sphere.intersect(ray, res)){
                img.setPixel(i, j, (res.hitNormal + 1.0)/2.0);
            }else{
                img.setPixel(i, j, Vec3(0.0, 0.0, 0.0));
            }

            //img.setPixel(i, j, Vec3((double)i/img.width, (double)j/img.height,0.0));

        }
    }

    img.ppm_output("single_sphere_tracing.ppm");
    std::cout << "GenerateImg" << std::endl;
    return 0;
}
