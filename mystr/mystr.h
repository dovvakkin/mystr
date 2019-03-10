//
// Created by Евгений Кожевников on 2019-03-09.
//

#ifndef STUPID_PRAK_OF_STUPID_PRAK_MYSTR_H
#define STUPID_PRAK_OF_STUPID_PRAK_MYSTR_H
#include <iostream>

class mystr {
public:
    mystr() : p(nullptr),
              len(0) {
        ++objects_count;
    }

    mystr(const mystr &other) {
        len = other.len;
        ++objects_count;
        total_size += len;

        if (other.p != nullptr) {
            p = new char[len];
            memcpy(p, other.p, len);
        } else {
            p = nullptr;
        }
    }

    explicit mystr(int a) {
        len = num_count(a);
        p = new char[len];
        itoa(a, p, len);

        ++objects_count;
        total_size += len;
    }

    explicit mystr(const char *c) {
        len = strlen(c);
        ++objects_count;
        total_size += len;

        if (len == 0) {
            p = nullptr;
        } else {
            p = new char[len];
            memcpy(p, c, len);
        }
    }

    mystr(char c, int n) {
        if (n <= 0) {
            len = 0;
            p = nullptr;
        } else {
            len = n;
            p = new char[len];
            for (int i = 0; i < n; ++i) {
                p[i] = c;
            }
        }

        ++objects_count;
        total_size += len;
    }

    ~mystr() {
        delete[] p;
        total_size -= len;
        --objects_count;
        if (objects_count > 0) {
            std::cout << "now there are " << objects_count << " alive mystr objects" << std::endl;
            std::cout << "now mystr objects occupies " << total_size << " bytes of memory" << std::endl << std::endl;
        } else {
            std::cout << "now there is no mystr objects" << std::endl << std::endl;
        }

    }

    explicit operator int();

    mystr &operator=(const mystr &other);

    mystr &operator=(const char *str);

    mystr operator+(const mystr &other);

    mystr &operator+=(const mystr &other);

    bool operator==(const mystr &other) const;

    bool operator!=(const mystr &other) const;

    char &operator[](size_t i);

    friend bool operator>(const mystr &s1, const mystr &s2);

    friend bool operator<(const mystr &s1, const mystr &s2);

    friend std::ostream &operator<<(std::ostream &out, const mystr &obj);

    friend std::istream operator>>(std::istream &in, mystr &obj);

private:
    char *p;
    size_t len;

    static size_t objects_count;
    static size_t total_size;

    int num_count(int a);

    void itoa(int a, char *str, int lit_count);

    static void _change_total_size(size_t old_len, size_t new_len);

};

std::ostream &operator<<(std::ostream &out, const mystr &obj);

std::istream operator>>(std::istream &in, mystr &obj);

bool operator>(const mystr &s1, const mystr &s2);

bool operator<(const mystr &s1, const mystr &s2);

#endif //STUPID_PRAK_OF_STUPID_PRAK_MYSTR_H
