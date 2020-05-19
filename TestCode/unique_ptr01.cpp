/*

unique_ptrの使用方法
1.コンストラクタで指定

2.resetを使用する
//std::unique_ptr<int> ptr2;
//ptr2.reset(new int(10));

3.make_unique
std::unique_ptr<int> ptr3=std::make_unique<int>(10);

*/

#include<iostream>
#include<memory>

class Hoge{
    private:
        std::unique_ptr<int> ptr;
    public:
        Hoge(int _val):ptr(new int(_val)){}
        ~Hoge(){
            std::cout << "Destractor" << std::endl;
        }
        
        int getValue()const{
            return *ptr;
        }
};

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
//コンストラクタで指定のパターン
int main(){
    //Hoge h(10);
    //Hoge h2(std::move(10));
    
    std::unique_ptr<Hoge> ptr(new Hoge(10));
    
    return 0;
}