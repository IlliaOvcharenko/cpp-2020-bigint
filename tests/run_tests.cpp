#include <iostream>
#include <string>
#include <fstream>
#include "big_int.h"


void run_test_file(string test_filename, string op) {
    std::cout << "start test: " << test_filename << std::endl;
    std::ifstream test_file(test_filename);
    string first_str, second_str, res_str;

    int passed_counter = 0;
    int failed_counter = 0;
    while (!test_file.eof()) {
        test_file >> first_str >> second_str >> res_str;
        if (test_file.fail()) break;

        big_int first(first_str);
        big_int second(second_str);

        big_int res;
        if (op == "+") {
            res = first + second;
        } else if (op == "-") {
            res = first - second;
        } else if (op == "*") {
            res = first * second;
        } else if (op == "/") {
            res = first / second;
        } else if (op == "<") {
            res = first < second;
        } else if (op == ">") {
            res = first > second;
        } else if (op == "==") {
            res = first == second;
        }

        if (res.to_string() != res_str) {
            ++failed_counter;

            std::cout << "test failed: " << (failed_counter + passed_counter) << std::endl;
            std::cout << "test case: " << first << " " << op << " " << second << std::endl;
            std::cout << "calculated: "<< res << " real: " << res_str << std::endl;
        } else {
            ++passed_counter;
        }

    }
    test_file.close();
    std::cout << "passed: " << passed_counter << " failed: " << failed_counter << std::endl;
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {

    run_test_file("tests/add.txt", "+");
    run_test_file("tests/sub.txt", "-");
    run_test_file("tests/mul.txt", "*");
    run_test_file("tests/div.txt", "/");

    run_test_file("tests/less.txt", "<");
    run_test_file("tests/greater.txt", ">");
    run_test_file("tests/equal.txt", "==");

    return 0;
}

