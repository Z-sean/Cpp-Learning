#include <iostream>

void sizeofnum(){
    std::cout << "Size of char: " << sizeof(char) << " bytes\n";
    std::cout << "Size of int: " << sizeof(int) << " bytes\n";
    std::cout << "Size of float: " << sizeof(float) << " bytes\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes\n";
    std::cout << "Size of long long: " << sizeof(long long) << " bytes\n";
}
int main() {
    /*
     * 变量和输出
     *  变量是存储数据的内存实体
     *  通过数据类型，我们知道数据种类以及在内存中的所占空间大小
     *
     *  数据类型：
     *      内置类型:整型/浮点型/布尔型/字符型
     *      复合类型:结构体/枚举/联合体/类
     *
     *  计算机内部使用二进制表示，1字节 = 8bit（位）
     *  计算机存储数据时会开辟一段内存地址，这个内存本身也有地址
     *
     *  变量名规则
     *      以数字&字母&_组合
     *      数字不能开头
     *      关键字以及保留字不能作为变量名
     *      变量名大小写敏感
     *
     *  输出
     *      c++通过标准输出流来输出内容到屏幕，std::cout是标准库的一个对象，为了使用该对象
     *      你必须包含头文件<iostream>
     *      <<是插入运算符，用于将右侧的数据插入左侧
     *      std::endl是操纵符，用于输出后插入换行符并刷新缓存区，使内容立即显式在屏幕上
     *      为了输出布尔值 true 和 false 而不是整数 1 和 0，我们使用了 std::boolalpha 操纵符
     *      c++还支持多种格式化输出
     */
    // 定义初始化一个变量pai_val数值为 3.14， 初始化一个int类型的变量int_val变量值为5，
    // 分别输出这两个变量的值。

    using namespace std;
    int int_val = 5;
    double pai_val = 3.14;

    cout << int_val << endl;
    cout << pai_val << endl;

    // 初始化一个bool变量数值为-100，输出bool变量的值，看看是true还是false。
    bool bool_val = -100;
    cout << boolalpha;
    cout << bool_val << endl;


    //=================================================================





    return 0;
}
