#include <iostream>
/*类型别名和类型推导
 * using
 * typedef
 *
 */
int main() {
    //wages 是double的同义词
    typedef double wages;
    //base是double的同义词,p是double*的同义词
    typedef wages base, *p;

    //64位整型
    using int64_t = long long;

    /*
     * 指针/常量和类型别名
     * pstring是一个指向char的指针
     *  cstr是一个指向常量的char类型指针
     *  ps是一个指向常量的指针，指向的类型是一个char指针
     */
    typedef char * pstring;
    const pstring cstr = 0;
    const pstring *ps;

    /*auto类型推导规则
     *单独使用时就是拷贝类型，忽略引用和顶层const
     * 和const/&/*使用时，是借用类型
     */

    /*decltype
     * 如果是一个光秃秃的变量名，那么推导类型就是该变量声明时的具体类型
     * 如果不是一个光秃秃的表达式
     *      左值-->推断为T&
     *      右值-->推断为T
     *  decltype（（variable））（注意是双层括号）的结果永远是引用，
     *  而decltype（variable）结果只有当variable本身就是一个引用时才是引用
     *
     */
    return 0;
}
