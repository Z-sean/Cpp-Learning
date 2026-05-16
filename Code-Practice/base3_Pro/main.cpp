#include <iostream>
//头文件和源文件
int main() {
    /*
     * 头文件主要进行声明
     *  类的声明
     *  函数声明
     *  外部变量声明
     *  内联函数/模板/宏定义
     *
     *  为了防止头文件被重复包含，一般意识预处理指令来防止该现象发生
     *
     *  编译器会首先处理源文件，通过include找到对应的头文件，进行匹配
     *
     *  头文件应该只负责声明，源文件负责实现
     *
     *  #pragme once 和 #ifndef...都是预编译指令，前者不是标准支持的，在历史版本上可能不被支持，后者较为繁琐，但支持性好
     *
     *  CMake是一个自动化构建系统，通过CMakelists文件描述构建过程
    *  cmake_minimum_required(VERSION 4.2) cmake系统要求
    *  project(base3_Pro)  项目名称
    *
    *  set(CMAKE_CXX_STANDARD 17)
    *
    *  add_executable(base3_Pro main.cpp)  添加源文件

     */
    return 0;
}
