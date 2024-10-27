#include "MyStack/MyStack.h"
using namespace std;

static void Multipliers(int n, MyStack<int>& stack)
{
    int temp = n;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            stack.push(i);
            n /= i;
        }
        else
        {
            i++;
        }
    }

    if (n >= 1)
    {
        stack.push(n);
    }
}

 

int main()
{
    setlocale(LC_ALL, "Rus");
	MyStack <char> stack;
    MyStack <char> stack2;
    MyStack <int> stack4;

    stack.push('a');
    stack.push('b');
    stack.push('c');
  
    stack2 = stack;

    MyStack stack3(stack);

    int n = 0;

    while (!(std::cin >> n) or (n <= 0))
    {
        std::cout << "Ошибка ввода: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

	Multipliers(n, stack4);
    
    stack.PrintStack();
    stack2.PrintStack();
    stack3.PrintStack();
    stack4.PrintStackM(n);

    stack3.PrintStackReverse();
    cout << endl;
    stack4.PrintStackReverseM(n);

	return 0;
}
