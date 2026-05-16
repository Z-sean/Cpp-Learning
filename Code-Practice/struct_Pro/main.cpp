#include <iostream>

int main() {
    //结构体
    /*
     * 结构体是用于管理数据的
     * 通过点操作符访问与使用成员变量和成员方法
     * 赋值方式:
     *  1. 列表初始化
     *  2. 逐个赋值
     *  3. 定义构造函数进行初始化
     */
    struct Student {
        int ID;
        std::string name;
        double score;

        Student(int id, std::string name, double score) :
        ID(id), name(name), score(score) {}
    };

    //Student stu1{001,"zhaochen",90.99};

    /*
    Student stu2;
    stu2.ID = 100;
    stu2.name = "zhaochen";
    stu2.score = 90.99;
    */

    Student stu3(001,"zhaochen",90.99);

    /*
     * 结构体和类
     * 都有成员函数和成员方法
     * 都支持访问控制
     * 都支持继承和多态
     *
     * 结构体:默认是public的访问权限，一般用于存储公开的数据
     * 类:默认是private的访问权限。一般存储私有数据以及数据的操作方法
     */

    //嵌套结构体,结构体可以包含结构体类型的成员
    {
        struct Adress {
            std::string Private;
            std::string Location;
        };

        struct Student {
            std::string name;
            Adress address;
        };

        Student stu1{"zhaochen",
            {"shanxi","lvliang"}};
    }

    //结构体数组，可以创建包含多个结构体的数组
    {
        struct Student {
            std::string name;
            int ID;
        };
        Student stus[] = {
            {"zc",1},
            {"gwj",2}
        };
    }

    //结构体指针
    {
        struct Student {
            std::string name;
            int ID;
        };
        Student stu = {"zhaoc",11};
        Student* stuptr = &stu;
    }

    //结构体别名
    {
        typedef struct  {
            std::string name;
            int ID;
        } Student;

        using std = Student;
    }

    //结构体作为参数类型与返回值,推荐使用引用或者指针的形式传递



    return 0;
}
