//reset関数を用いることでunique_ptrを使用出来る
#include <iostream>

class Hoge1{
    private:
        int num = 10;
    public:
        Hoge1(int _n) : num(_n){
            std::cout << num << std::endl; 
            std::cout << "Constractor" << std::endl;
        }

        ~Hoge1(){
            std::cout << "Destractor" << std::endl;
        }
};

int main(){
    std::unique_ptr<Hoge1> ptr;
    ptr.reset(new Hoge1(10));

}