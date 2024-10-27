#include "containers/MySet.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    MySet<int> set;

    set.add_element(1);
    set.add_element(2);
    set.add_element(3);
    set.add_element(4);
    set.add_element(5);

    std::cout << set << std::endl;

    MySet<int> set2(5);

    std::cout << set2 << std::endl;

    MySet<int> set3 = set - set2;

    std::cout << set3 << std::endl;
    MySet<int> tempSet(10);
    MySet<int> set4 = set3 + tempSet;

    std::cout << set4 << std::endl;

    MySet<int> five;
    five.add_element(4);
    five.add_element(5);
    five.add_element(6);
    five.add_element(7);
    five.add_element(8);
    five.add_element(9);

    std::cout << five << std::endl;

    MySet<int> out = five * set;

    std::cout << out << std::endl;

    MyVector<char *> v("Hello!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.delete_element(-1);
    std::cout << "Вектор v: " << v << std::endl;
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    MyVector<char *> v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
        v1.delete_element(0);
    std::cout << "Вектор v1: " << v1 << std::endl;
    std::cout << "================================" << std::endl;
    MySet<char *> s("Yes"), s1, s2;
    s.add_element("Привет!");
    s.add_element("No");
    char *str = "Hello!";
    s.add_element(str);
    std::cout << "Множество s: " << s << std::endl;
    s1.add_element("Cat");
    s1.add_element("No");
    s1.add_element("Привет!");
    std::cout << "Множество s1: " << s1 << std::endl;
    s2 = s1 - s;
    std::cout << "Множество s2=s1-s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s - s1;
    std::cout << "Множество s2=s-s1: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s1 + s;
    std::cout << "Множество s2=s1+s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    s2 = s1 * s;
    std::cout << "Множество s2=s1*s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;
    MySet s3 = s2;
    std::cout << "Множество s3=s2: " << s3 << std::endl;
    if (s3 == s2)
        std::cout << "Множество s3=s2\n";
    else
        std::cout << "Множество s3!=s2\n";
    if (s3 == s1)
        std::cout << "Множество s3=s1\n";
    else
        std::cout << "Множество s3!=s1\n";
    if (s1 == s3)
        std::cout << "Множество s1=s3\n";
    else
        std::cout << "Множество s1!=s3\n";

	return 0;
}
