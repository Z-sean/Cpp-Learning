#include <iostream>
#include<cstring>
/*
 * 数组
 * 数组也是存储一组相同类型数据的容器，需要通过位置来访问容器内元素
 * 与vector相比，不能动态改变容器的大小，缺少灵活性
 * 在不确定元素数量时，请使用vector
 *
 *
 */
int main() {
    system("chcp 65001");
    //数组的定义
    //数组的容量是固定的，所以要求在定义时就确定其维度
    //数组的维度必须是常量表达式

    //定义在自定义类或者对象的内置类型变量，默认不会被初始化
    {
        // int a = 10;//不是常量表达式
        // constexpr int b = 20;//是常量表达式
        //
        // int arr1[10];
        // int* arr2[b];
        //
        // int arr3[a];//部分编译器可以通过，但不代表这种写法是正确的

    }
    //初始化
    //使用列表初始化可以不确定维度
    //确定维度后不可以初始化超出维度
    {
            // const unsigned sz = 3;
            // // 含有3个元素的数组，元素值分别是0，1，2
            // int ial[sz] = {0,1,2};
            // // 维度是3的数组
            // int a2[] = {0,1,2};
            // //等价于a3[] = {0,1,2,0,0}
            // int a3[5] = {0,1,2};
            // //等价于a4[] = {"hi","bye",""}
            // std::string a4[3] = {"hi","bye"};
        //错误，初始值过多
        //int a5[2] = {0,1,2};
    }

    //拷贝与赋值
    //数组不允许拷贝赋值另一个数组
    //部分编译器可以，这是编译器的优化，不是c++语言的支持
    {
        // //含有三个整数的数组
        // int a[] = {0,1,2};
        // // 错误，不允许使用一个数组初始化另一个数组
        // // int a2[] = a;
    }

    //复杂类型的数组声明
    //数组本身是一个对象，所以有数组的指针和数组的引用
    //没有引用的数组
    {
        // //ptrs是含有10个整数指针的数组
        // int *ptrs[10];
        // //错误, 不存在引用的数组
        // //int& refs[10] = /*?*/;
        // //Parray指向一个含有10个整数的数组
        // int arr[10] ={0,1,2,3,4,5,6,7,8,9};
        // int (*Parray)[10] = &arr;
        // //arrRef 引用一个含有10个整数的数组
        // int (&arrRef)[10] = arr;
    }

    //数组的访问
    //与string vector类似，通过for循环访问输出
    //在使用数组下标的时候，通常将其定义为size_t类型。
    //size_t是一种机器相关的无符号类型，它被设计得足够大以便能表示内存中任意对象的大小。
    //数组的大小可以通过sizeof获取
    //数组没有越界检查，使用时要小心
    {
        // int arr[10] ={0,1,2,3,4,5,6,7,8,9};
        // for(size_t i = 0; i < sizeof(arr)/sizeof(int); ++i){
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
    }

    //数组与指针
    //数组的元素也是对象，所以可以使用下标获取数组元素后通过取地址符获取数组元素的指针
    //数组名在编译期间会被转换为指向数组首元素的指针
    //一些情况下，对数组的操作就是对指针的操作，所以使用auto推断类型得到的就是一个指针类型
    //但在使用delctype时不会发生auto的类型推断转换
    {

    }

    //数组的指针相当于迭代器
    //能够实现迭代器的全部功能
    {
        // int arr[] = {1,2,3,4,5};
        // int *p = arr;
        // std::cout << *(++p) << " ";
    }


    //使用数组实现迭代器功能
    //前提是获取指向最后一个元素下一个对象的指针
    //在c++11中，提供了获取首元素与尾元素标志位的方法；std::begin(),std::end()
    {
        // int arr[10] = {0,1,2,3,4,5,6,7,8,9};
        // // e指向arr[10],也就是最后一个元素的下一个位置
        // int *e = arr+10;
        //
        // for(int* b = arr; b != e; ++b){
        //     std::cout << *b << " ";
        // }
        //
        // std::cout << std::endl;
        //
        // int ia[] = {0,1,2,3,4,5,6,7,8,9};
        // int * beg = std::begin(ia);
        // int * end = std::end(ia);
        // for(auto it = beg; it != end; ++it){
        //     std::cout << *it << " ";
        // }
    }

    //指针运算
    //指向数组元素的指针可以进行算术运算，与迭代器相同，表示指向位置的移动

    //c风格字符串
    //是继承自C语言的一种写法，该写法中，字符串存储在字符数组中并以空字符结尾，一般利用指针
    //来操作字符
    //当使用双引号""表示字符串时，编译器一般会自动在字符串字面量后面加上一个空字符，不需要手动添加
    //在使用strlen计算c风格字符串的长度时，必须保证在末尾有空字符，否则会导致越界风险
    //c风格字符串不能使用比较运算符进行比较，需要使用strcmp，使用比较运算符比较的是指针不是指针
    //指向的元素
    {
        // char* arr = "hello\0";
        // char* arr2 = "world\0";
        // //strlen-长度
        // //strcmp-长度比较，相等返回0，前者大返回正值，后者大返回负值
        // //strcat-拼接
        // //strcpy-拷贝
        // // std::cout << strlen(arr) << std::endl;
        // // std::cout << strcmp(arr, arr2) << std::endl;
        // std::cout << strcat(arr, arr2) << std::endl;
        // std::cout << arr << std::endl;
    }
    //为了c风格代码与cpp风格代码的混合使用，c++提出了c_str()函数，该函数返回一个指针，
    //该指针指向一个以空字符结尾的字符数组，但这个指针的生命周期由字符串管理
    {
        // char ch[] = {'h','e','l'};
        // const char *ch1 =c_str(ch);
    }
    {
        // int time[5]{};
        //
        // std::cout << "请输入5天内的学习时长:(输入-1结束)" ;
        //
        // for (int i = 0; i < 5; i++) {
        //     int input = 0;
        //     std::cin >> input;
        //     if (input == -1) {
        //         break;
        //     }else {
        //         time[i] = input;
        //     }
        //
        // }
        // auto beg = std::begin(time);
        // auto end = std::end(time);
        // int total = 0;
        // for (auto it = beg; it != end; ++it) {
        //
        //     total += *it;
        // }
        // std::cout << "学习时长为：" << total << std::endl;

    }


    {
        int pages[7]{};
        std::cout << "请输出你的学习数据：(输入-1结束)";
        for (int i = 0; i < 7; i++) {
            int input = 0;
            std::cin >> input;
            if (input == -1) {
                break;
            }else if (std::size(pages) > 7) {
                break;
            }else {
                pages[i] = input;
            }
        }

        auto beg = std::begin(pages);
        auto end = std::end(pages);
        int max = pages[0];
        for (auto it = beg; it != end; ++it) {

            if (*it > max) {
                max = *it;
            }
        }
        std::cout << "本周日最高阅读记录为：" << max << std::endl;
    }
    return 0;
}
