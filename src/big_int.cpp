#include "big_int.h"

big_int::big_int() {
    sign_m = true;
    nums_m.push_back(0);
}

big_int::big_int(string str) {
    sign_m = true;
    if (str[0] == '-') {
        sign_m = false;
        str.erase(str.begin());
    } else if (str[0] == '+') {
        str.erase(str.begin());
    }

    std::reverse(str.begin(), str.end());

    for (int i = 0; i < str.length(); i += exp_m) {
        string sub_str = str.substr(i, exp_m);
        std::reverse(sub_str.begin(), sub_str.end());
        nums_m.push_back(std::stoi(sub_str));
    }
}

void big_int::remove_leading_zero() {
    while ((nums_m.size() > 1) && nums_m.back() == 0) {
        nums_m.pop_back();
    }
}

size_t big_int::get_num_of_digits() const {
    size_t num_full_blocks = nums_m.size() - 1;
    int last_value = nums_m.back();
    return (num_full_blocks * exp_m) + std::to_string(last_value).length();
}


bool big_int::operator >(const big_int& second) const {
    if (is_zero() && second.is_zero()) {
        return false;
    } else if (sign_m && !second.sign_m) {
        return true;
    } else if (!sign_m && second.sign_m) {
        return false;
    }

    size_t first_len = get_num_of_digits();
    size_t second_len = second.get_num_of_digits();

    bool result;
    if (first_len > second_len) {
        result = sign_m;
    } else if (first_len < second_len) {
        result = !sign_m;
    } else {
        result = false;
        for (int i = nums_m.size() - 1; i >= 0; --i) {
            int first_num = sign_m ? nums_m[i] : -nums_m[i];
            int second_num = sign_m ? second.nums_m[i] : - second.nums_m[i];

            if (first_num > second_num) {
                result = true;
                break;
            } else if (first_num < second_num) {
                break;
            }
        }
    }
    return result;
}

bool big_int::operator <(const big_int& second) const {
    if (is_zero() && second.is_zero()) {
        return false;
    } else if (sign_m && !second.sign_m) {
        return false;
    } else if (!sign_m && second.sign_m) {
        return true;
    }

    size_t first_len = get_num_of_digits();
    size_t second_len = second.get_num_of_digits();

    bool result;
    if (first_len < second_len) {
        result = sign_m;
    } else if (first_len > second_len) {
        result = !sign_m;
    } else {
        result = false;
        for (int i = nums_m.size() - 1; i >= 0; --i) {
            int first_num = sign_m ? nums_m[i] : -nums_m[i];
            int second_num = sign_m ? second.nums_m[i] : - second.nums_m[i];
            if (first_num < second_num) {
                result = true;
                break;
            } else if (first_num > second_num) {
                break;
            }
        }
    }
    return result;
}

bool big_int::operator ==(const big_int& second) const {
    return !(*this < second) && !(*this > second);
}

bool big_int::operator !=(const big_int& second) const {
    return !(*this == second);
}

bool big_int::operator >=(const big_int& second) const {
    return (*this > second) || (*this == second);
}

bool big_int::operator <=(const big_int& second) const {
    return (*this < second) || (*this == second);
}


big_int big_int::operator +(const big_int& second) const {
    big_int first = *this;

    if (first.sign_m && !second.sign_m) {
        return first - second.abs();
    } else if (!first.sign_m && second.sign_m) {
        return second - first.abs();
    } else if (!first.sign_m && !second.sign_m) {
        big_int res = first.abs() + second.abs();
        res.sign_m = !res.sign_m;
        return res;
    }

    if (second > first) {
        return second + first;
    }

    big_int out;
    out.nums_m.pop_back();

    int carry_over = 0;

    for (int i = 0; i < first.nums_m.size(); ++i) {
        int first_num = first.nums_m[i];
        int second_num = (second.nums_m.size() <= i)? 0 : second.nums_m[i];

        int value = first_num + second_num + carry_over;
        carry_over = 0;

        if (value >= base_m) {
            carry_over = 1;
            value -= base_m;
        }
        out.nums_m.push_back(value);
    }

    if (carry_over != 0) {
        out.nums_m.push_back(carry_over);
    }

    return out;
}

