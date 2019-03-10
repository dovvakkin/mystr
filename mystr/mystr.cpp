#include "mystr.h"

int mystr::num_count(int a) {
    if (a == 0) {
        return 1;
    }

    int count = 0;
    if (a < 0) {
        ++count;
        a = -a;
    }
    while (a > 0) {
        ++count;
        a = a / 10;
    }
    return count;
}

void mystr::itoa(int a, char *str, int lit_count) {
    if (a == 0) {
        str[0] = '0';
        return;
    }

    int i(lit_count - 1);
    if (a < 0) {
        str[0] = '-';
        a = -a;
    }

    uint8_t num(0);
    while (a > 0) {
        num = a % 10;

        // кодовая таблица, вообще говоря, не гарантирует непрерывность символов 0-9
        switch (num) {
            case 0: {
                str[i] = '0';
                break;
            }
            case 1: {
                str[i] = '1';
                break;
            }
            case 2: {
                str[i] = '2';
                break;
            }
            case 3: {
                str[i] = '3';
                break;
            }
            case 4: {
                str[i] = '4';
                break;
            }
            case 5: {
                str[i] = '5';
                break;
            }
            case 6: {
                str[i] = '6';
                break;
            }
            case 7: {
                str[i] = '7';
                break;
            }
            case 8: {
                str[i] = '8';
                break;
            }
            case 9: {
                str[i] = '9';
                break;
            }

        }
        a = a / 10;
        --i;
    }
}

void mystr::_change_total_size(size_t old_len, size_t new_len) {
    total_size += (-old_len + new_len);
}

mystr::operator int() {
    return atoi(p);
}

mystr &mystr::operator=(const mystr &other) {
    if (this == &other) {
        return *this;
    }

    _change_total_size(len, other.len);

    len = other.len;
    char *q = nullptr;

    if (len > 0) {
        q = new char[len];
        memcpy(q, other.p, len);
    }

    delete[] p;
    p = q;

    return *this;
}

mystr &mystr::operator=(const char *str) {
    size_t new_len = strlen(str);
    _change_total_size(len, new_len);

    len = new_len;
    char *q = nullptr;

    if (len > 0) {
        q = new char[len];
        memcpy(q, str, len);
    }

    delete[] p;
    p = q;

    return *this;
}

mystr mystr::operator+(const mystr &other) {
    size_t old_len = len;
    size_t new_len = len + other.len;

    mystr tmp = mystr();

    auto q = new char[new_len];
    memcpy(q, p, old_len);
    memcpy(q + old_len, other.p, new_len - old_len);
    _change_total_size(0, new_len);

    delete[] tmp.p;
    tmp.p = q;
    tmp.len = new_len;

    return tmp;
}

mystr &mystr::operator+=(const mystr &other) {
    size_t old_len = len;
    size_t new_len = len + other.len;

    auto q = new char[new_len];
    memcpy(q, p, old_len);
    memcpy(q + old_len, other.p, new_len - old_len);
    _change_total_size(old_len, new_len);

    delete[] p;
    p = q;
    len = new_len;

    return (*this);
}

bool mystr::operator==(const mystr &other) const {
    if (len != other.len) {
        return false;
    }

    return (memcmp(p, other.p, len) == 0);
}

bool mystr::operator!=(const mystr &other) const {
    return !(*this == other);
}


char &mystr::operator[](size_t i) {
    if ((i < len) && (i >= 0)) {
        return p[i];
    } else {
        throw std::out_of_range("there is no element with index " + std::to_string(i));
    }
}

std::ostream &operator<<(std::ostream &out, const mystr &obj) {
    for (size_t i = 0; i < obj.len; ++i) {
        out << obj.p[i];
    }
    return out;
}

std::istream& operator>>(std::istream &in, mystr &obj) {
    size_t len = 1;
    size_t cur = 0;
    auto q = new char[len];
    char c('&');
    while  ((c != '\n') && !(in.eof())) {
        c = in.get();

        if (cur >= len) {
            len *= 2;
            auto r = new char[len];
            memcpy(r, q, cur);
            delete[] q;
            q = r;
        }

        q[cur] = c;
        ++cur;
    };

    // final resize
    --cur;
    auto r = new char[cur];
    memcpy(r, q, cur);
    delete[] q;
    q = r;

    obj._change_total_size(obj.len, cur);
    obj.len = cur;
    delete[] obj.p;
    obj.p = q;

    return in;
};


bool operator>(const mystr &s1, const mystr &s2) {
    size_t min_len;
    if (s1.len < s2.len) {
        min_len = s1.len;
    } else {
        min_len = s2.len;
    }

    int check = memcmp(s1.p, s2.p, min_len);
    if (check == 0) {
        if (s1.len == s2.len) {
            return false;
        } else {
            return (s1.len > s2.len);
        }
    } else {
        return (check > 0);
    }
};

bool operator<(const mystr &s1, const mystr &s2) {
    size_t min_len;
    if (s1.len < s2.len) {
        min_len = s1.len;
    } else {
        min_len = s2.len;
    }

    int check = memcmp(s1.p, s2.p, min_len);
    if (check == 0) {
        if (s1.len == s2.len) {
            return false;
        } else {
            return (s1.len < s2.len);
        }
    } else {
        return (check < 0);
    }
};

size_t mystr::objects_count = 0;
size_t mystr::total_size = 0;
