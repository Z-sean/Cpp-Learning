#include <iostream>
//Vector示例代码
#include<vector>
using namespace std;
int main(void) {
    // std::cout << "Hello, World!" << std::endl;
    vector<int> vec1;//默认声明
    vector<int> vec2(5,1);//指定大小&默认值
    vector<int> vec3 = {1,2,3};//初始化
    vector<int> vec5(vec3);//拷贝构造
    vector<int> vec6(move(vec5));//移动构造

    cout << "vsc2:";
    for (int temp:vec2) {
        cout << temp << " ";
    }
    cout << endl;

    cout << "vec2's size=" << vec2.size() << endl;
    cout << "vec2's capacity=" << vec2.capacity() << endl;
    cout << "vec2 is empty? " << vec2.empty() << endl;
    return 0;
}