big_int big_int::operator -(const big_int& second) const {
    big_int first = *this;

    if (first.sign_m && !second.sign_m) {
        return first + second.abs();
    } else if (!first.sign_m && second.sign_m) {

        big_int res = first.abs() + second.abs();
        res.sign_m = !res.sign_m;
        return res;
    } else if (!first.sign_m && !second.sign_m) {
        return  second.abs() - first.abs();
    }

    if (second > first) {
        big_int res = second - first;
        res.sign_m = !res.sign_m;
        return res;
    }

    big_int out;
    out.nums_m.pop_back();

    int carry_over = 0;

    for (int i = 0; i < first.nums_m.size(); ++i) {
        int first_num = first.nums_m[i];
        int second_num = (second.nums_m.size() <= i)? 0 : second.nums_m[i];

        int value = first_num - second_num - carry_over;

        if (value < 0) {
            carry_over = 1;
            value += base_m;
        } else {
            carry_over = 0;
        }

        out.nums_m.push_back(value);
    }

    out.remove_leading_zero();
    return out;
}

big_int big_int::operator *(const big_int& second) const {
    big_int first = *this;

    if (first.sign_m && !second.sign_m) {
        big_int res = first * second.abs();
        res.sign_m = !res.sign_m;
        return res;
    } else if (!first.sign_m && second.sign_m) {
        big_int res = first.abs() * second;
        res.sign_m = !res.sign_m;
        return res;
    } else if (!first.sign_m && !second.sign_m) {
        return first.abs() * second.abs();
    }

    if (second > first) {
        second * first;
    }

    big_int out;
    out.nums_m.resize(first.nums_m.size() + second.nums_m.size(), 0);


    for (int j = 0; j < second.nums_m.size(); ++j) {
        int carry_over = 0;

        for (int i = 0; i < first.nums_m.size(); ++i) {
            int value = out.nums_m[j+i] + (first.nums_m[i] *  second.nums_m[j]) + carry_over;

            if (value >= base_m) {
                carry_over = value / base_m;
                value = value % base_m;
            } else {
                carry_over = 0;
            }

            out.nums_m[j+i] = value;
        }

        out.nums_m[j + first.nums_m.size()] += carry_over;
    }

    out.remove_leading_zero();
    return out;
}

big_int big_int::operator /(const big_int& second) const {
    if (sign_m && !second.sign_m) {
        big_int res = *this / second.abs();
        res.sign_m = !res.sign_m;
        return res;
    } else if (!sign_m && second.sign_m) {
        big_int res = abs() / second;
        res.sign_m = !res.sign_m;
        return res;
    } else if (!sign_m && !second.sign_m) {
        return abs() / second.abs();
    }


    big_int q(0);
    size_t second_len = second.get_num_of_digits();

    big_int dividend(*this);
    while (second <= dividend) {
        size_t dividend_len = dividend.get_num_of_digits();
        int len_diff = (int) dividend_len - (int) second_len;

        string step_q_str;
        if (len_diff > 0) {
            step_q_str = string(len_diff, '0');
            step_q_str[0] = '1';
        } else {
            step_q_str = "1";
        }
        big_int step_q(step_q_str);


        dividend = dividend - (second * step_q);
        q = q + step_q;
    }
    return q;
}


big_int big_int::operator +=(const big_int& second) {
    return *this = *this + second;
}

big_int big_int::operator -=(const big_int& second) {
    return *this = *this - second;
}

big_int big_int::operator *=(const big_int& second) {
    return *this = *this * second;
}

big_int big_int::operator /=(const big_int& second) {
    return *this = *this / second;
}


big_int& big_int::operator ++() {
    *this += big_int(1);
    return *this;
}

big_int big_int::operator ++(int) {
    big_int tmp(*this);
    ++(*this);
    return tmp;
}

big_int& big_int::operator --() {
    *this -= big_int(1);
    return *this;
}

big_int big_int::operator --(int) {
    big_int tmp(*this);
    --(*this);
    return tmp;
}


big_int big_int::abs() const  {
    big_int out(*this);
    out.sign_m = true;
    return out;
}

bool big_int::is_zero() const {
    if ((nums_m.size() == 1) && (nums_m[0] == 0)) {
        return true;
    }
    return false;
}

string big_int::to_string() const {
    string out_str;

    for (int i = (int)(nums_m.size() - 1); i >= 0; --i) {
        string sub_str = std::to_string(nums_m[i]);
        if (i != (int)(nums_m.size() - 1)) {
            string leading_zero = string(exp_m - sub_str.length(), '0');
            out_str += leading_zero + sub_str;
        } else {
            out_str += sub_str;
        }

    }

    if (!sign_m && (*this != 0)) {
        out_str = '-' + out_str;
    }
    return out_str;
}

void big_int::debug_print() const {
    for (auto n: nums_m) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}


std::ostream& operator <<(std::ostream& out, const big_int& bi) {
    out << bi.to_string();
    return out;
}
