#include <iostream>
#include <string>
#include "big_int.h"


using std::string;


int main(int argc, const char * argv[]) {
    big_int bi_1 = (string) "-132354234652534686766556565756575656756568000988888885234672546";
    big_int bi_2 = (string) "34858635725542568723428309482340923756";
    big_int bi_3 = (string) "-34858635725542568723428309482340923756";
    big_int bi_5(0);

    std::cout << std::fixed;

    std::cout << bi_5 << " * " << bi_2 << " = " << (bi_5 * bi_2) << std::endl;
    std::cout << bi_2 << " - " << bi_2 << " = " << (bi_2 - bi_2) << std::endl;
    std::cout << bi_1 << " / " << bi_2 << " = " << bi_1 * bi_2 << std::endl;
    std::cout << bi_2 << " + " << bi_1 << " = " << bi_2 * bi_1 << std::endl;

    std::cout << bi_1 << " < " << bi_2 << " == " << (bi_1 < bi_2) << std::endl;
    std::cout << bi_1 << " > " << bi_2 << " == " << (bi_1 > bi_2) << std::endl;
    std::cout << bi_1 << " == " << bi_2 << " == " << (bi_1 == bi_2) << std::endl;
    std::cout << bi_1 << " != " << bi_2 << " == " << (bi_1 != bi_2) << std::endl;
    std::cout << bi_1 << " >= " << bi_2 << " == " << (bi_1 >= bi_2) << std::endl;
    std::cout << bi_1 << " <= " << bi_2 << " == " << (bi_1 <= bi_2) << std::endl;

    return 0;
}
