#include <iostream>
#include <string>
#include "big_int.h"


using std::string;


int main(int argc, const char * argv[]) {
//    std::cout << INT_MAX << std::endl;

//    string test("1234453457777878456456456");
//    std::cout << test[14234];

//    std::reverse(test.begin(), test.end());
//    std::cout << test;

    big_int bi_1 = (string) "132354234652534686766556565756575656756568000988888885234672546";
    big_int bi_2 = (string) "34858635725542568723428309482340923756";
    big_int bi_3 = (string) "34858635725542568723428309482340923756";
    big_int bi_4 = (string) "34858635725542568723428309482340923757";
//                         "85666642815406514531412163519485208926"
    big_int bi_5(0);
    big_int bi_6 = (string) "348586357255425687234283094823409237560000000000000000000000000";

    std::cout << std::fixed;

//    bool res = bi_1 > bi_2;
//    std::cout << res << std::endl;



//    std::cout << std::to_string(11242424)[0] << std::endl;
//    std::cout << big_int(-1230) << std::endl;
//    std::cout << bi_1.div(bi_2) << std::endl;
//    std::cout << big_int("43545637567456") / big_int(44) << std::endl;
//    std::cout << (bi_1 > bi_6) << std::endl;
//    std::cout << (bi_1 < bi_6) << std::endl;
//    std::cout << (bi_1 == bi_6) << std::endl;
//    std::cout << bi_1.sub(bi_6) << std::endl;
//    std::cout << bi_2.mul(bi_1) << std::endl;

//    std::cout << big_int("1900000000000000000000000").add(big_int("100000000000000000000000")) << std::endl;
    std::cout << (big_int(1234253425) += 134) << std::endl;


//    auto res = bi_2.mul(bi_5);
//    std::cout << bi_2.mul(bi_5) << std::endl;
//    std::cout << bi_5.mul(bi_2) << std::endl;


//    auto res = bi_2.sub(bi_2);
//    res.debug_print();
//    std::cout << res << std::endl;
//    std::cout << bi_1.mul(big_int("10000000000000000000")) << std::endl;

//    std::cout << big_int(bi_1) << std::endl;
//    res.nums_m.push_back(0);
//    res.debug_print();

//    std::cout << bi_5.mul(bi_2) << std::endl;
//
//    bi_5.mul(bi_2).debug_print();
//    big_int res = bi_1.add(bi_2);
//    std::cout << res << std::endl;
//    res.debug_print();
//

//    big_int res = bi_1.sub(bi_2);
//    std::cout << res << std::endl;
//    res.debug_print();

//    std::cout << bi_1.get_num_of_digits() << std::endl;
//    std::cout << bi_2.get_num_of_digits() << std::endl;
//    std::cout << big_int().get_num_of_digits() << std::endl;

//    std::cout << (bi_1 < bi_2) << std::endl;
//    std::cout << (bi_1 > bi_2) << std::endl;
//    std::cout << (bi_1 == bi_2) << std::endl;
//    std::cout << (bi_1 != bi_2) << std::endl;
//    std::cout << (bi_1 >= bi_2) << std::endl;
//    std::cout << (bi_1 <= bi_2) << std::endl;
//
//    std::cout << std::endl;
//    std::cout << (bi_3 < bi_2) << std::endl;
//    std::cout << (bi_3 > bi_2) << std::endl;
//    std::cout << (bi_3 == bi_2) << std::endl;
//    std::cout << (bi_3 != bi_2) << std::endl;
//    std::cout << (bi_3 >= bi_2) << std::endl;
//    std::cout << (bi_3 <= bi_2) << std::endl;

    return 0;
}
