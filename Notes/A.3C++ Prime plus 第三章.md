# 第三章 数据处理

## 简单变量

```cpp
int num ;
num = 10;
```

- 在内存中开辟一块空间，将值复制在该空间中

### 变量名

- 字母数字和`_`的组合
- 数字不能开头
- 区分大小写
- 不能使用关键字命名
- 对长度没有限制

---

### 整型

- 任何计算机都只能表达**整型的一个子集**
- C++中用于表示整型的类型有:
  - char
  - short
  - int
  - long
  - long long(C++ 11)

- 每种类型都有`有符号`和`无符号`两种类型

- `short`至少16位；
- `int`至少与`short`一样长；
- `long`至少32位， 且至少与`int`一样长；
- `long long`至少64位， 且至少与`long`一样长。

> 以上是由于不同编译器的标准不同所导致的，`char`类型一般就是1字节

---

#### `sizeof`和`limits`头文件

- `sizeof`是一个运算符，不是函数，后面可以跟变量名，数据类型名
  - **在跟数据类型名时，要包裹括号**

```cpp
include<iostream>
#include<climits>
int main(void)
{
        using namespace std;
        int n_int = INT_MAX;
        long n_long = LONG_MAX;
        short n_short = SHRT_MAX;
        long long n_llong = LLONG_MAX;
        cout << "the MAX INT is " << sizeof(n_int) << "bytes" <<endl;
        cout << "the MAX short is " << sizeof(n_short) << "bytes" <<endl;
        cout << "the MAX long is " << sizeof(n_long) << "bytes" <<endl;
        cout << "the MAX long long is " << sizeof(n_llong) << "bytes" <<endl;
        return 0;
}


/*
the MAX INT is 4bytes
the MAX short is 2bytes
the MAX long is 8bytes
the MAX long long is 8bytes

*/
```

- 为什么`long`和`long long`都是8字节，有什么区别
  - 这表示物理上都分配了8字节的空间，但C++规定不同环境下，`long`至少保证32位的承载能力，`long long`至少保证64位的承载能力

### 初始化

```cpp
int n = 10;//字面量初始化
int n = b;//变量初始化
int n(10);
int n{};//默认赋值0，加不加=都一样
int n{10};
```

---

## 无符号整型

![](D:\Work\Computer-Learning\Cpp-Learning\Screenshots\c++-primeplus学习截图\溢出行为.png)

```cpp
#include<iostream>
#include<climits>
int main(void)
{
        using namespace std;
        short sam = SHRT_MAX;
        unsigned short sum = USHRT_MAX;
        cout << "sam has" << sam << " dollars"
                << endl
                << "sum has" << sum << " dollars" << endl;
        sam += 1;
        sum += 1;
        cout << "\n\nsam has" << sam << " dollars"
                << endl
                << "sum has" << sum << " dollars" 
                << endl;

        return 0;

}


/*
sam has32767 dollars
sum has65535 dollars


sam has-32768 dollars
sum has0 dollars

*/
```

---

### 类型选择

- 默认情况下，使用`int`
- 若有明确需求，对于符号的使用，对于范围的明确，可选择合适的类型

### 整型字面量

- 计算机使用二进制，C++中对于字面量的进制使用做出以下规范
  - 如果第一位为1～9，则基数为10  
  - 如果第一位是0，第二位为1～7，则基数为8  
  - 如果前两位为0x或0X，则基数为16  

```cpp
#include<iostream>

int main(void)
{
        using namespace std;
        int cheat = 42;
        int waist = 0x42;
        int insait = 042;

        cout << cheat << endl;
        cout << waist << endl;
        cout << insait << endl;

        return 0;
}


```

- `cout`默认输出10进制数字
  - hex 十六进制
  - oct八进制
  - 通过以上控制符可以修改cout的输出形式

---

### C++如何确定常量类型？

- 除非有理由存储为其他类型（如使用了特殊的后缀来表示特定的类型， 或者值太大， 不能存储为`int`） ， 否则`C++`将整型常量存储为`int`类型  
  - 后缀是放在数字常量后面的字母， 用于表示类型。 整数后面的l或L后缀表示该整数为`long`常量， `u`或`U`后缀表示`unsigned int`常量， `ul`（可以采用任何一种顺序， 大写小写均可） 表示`unsigned long`常量  

---

### `char`

- `char`其实也是整型，编程语言通过使用字母的数值编码解决了字符存储的问题，虽然char最常被用来处理字符， 但也可以将它用做比short更小的整型。  

- ```cpp
  #include<iostream>
  
  int main(void)
  {
      using namespace std;
      
      char a = 'M';
      int i = a;
      
      cout << a << "\'s code is " << i << endl;
       
      return 0;
  }
  ```

- 