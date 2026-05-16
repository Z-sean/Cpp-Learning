#include <iostream>
#include<string>
#include<sstream>
#include<map>
#include<algorithm>
/*● 统计单词数量
● 统计每个单词出现的次数
● 查找指定单词的出现次数
● 输出最长的单词
*/

/*
 * ostringstream 字符流输出对象，cout是把字符输出在屏幕上，ostringstream是把字符存储在
 * 这个对象离 str()用于获取存储的字符串
 *
 */
int main() {
    std::string text;
    std::cout << "请输入一段文本: \n" ;

    //读取文本
    std::ostringstream oss;
    std::string line;
    while (std::getline(std::cin,line)) {
        oss << line << " ";
    }
    text = oss.str();
    return 0;
}
