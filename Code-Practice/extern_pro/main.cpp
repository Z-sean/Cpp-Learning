#include <iostream>
/*
 * extern主要用于声明一个变量或函数是在另一个文件或同一个文件的其他位置定义的。
 * 这主要用于处理全局变量或函数声明，确保在多个源文件中能够正确地链接到这些全局变量或函数的定义。
 *
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
