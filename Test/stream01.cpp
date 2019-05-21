/*
ファイル書き込みサンプル
*/
#include <iostream>
#include <fstream>


int main(){
    std::ofstream ofs("./test.txt");
    ofs << "Hi!" << std::endl;
    return 0;
}