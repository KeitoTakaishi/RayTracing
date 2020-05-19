/*
通常のポインタではnewでメモリ確保した後，deleteにてメモリ開放をしてあげないと
destractorが呼ばれない
*/
#include <iostream>

class Hoge{
    public:
        int num;
        Hoge(){
            num = 10;
            std::cout << "Constractor" << std::endl;
        }

        ~Hoge(){
            std::cout << "DesConstractor" << std::endl;
        }
};

int main(){
    Hoge* hoge = new Hoge();
    std::cout << hoge->num << std::endl;
    //delete hoge;
    return 0;
}