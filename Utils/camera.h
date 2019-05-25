#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "ray.h"
/*
Image Sensorがあり，そこからpinholeへ光が収束して
ピクセルへ当たる．
*/
class Camera {
    public:
        Vec3 camPos;
        Vec3 camForward;
        Vec3 camRight;
        Vec3 camUp;

        Camera(const Vec3& _camPos, const Vec3& _camForward) :
        camPos(_camPos), camForward(_camForward) {
            orthonormalBasis(camForward, camRight, camUp);

            std::cout << "camPos" << camPos << std::endl;
            std::cout << "camForward" << camForward << std::endl;
            std::cout << "camRight" << camRight << std::endl;
            std::cout << "camUp" << camUp << std::endl;
        };

        virtual Ray getRay(double u, double v) const = 0;
};
//継承，コンストラクタ
class PinholeCamera : public Camera {
    public:
        double pinholeDist; //イメージセンサーの中心からピンホールまでの距離
        PinholeCamera(const Vec3& _CamPos, const Vec3& _camForward, double _pinholelDist)
        : Camera(_CamPos, _camForward), pinholeDist(_pinholelDist){};

        Ray getRay(double u, double v) const {

            Vec3 pinholePos = camPos + pinholeDist * camForward;

            Vec3 sensorPos = camPos + u * camRight + v * camUp;

            //Rayの原点，方向
            return Ray(sensorPos, normalize(pinholePos - sensorPos));
        }
         
};
#endif