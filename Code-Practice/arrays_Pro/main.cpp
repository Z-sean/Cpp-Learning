#include <iostream>
/*
 * 多维数组
 * cpp没有多维数组的明确定义
 *
 */
int main() {
    //多维数组在定义后就不支持大规模的赋值了，只能单个单独赋值
    {
        // //该数组描述为包含3个数组，每个数组都包含4个整数
        // int arr[3][4]{};
        //
        // //包含3个数组，每个都包含5个数组，每个都包含10个整数
        // int arr2[3][5][10]{};

        int arr[3][4]{}; // 数组已经出生了，此时里面全是0

        // 声明之后，只能单独针对某个格子进行精准修改
        arr[0][0] = 1;  // 修改第0行第0列
        arr[1][2] = 7;  // 修改第1行第2列

        std::cout << "arr[0][0]: " << arr[0][0] << std::endl;
        std::cout << "arr[1][2]: " << arr[1][2] << std::endl;


    }

    //我们通过下标访问多维数组的元素

    //使用for以及嵌套for循环遍历多维数组
    {
        constexpr size_t rowCnt = 3, colCnt=4;
        //12 个未初始化的元素
        int ia[rowCnt][colCnt];
        //对于每一行
        for(size_t i = 0; i != rowCnt; ++i){
            //对于行内的每一列
            for( size_t j = 0; j != colCnt; ++j){
                ia[i][j] = i*colCnt + j;
            }
        }
    }
    //在c++11后，通过范围for循环可以更加快速的遍历
    {
        constexpr size_t rowCnt = 3, colCnt=4;
        //12 个未初始化的元素
        int ia[rowCnt][colCnt];
        size_t cnt = 0;
        for(auto &row: ia){
            for(auto & col : row){
                col = cnt;
                ++cnt;
            }
        }
    }

    //数组不能进行复制与整体赋值
    //在 C++ 中，范围循环默认会尝试复制（Copy）集合中的元素
    //使用范围循环遍历多维数组时，若在外层循环上使用auto，必须是auto&，否则数组会被退化为int*，
    //只是一个指针，但不知道数组长度是多少，这会导致内层循环出错
    return 0;
}
