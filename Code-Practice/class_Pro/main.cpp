#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// ============================================================
// 1. 类的基本定义、访问控制（public / private / protected）
// ============================================================
class Person {
private:
    string name;
    int age;

protected:
    string gender; // 子类可直接访问

public:
    // 2. 构造函数：默认构造、带参构造、初始化列表
    Person() : name("未知"), age(0), gender("未知") {
        cout << "  [Person] 默认构造: " << name << endl;
    }

    Person(const string& name, int age, const string& gender)
        : name(name), age(age), gender(gender) {
        cout << "  [Person] 带参构造: " << name << ", " << age << "岁" << endl;
    }

    // 3. 拷贝构造函数
    Person(const Person& other)
        : name(other.name), age(other.age), gender(other.gender) {
        cout << "  [Person] 拷贝构造: " << name << endl;
    }

    // 4. 移动构造函数 (C++11)
    Person(Person&& other) noexcept
        : name(move(other.name)), age(other.age), gender(move(other.gender)) {
        other.age = 0;
        cout << "  [Person] 移动构造: " << name << endl;
    }

    // 5. 析构函数
    virtual ~Person() {
        cout << "  [Person] 析构: " << name << endl;
    }

    // 6. 拷贝赋值运算符
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            gender = other.gender;
        }
        cout << "  [Person] 拷贝赋值: " << name << endl;
        return *this;
    }

    // 7. 移动赋值运算符
    Person& operator=(Person&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            age = other.age;
            gender = move(other.gender);
            other.age = 0;
        }
        cout << "  [Person] 移动赋值: " << name << endl;
        return *this;
    }

    // 8. this 指针的使用
    Person& setName(const string& name) {
        this->name = name;
        return *this; // 返回 *this 支持链式调用
    }

    Person& setAge(int age) {
        this->age = age;
        return *this;
    }

    // 9. 常成员函数 —— 承诺不修改对象状态
    string getName() const { return name; }
    int getAge() const { return age; }

    // 10. 静态成员：属于类而非对象
    static int count;
    static int getCount() { return count; }

    // 11. 友元函数：可以访问私有成员
    friend void showPersonSecret(const Person& p);

    // 12. 虚函数 —— 支持多态
    virtual void introduce() const {
        cout << "  我是" << name << ", " << age << "岁, " << gender << endl;
    }
};

// 静态成员初始化
int Person::count = 0;

// 友元函数实现
void showPersonSecret(const Person& p) {
    cout << "  [友元] " << p.name << "的秘密年龄是: " << p.age << endl;
}

// ============================================================
// 13. 继承 + 14. 多态（虚函数重写）
// ============================================================
class Student : public Person {
private:
    string school;
    double gpa;

public:
    Student(const string& name, int age, const string& gender,
            const string& school, double gpa)
        : Person(name, age, gender), school(school), gpa(gpa) {
        cout << "  [Student] 构造: " << name << " @ " << school << endl;
    }

    ~Student() override {
        cout << "  [Student] 析构: " << getName() << endl;
    }

    // override 显式重写虚函数
    void introduce() const override {
        cout << "  我是" << getName() << ", " << getAge() << "岁, "
             << gender << ", 在" << school << "上学, GPA=" << gpa << endl;
    }

    string getSchool() const { return school; }
};

