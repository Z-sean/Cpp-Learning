#include <iostream>
#include <string>
#include<sstream>
#include<regex>
/*
 * 字符串是一连串字符组合的序列，
 *
 * 字符串有两种风格:
 *  c语言风格:以\0结尾的字符数组
 *  C++的std::std类
 *
 *  使用字符串需要包含string文件
 *
 */
int main() {
    system("chcp 65001");
    using namespace std;

    char ch[] = "Hello,world!";
    string str = "Hello,World!";

    //string对象的初始化
     {
         // string str1;
         // string str2 = "yolo!";
         // string str3("yolo!");
         // string str4{"yolo!"};//列表初始化
         // string str5(5,'a');
         // string str6(str4);
         // string str7(str4,0,2);
         //
         // cout << "str1 =  " << str1 << endl;
         // cout << "str2 =  " << str2 << endl;
         // cout << "str3 =  " << str3 << endl;
         // cout << "str4 =  " << str4 << endl;
         // cout << "str5 =  " << str5 << endl;
         // cout << "str6 =  " << str6 << endl;
         // cout << "str7 =  " << str7 << endl;
     }

    //字符串的输入和输出
    {
        // string str1 = "Hello,     world";
        // cout << str1 <<endl;
        //
        // string input;
        // cout << "请输入：" ;
        // cin >> input;
        // cout << "你输入的是：" << input << endl;
        //
        // // //使用getline读取带空格的输入
        // // string inp;
        // // cout << "请输入：";
        // // getline(cin,inp);
        // // cout << "你的输入是:" << inp << endl;

    }

    /*字符串操作:
     * 1. 拼接
     * 2. 比较
     * 3. 查找
     * 4. 替换
     * 5. 剪切
     */
    {
        // string str1 = "Hello,World!";
        // string str2 = "zhaochen";
        //
        // //拼接
        // // cout << str1+str2 << endl;
        // // str1+=str2;//Hello,World!zhaochen
        // // cout << str1+str2 << endl;//Hello,World!zhaochenzhaochen
        // // cout << str1.append(str2) << endl;//Hello,World!zhaochenzhaochen
        //
        // //比较，字符串是字符拼接的序列，比较比的是字符在字典中的序列值
        // //'z' > 'H'所以一定是str1<str2
        // // if (str1 == str2) cout << "相等";
        // // if (str1 > str2) cout << "str1大";
        // // if (str1 < str2) cout << "str2大";//str2大
        //
        // //查找
        // //size_t pos = str.find("目标字符串");
        // string word;
        // cout << "请输入查找的字符 " ;
        // cin >> word;
        // size_t pos = str1.find(word);
        // if (pos != std::string::npos) {
        //     std::cout << "找到 '" << word << "' 在位置: " << pos << std::endl;
        // } else {
        //     std::cout << "'" << word << "' 未找到。" << std::endl;
        // }
        //
        // //替换
        // //str.replace(起始位置, 替换长度, "新内容");
        // str1.replace(pos, str2.length(), str2);
        // cout << str1 << endl;
        //
        // //截取
        // //string result = str.substr(起始位置, 截取长度);
        // //如果省略第二个参数，substr() 会返回从起始位置到字符串末尾的所有字符。
    }

    //成员函数使用
    /*
     * 长度/容量
     * 字符操作，cctype库中，用于判断字符的情况
     */
    {
        // string str = "Hello,World!";
        // cout << str.size() << endl;//12
        // cout << str.length() << endl;//12
        // cout << str.capacity() << endl;//15,表示它当前能够持有的最大字符数，而不需要重新分配内存
        //
        // //islower(),isupper(),tolower(),toupper()
        //
        // //访问
        // cout << str[15] << endl;//同样的越觉，直接停止，没有报错
        // cout << str.at(5)<< endl;//std::out_of_range报错
        //
        // //大小写转换，std本身包含tolower和toupper()
        // //清理clear
        // //判空empty()
        // //删除部分erase(起始位置，终止位置)
        // //指定位置插入insert(位置,插入内容)
        // //find_first_of(), find_last_of()：查找字符集合中的任何一个字符
    }

    //高级用法
    {
        // //字符流
        // /*
        //  * 我们可以定义一个字符串进行输出，cin需要接受外设的输入
        //  * 字符流可以自定义字符内容进行输入，代替了外设输入的过程
        //  */
        // stringstream ss;
        // string str  = "Hello, World!";
        // ss << str;
        // string str2{};
        // ss >> str2;
        // cout << str2 << endl;
    }

    //类型转化:前提是可以转
    {
        // int num = 100;
        // double pi = 3.14159;
        //
        // string str1 = to_string(num);
        // string str2 = to_string(pi);
        //
        // // cout << "str1: " << str1 << ", str2: " << str2 << endl;
        //
        // //string转其他类型:
        // //直接赋值强制转换
        // //stoi()/stod()(c++11相关)
    }

    //正则表达式匹配
    {
        // //c++提供regex类
        //
        //
        // std::string text = "The quick brown fox jumps over the lazy dog.";
        // std::regex pattern(R"(\b\w{5}\b)"); // 匹配所有5个字母的单词
        //
        // std::sregex_iterator it(text.begin(), text.end(), pattern);
        // std::sregex_iterator end;
        //
        // std::cout << "5个字母的单词有:" << std::endl;
        // while (it != end) {
        //     std::cout << (*it).str() << std::endl;
        //     ++it;
        // }
    }

    //与C风格字符串互相转换
    //c_str()
    {
        // // const char* cstr = "Hello, C-strings!";
        // // std::string str(cstr);//直接使用string类进行转换
        // // std::cout << str << std::endl; // 输出: Hello, C-strings!
        //
        //
        // //c_str()获取一个c风格的指针，指针指向的内存由string管理，需要保证在string有效期间使用
        // std::string str = "Hello, std::string!";
        // const char* cstr = str.c_str();
        // std::cout << cstr << std::endl; // 输出: Hello, std::string!
    }

    {
        std::string str = "helo   yolo";
        std::cout << str << std::endl;
    }

    return 0;
}
