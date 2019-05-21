/*
operatorのoverloadに関しての検証コード
*/
#include <iostream>

class Test{
    public:

        /*
        int operator+(){
            return 2;
        };
        */

        /*02
        クラスオブジェクトオブジェクトの後ろに()をつけて
        関数呼び出しの形式で使用可能．関数オブジェクトという
        */
        int operator()(int iValue){
            return 2 * iValue;
        };
};

/*
グローバ関数として定義する場合，第一引数にクラスのオブジェクトを渡す必要がある
引数としてc++の組み込み型の変数を用いることはできない
*/
int operator+(Test& test){
    return 20;
}

int main(){
    Test test;
    
    //01
    int v = + test;
    std::cout << v << std::endl;

    //02
    v = test(1);
    //std::cout << v << std::endl;
    return 0;
}