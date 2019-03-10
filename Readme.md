## mystr

Наивная реализация класса-строки. Исходный код располагается в ```/mystr```. Для тестирования используется *Google C++ Testing Framework*. Файлы теста располагаются в ```/test```. 

Процедура запуска тестов:
```
$ mkdir build && cd build
$ cmake .. && make
$ ./RunStringTest
```

В результате будет выведено примерно следующее: 
```
Running main() from /Users/dovvakkin/tmp/mystr/lib/googletest/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from TestSerialization
[ RUN      ] TestSerialization.DateJson
now there are 1 alive mystr objects
now mystr objects occupies 1 bytes of memory

now there is no mystr objects

[       OK ] TestSerialization.DateJson (0 ms)
[----------] 1 test from TestSerialization (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```
Что свидетельствует об успешном прохождении классом ```mystr``` всх представленных тестов.

