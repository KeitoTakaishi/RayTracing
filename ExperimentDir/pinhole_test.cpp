#include "../Utils/vec3.h"
#include "../Utils/ray.h"
#include "../Utils/image.h"
#include "../Utils/camera.h"

int main(){
    Image img(512, 512);
    PinholeCamera cam(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, -1.), 1.0);
    for(int i = 0; i < img.width; i++){
        for(int j = 0; j < img.height; j++){
            double u = (2.0*i - img.width) / img.width;
            double v = (2.0*j - img.height) / img.height;
            Ray ray = cam.getRay(-u, -v);
            Vec3 col = (ray.direction+1.0)/2.0;
            img.setPixel(i, j, col);
        }
    }
    img.ppm_output("pinhole_test.ppm");
    return 0;
}
