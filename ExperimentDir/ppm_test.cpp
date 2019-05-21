// 結果: i_view ppm_test.ppm
#include <iostream>
#include <fstream>

int main(){
    std::ofstream file("ppm_test.ppm");
    
    file << "P3" << std::endl;
    file << 512 << " " << 512 << std::endl;
    file << 512 << std::endl; //諧調数
    for(int i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
            int r = i/512.0 * 255;
            int g = j/512.0 * 255;
            int b = 255;
            file << r << " " << g << " " << b << std::endl;
        }
    }

    file.close();
    return 0;
}