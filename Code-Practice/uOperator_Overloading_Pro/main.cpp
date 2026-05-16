#include <iostream>
/*
 * 运算符重载
 * 对运算符拓展为一个函数，在函数内自定义自己的计算逻辑
 * 目的是为了简化计算逻辑
 *
 * 重载后的运算符只对自定义的类或者结构体起效，对于内置类型的对象不会生效
 */
int main() {
    //基础写法模板
    /*
     * operator运算符(参与运算的另一个数据对象) {
     *      自定义的运算逻辑
     * }
     * 只要不改原对象，那就在参数以及函数右侧加上const
    * operator运算符(const &参与运算的另一个数据对象) const {
     *      自定义的运算逻辑
     * }
     * 参数列表的常引用保护参数不被修改，而函数右侧的const保护函数调用者不被改变
     * 函数右侧的const表示这是一个常成员函数，意思是不希望函数修改
     */

    {
        class Point {
        public:
            int x, y;
            Point(int x = 0, int y = 0) : x(x), y(y) {}

            // 标准写法：常成员函数 + 常引用形参（防止拷贝，且支持连续相加）
            Point operator+(const Point& other) const {
                // 内部通过 this 指针访问左操作数，通过 other 访问右操作数
                return Point(this->x + other.x, this->y + other.y);
            }

            bool operator==(const Point& other) {
                return x == other.x && y == other.y;
            }
        };
    }
    return 0;
}
