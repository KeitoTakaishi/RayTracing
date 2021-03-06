#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include <cmath>
#include "string"
#include "vec3.h"
#include "util.h"

class Image{
    public:
    int width;
    int height;
    Vec3* data;

    Image(int _width, int _height) : width(_width), height(_height){
        data = new Vec3[width*height];
    };

    ~Image(){
        delete[] data;
    };

    //メンバ変数を変更するわけではないので文末にconst
    Vec3 getPixel(int i, int j) const{
        return data[i * width + j];
    };

    void setPixel(int i, int j, const Vec3& c){
      //data[i + width * j] = c;
      data[i * width + j] = c;
    };

    void addPixel(int i, int j, const Vec3& c){
      //data[i + width * j] = c;
      data[i * width + j] = c + data[i * width + j];
    };

    void divide(const double& k) {
      for(int r = 0; r < height; r++) {
        for(int c = 0; c < width; c++) {
          setPixel(r, c, getPixel(r, c)/k);
        }
      }
      return;
    }
    void ganmma_correction(){
        for(int i = 0; i < i < width; i++){
            for(int j = 0; j < height; j++){
                Vec3 c = this->getPixel(i, j);
                this->setPixel(i, j, Vec3(std::pow(c.x, 1/2.2), std::pow(c.y, 1/2.2), std::pow(c.z, 1/2.2)));
            }
        }
    };

    void ppm_output(const std::string& filename) const{
        std::ofstream file(filename);
        file << "P3" << std::endl;
        file << width << " " << height << std::endl;
        file << "255" << std::endl;

        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                Vec3 c = this->getPixel(i, j);
                int r = clamp(int(255*c.x), 0, 255);
                int g = clamp(int(255*c.y), 0, 255);
                int b = clamp(int(255*c.z), 0, 255);
                file << r << " " << g << " " << b << std::endl;
            }
        }
        file.close();
    };
};
#endif
