#include <iostream>
/*
 * 命名空间是为了防止多文件的同名成员变量或方法冲突
 * 每个using只能声明一个成员变量
 * 头文件中不应该包含using
 * 在使用时通过::,系统会在左侧的命名空间寻找右侧的成员
 *
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
