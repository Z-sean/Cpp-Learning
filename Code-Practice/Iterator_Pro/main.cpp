#include <iostream>
#include<string>
#include<sstream>
#include <vector>
/*
 *迭代器 : 提供了统一的数据访问方式
 *  迭代器提供了一种方法，可以不暴露容器的内部实现而实现容器内数据的访问
 *  > 什么是不暴露容器的内部实现?
 *  > 比如通过下标访问:底层是连续的内存存储 / 通过节点访问 / 通过指针访问-->这些都依赖其
 *  > 底层的实现
 *
 *  如何获取迭代器?
 *      有迭代器的成员同时会拥有返回迭代器的成员方法
 *      比如这些类型都拥有begin(),end()成员，其中begin()可以返回第一个元素的迭代器
 *      end()返回的是尾元素的下一个元素的迭代器，也就是意味着是一个不存在的的元素，这个意味着我们已经处理完了容器的全部元素
 *
 *  特殊情况下如果容器为空，则begin和end返回的是同一个迭代器
 *  一般情况下，我们不在意迭代器指向的数据类型是什么，我们使用auto来进行类型推导
 */
int main() {
    system("chcp 65001");
    //迭代器的基本操作
    //迭代器的行为与指针类似，所以可以通过*解引用
    {
        // /*
        //  *it      // 访问当前元素
        //  ++it     // 移动到下一个元素
        //  it != end // 判断是否到边界
        //  it->成员 // 访问对象成员
        //  */
        //
        // std::string s("some string");
        // //确保s非空
        // if(s.begin() != s.end()){
        //     //第一个字母改为大写
        //     auto it = s.begin();
        //     *it = toupper(*it);
        //     std::cout << s << std::endl;
        // }

    }

    {
        // std::string s2 = "another string";
        //
        // for(auto it = s2.begin(); it != s2.end() && !isspace(*it); ++it) {
        //     *it = toupper(*it);
        //     }
        // std::cout << s2 << std::endl;
    }

    //迭代器类型
    //关于迭代器的相关概念：迭代器对象本身，容器下的迭代器类型，某个迭代器对象，核心是能够支持
    //访问容器
    {
        // //我们不关注迭代器的类型
        // // 拥有迭代器的标准库类型使用iterator和const_iterator来表示迭代器的类型
        // const std::string str = "Hello World!";
        // //it是只能指向vector容器类型的常量迭代器对象
        // // std::vector<int>::iterator it; //一般类型的迭代器对象
        // // std::string::const_iterator it ; //指向常量的迭代器对象
    }

    //begin和end返回的类型由容器决定，若容器元素是常量，返回的是常量迭代器对象，反之就是普通的迭代器对象

    //迭代器的解引用操作
    //若迭代器指向的容器存储的是类，那么可以使用*it通过点操作符或者it->来访问迭代器内容
    {
        // std::vector<std::string> vs = {"hello", "world"};
        // for(auto it = vs.begin(); it != vs.end(); ++it){
        //     //(*it)解引用获取string对象，再次调用empty()方法判断为空
        //     if((*it).empty()){
        //         std::cout << "empty string" << std::endl;
        //     }
        // }
    }


    {
        // std::vector<std::string> text = {
        //     "hello",
        //     "",
        //     "world",
        // };
        // for (auto it = text.begin(); it != text.end(); ++it) {
        //     std::cout << *it << " ";
        // }
    }

    //迭代器失效
    //任何一种在循环过程中尝试修改vector容量的行为都会导致迭代器失效
    {
        // //注意下面逻辑错误，在for循环中push元素导致死循环
        // std::vector<int> numbers = {1, 2, 3, 4, 5};
        // for(auto i = 0; i < numbers.size(); ++i) {
        //     numbers.push_back(i);
        // }
        // for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        //     numbers.push_back(*it);
        // }
        //
        // //在vector中删除元素可以使用erase()，他会返回删除元素的下一个迭代器对象
        // numbers.erase(numbers.begin());

    }

    //测试：vector容器存储了一系列数字，在循环中遍历每一个元素，并且删除其中的奇数，要求循环结束，vector元素为偶数，要求时间复杂度o(n)
    {
        // std::vector<int> numbers = {1, 2, 3, 4, 5};
        // //循环遍历,并删除其中奇数
        // for(auto it = numbers.begin(); it != numbers.end(); ) {
        //     // 删除奇数
        //     if(*it % 2 != 0){
        //         it = numbers.erase(it);
        //         continue;
        //     }
        //     ++it;
        // }
        //
        // for(auto num : numbers) {
        //     std::cout << num << " ";
        // }
        //
        // std::cout << std::endl;
    }

    //迭代器运算
    //string和vector为迭代器适配了多种运算，包括+=、+、-、<、>
    //这些运算符改变的是迭代器的指向内容

    //编写一个程序，读取一组整数到一个 std::vector 中，
    //并打印每对相邻元素的和。例如，给定输入 1 2 3 4，输出应为 3 5 7。
    {
        std::vector<int> numbers = {};
        int num{};

        std::cout << "请输入数字：" ;
        while (std::cin >> num && num != -1) {
            numbers.push_back(num);
        }
        std::cout << "相邻元素的和: ";
        for (auto it = numbers.begin(); it+1 != numbers.end(); ++it) {
            std::cout << (*it + *(it+1)) << " ";
        }

    }

    return 0;
}
