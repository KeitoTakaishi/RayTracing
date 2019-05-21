#include <iostream>
#include "../Utils/vec3.h"
using namespace std;

int main(){
    Vec3 v1(1, 2, 3);
    Vec3 v2(4, 5, 6);

    cout << v1 + v2 << endl;
    cout << v1 - v2 << endl;
    cout << v1 * v2 << endl;
    cout << v1 / v2 << endl;
    cout << endl;

    cout << v1 + 1 << endl;
    cout << v1 - 1 << endl;
    cout << v1 * 2 << endl;
    cout << v1 / 2 << endl;
    cout << endl;


    cout << dot (v1, v2) << endl;
    cout << cross(v1, v2) <<  endl;
    cout << endl;

    cout << v1.length() << endl;

    return 0;
}