// ============================================================
// 15. 运算符重载
// ============================================================
class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // 重载 + 运算符（成员函数方式）
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // 重载 - 运算符
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // 重载 * 运算符（点积）
    double operator*(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // 重载前置 ++ (++v)
    Vector2D& operator++() {
        ++x; ++y;
        return *this;
    }

    // 重载后置 ++ (v++)
    Vector2D operator++(int) {
        Vector2D temp = *this;
        ++x; ++y;
        return temp;
    }

    // 重载 << 友元方式
    friend ostream& operator<<(ostream& os, const Vector2D& v);

    // 重载 [] 运算符
    double& operator[](int index) {
        return index == 0 ? x : y;
    }

    double magnitude() const { return sqrt(x * x + y * y); }
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// ============================================================
// 16. 抽象类与纯虚函数
// ============================================================
class Shape {
public:
    virtual double area() const = 0;       // 纯虚函数
    virtual string type() const = 0;
    virtual ~Shape() = default;

    // 普通成员函数也可以有
    void describe() const {
        cout << "  " << type() << " 面积 = " << area() << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    string type() const override { return "圆形(r=" + to_string(radius) + ")"; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    string type() const override { return "矩形(" + to_string(width) + "x" + to_string(height) + ")"; }
};

// ============================================================
// 17. 组合（has-a 关系）
// ============================================================
class Engine {
public:
    int horsepower;
    Engine(int hp) : horsepower(hp) {
        cout << "  [Engine] 构造, 马力=" << horsepower << endl;
    }
    ~Engine() { cout << "  [Engine] 析构" << endl; }
    void start() const { cout << "  发动机启动! 马力=" << horsepower << endl; }
};

class Car {
private:
    string brand;
    Engine engine; // 组合：Car 拥有 Engine
public:
    Car(const string& brand, int hp) : brand(brand), engine(hp) {
        cout << "  [Car] 构造: " << brand << endl;
    }
    ~Car() { cout << "  [Car] 析构: " << brand << endl; }
    void drive() const {
        engine.start();
        cout << "  " << brand << " 正在行驶..." << endl;
    }
};

// ============================================================
// 演示函数
// ============================================================
void demoBasicClass() {
    cout << "\n===== 1. 基本类与构造/析构 =====" << endl;
    Person p1;                                    // 默认构造
    Person p2("张三", 25, "男");                  // 带参构造
    Person p3 = p2;                               // 拷贝构造
    Person p4("临时", 1, "女");
    Person p5 = move(p4);                         // 移动构造

    p1 = p3;                                      // 拷贝赋值
    Person p6;
    p6 = Person("王五", 30, "男");                // 移动赋值

    cout << "\n--- 链式调用 (this指针) ---" << endl;
    p1.setName("李四").setAge(28);
    p1.introduce();

    cout << "\n--- 常成员函数 ---" << endl;
    const Person cp("赵六", 22, "男");
    cout << "  常对象只能调用const函数: name=" << cp.getName() << endl;

    cout << "\n--- 友元函数 ---" << endl;
    showPersonSecret(p2);

    cout << "\n--- 即将离开作用域，析构顺序 ---" << endl;
}

void demoStaticMember() {
    cout << "\n===== 2. 静态成员 =====" << endl;
    cout << "  当前Person数量: " << Person::getCount() << endl;
    // 注：count 未在构造中递增，这里仅演示用法
    Person::count = 100;
    cout << "  设置后: " << Person::getCount() << endl;
    Person::count = 0; // 还原
}

void demoInheritanceAndPolymorphism() {
    cout << "\n===== 3. 继承与多态 =====" << endl;

    // 直接使用子类
    Student stu("小明", 18, "男", "清华大学", 3.9);
    stu.introduce();

    // 多态：父类指针指向子类对象
    cout << "\n--- 多态（父类指针/引用调用虚函数）---" << endl;
    Person* ptr = new Student("小红", 19, "女", "北京大学", 4.0);
    ptr->introduce();  // 调用的是 Student::introduce
    delete ptr;        // 因为基类析构是 virtual，会正确调用子类析构

    // 多态：引用
    cout << "\n--- 多态（父类引用）---" << endl;
    Student stu2("小刚", 20, "男", "复旦大学", 3.5);
    Person& ref = stu2;
    ref.introduce();
}

void demoOperatorOverloading() {
    cout << "\n===== 4. 运算符重载 =====" << endl;
    Vector2D v1(3, 4), v2(1, 2);

    Vector2D v3 = v1 + v2;
    cout << "  v1 + v2 = " << v3 << endl;

    Vector2D v4 = v1 - v2;
    cout << "  v1 - v2 = " << v4 << endl;

    cout << "  v1 · v2 = " << (v1 * v2) << endl;

    ++v1;
    cout << "  ++v1 = " << v1 << endl;

    Vector2D v5 = v2++;
    cout << "  v2++ => v5=" << v5 << ", v2=" << v2 << endl;

    cout << "  v1[0]=" << v1[0] << ", v1[1]=" << v1[1] << endl;
    v1[0] = 10;
    cout << "  v1[0]=10后: " << v1 << endl;
}

void demoAbstractClass() {
    cout << "\n===== 5. 抽象类与纯虚函数 =====" << endl;
    // Shape s; // 错误！抽象类不能实例化

    Circle c(5);
    Rectangle r(4, 6);

    // 通过基类指针实现多态
    Shape* shapes[] = {&c, &r};
    for (auto s : shapes) {
        s->describe();
    }
}

void demoComposition() {
    cout << "\n===== 6. 组合（has-a） =====" << endl;
    Car car("比亚迪", 200);
    car.drive();
    cout << "  --- Car 即将析构 ---" << endl;
}

void demoMemoryLayout() {
    cout << "\n===== 7. 对象内存与sizeof =====" << endl;
    cout << "  sizeof(Person)    = " << sizeof(Person) << " 字节" << endl;
    cout << "  sizeof(Student)   = " << sizeof(Student) << " 字节" << endl;
    cout << "  sizeof(Vector2D)  = " << sizeof(Vector2D) << " 字节" << endl;
    cout << "  sizeof(Circle)    = " << sizeof(Circle) << " 字节" << endl;
    cout << "  sizeof(Rectangle) = " << sizeof(Rectangle) << " 字节" << endl;
    cout << "  注: 含虚函数的类有虚表指针(vptr)开销" << endl;
}

// ============================================================
// main
// ============================================================
int main() {
    system("chcp 65001");

    cout << "╔══════════════════════════════════════╗" << endl;
    cout << "║   C++ 类与对象 — 学习 Demo          ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;

    demoBasicClass();
    demoStaticMember();
    demoInheritanceAndPolymorphism();
    demoOperatorOverloading();
    demoAbstractClass();
    demoComposition();
    demoMemoryLayout();

    cout << "\n===== 全部演示结束 =====" << endl;
    return 0;
}
