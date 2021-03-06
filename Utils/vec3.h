#ifndef VEC3_H
#define VEC3_H
#include <iostream>
#include <cmath>

class Vec3 {
    public:
        double x;
        double y;
        double z;

        Vec3(){x = y = z = 0;}
        Vec3(double _x){x = y = z = _x;}
        Vec3(double _x, double _y, double _z){x = _x,  y = _y, z = _z;}
        /*
        constメンバ関数にすることでメンバ変数の変更を禁止する
        *の前のcons は参照するオブジェクトが不変
        後の const はアドレスが不変である事を示す.m

        また参照はnullを許容しないので，nullの可能性のあるものは必ずpointer
        参照はconstと一緒に使うのが理想
        */
        double length() const{
            return std::sqrt(x*x + y*y + z*z);
        };

        double length2() const{
            return (x*x + y*y + z*z);
        };
};

//vector calc
Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 operator-(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator*(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

Vec3 operator/(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

//vectorxscalor calc
Vec3 operator+(const Vec3& v, double k){
    return Vec3(v.x + k, v.y + k, v.z + k);
}

Vec3 operator-(const Vec3& v, double k){
    return Vec3(v.x - k, v.y - k, v.z - k);
}

Vec3 operator*(const Vec3& v, double k){
    return Vec3(v.x * k, v.y * k, v.z * k);
}

Vec3 operator/(const Vec3& v, double k){
    return Vec3(v.x / k, v.y / k, v.z / k);
}

// dot
double dot(const Vec3& v1, const Vec3& v2){
    return(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

//cross
Vec3 cross(const Vec3& v1, const Vec3& v2){
    return Vec3(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x-v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

Vec3 normalize(const Vec3& v){
    return v / v.length();
}

void orthonormalBasis(const Vec3& v1, Vec3& v2, Vec3& v3){
    if(std::abs(v1.x) > 0.9) v2= Vec3(0, 1, 0);
    else v2 = Vec3(1, 0, 0);

    v2 = normalize(v2 - dot(v1, v2) * v1);

    v3 = cross(v1, v2);
}

std::ostream& operator<<(std::ostream& stream, const Vec3& v){
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}
#endif
