#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

/*
 * vector
 * 向量   是一种可以动态管理大小的数组
 * 使用vector需要包含vector库文件
 */
int main() {
    //定义与初始化
    {
        // //声明
        // std::vector<int> v1;
        // std::vector<std::string> v2;
        //
        // //初始化
        // std::vector<int> v3(5,10);
        // std::vector<int> v4(v3);
        // std::vector<int> v5{1,2,3,4,5};
        // std::vector<int> v6(std::move(v5));

    }

    {
        //     //输出
        //     //标准输出流不支持输出vector类型的数据，需要遍历输出
        //     std::vector<int> v1{1,2,3,4,5};
        //     //标准输出流不支持输出vector类型的数据
        //     // std::cout << v1 << std::endl;
        //     //推荐使用auto，降低维护成本
        //     for (auto& num : v1) {
        //         std::cout << num << " ";
        //     }
    }

    //向量的大小和容量
    {
        // std::vector<int> v1{1,2,3,4,5};
        // std::cout << v1.size() << std::endl;//5
        // std::cout << v1.capacity() << std::endl;//5
        // std::cout << std::boolalpha ;
        // std::cout << v1.empty() << std::endl;//false
    }

    //基本操作
    {
        // //增&删
        // std::vector<int> v1{1,2,3,4,5};
        // v1.push_back(10);
        // v1.push_back(20);
        // v1.push_back(30);
        //
        // for (auto num :v1) {
        //     std::cout << num << " ";
        // }
        // std::cout << std::endl;
        //
        // v1.pop_back();//没有参数，只能删除最后一个元素
        // std::cout << "after pop_back():" ;
        //
        // for (auto num :v1) {
        //     std::cout << num << " ";
        // }
        //
        // //插入
        // //v.insert(pos, value);
        //
        // //指定位置删除
        // //v.erase(pos);
        // //v.erase(first, last);区间删除
        //
        // //清空向量
        // //clear()
    }

    //访问
    {
        //下标访问
        //at()
        //.font()
        //.back()
    }

    //遍历
    {
        // //普通for循环
        // //范围for循环
        // //迭代器
        // std::vector<int> v1{1,2,3,4,5};
        // for (size_t i = 0; i < v1.size();++i) {
        //     std::cout << v1[i] << std::endl;
        // }
        //
        // //使用迭代器
        // for(auto it = v1.begin(); it != v1.end(); ++it) {
        //     std::cout << *it << " ";
        // }
    }

    //修改
    {
        // std::vector<int> v1{1,2,3,4,5};
        // //通过下标修改
        // v1[1]  = 10;
        // v1.at(2) = 20;
        //
        // //通过迭代器修改
        // for(auto it = v1.begin(); it != v1.end(); ++it) {
        //     if(*it == 20) {
        //         *it = 25;
        //     }
        // }
        //
        // //assign()
        // //v.assign(count, value);赋值多个相同元素
        // //v.assign(first, last);用另一个区间给他赋值
        // //v.assign({a, b, c});列表初始化赋值
    }

    //高级用法
    {
        //二维嵌套
        //vector<T> v(数量, 初始值);
        //std::vector<int>(4) 表示创建4个空位，默认值为0
        std::vector<std::vector<int>> 矩阵(3,std::vector<int>(4));

        //向量可以和其他复合数据类型结合，进行数据管理

        //使用迭代器操作向量
        //迭代器是一种指针类型，用于遍历与操作容器中的元素
        // for(auto it = vec.begin(); it != vec.end(); ++it) {
        //     *it += 5;
        // }
    }

    //向量与算法
    {
        //排序：sort(),由小到大排序
        std::vector<int> numbers = {50, 20, 40, 10, 30};

        // 排序前
        std::cout << "Before sorting: ";
        for(auto num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 使用sort()排序
        std::sort(numbers.begin(), numbers.end());

        // 排序后
        std::cout << "After sorting: ";
        for(auto num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        //自定义排序规则
        // 使用sort()并传入lambda表达式进行降序排序
        std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
            return a > b;
        });

        // 输出排序后的向量
        std::cout << "After sorting in descending order: ";
        for(auto num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }


    {
        //反转:reverse(v.begin(), v.end());

        //查找:reverse(v.begin(), v.end());


    }


    {
        //内存管理，vector的一个优势就是动态的管理空间
        //reserve()扩容，申请预留空间

        //shrink_to_fit()：表示申请收缩空间，与当前内存空间匹配
    }
    return 0;
}
