#ifndef BIGINT_BIG_INT_H
#define BIGINT_BIG_INT_H

#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cmath>
#include <algorithm>

using std::string;

class big_int {
private:
    int exp_m = 4;
    int base_m = std::pow(10, exp_m);
    bool sign_m;
    std::vector<int> nums_m;

    void remove_leading_zero();
    size_t get_num_of_digits() const;

public:
    big_int();
    big_int(string str);
    big_int(long long int v) : big_int(std::to_string(v)) {}


    bool operator >(const big_int& second) const;
    bool operator <(const big_int& second) const;
    bool operator ==(const big_int& second) const;
    bool operator !=(const big_int& second) const;
    bool operator >=(const big_int& second) const;
    bool operator <=(const big_int& second) const;

    big_int operator +(const big_int& second) const;
    big_int operator -(const big_int& second) const;
    big_int operator *(const big_int& second) const;
    big_int operator /(const big_int& second) const;

    big_int operator +=(const big_int& second);
    big_int operator -=(const big_int& second);
    big_int operator *=(const big_int& second);
    big_int operator /=(const big_int& second);

    big_int& operator ++();
    big_int operator ++(int);
    big_int& operator --();
    big_int operator --(int);

    big_int abs() const;
    bool is_zero() const;
    string to_string() const;
    void debug_print() const;
};

std::ostream& operator <<(std::ostream& out, const big_int& bi);
#endif //BIGINT_BIG_INT_H
