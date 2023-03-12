#include <iostream>
#include <stack>
#include <string>
using namespace std;
enum errorcode 
{
    success, overflow, underflow
};
template<class T>
class Stack 
{
public:
    Stack() 
    {
        count = 0;
    }
    bool empty()const 
    {
        if (count == 0) return true;
        else return false;
    }
    bool full()const 
    {
        if (count == 50) return true;
        else return false;
    }
    template<class T>
    errorcode get_top(T& x)const 
    {
        if (empty()) return underflow;
        else {
            x = data[count - 1];
            return success;
        }
    }
    template<class T>
    errorcode push(const T x) 
    {
        if (full()) return overflow;
        data[count] = x;
        count++;
        return success;
    }
    errorcode pop() 
    {
        if (empty()) return underflow;
        count--;
        return success;
    }
private:
    int count;
    T data[50];
};

bool judge_1(char n) 
{
    if (n >= '0' && n <= '9') return 1;
    return 0;
}

int judge_2(char n) 
{
    if (n == '+' || n == '-')
        return 1;
    else if (n == '*' || n == '/')
        return 2;
    else if (n == '(' || n == ')')
        return 0;
    else
        return -1;
}

int result(char x, Stack<int>& num)
{
    int a, b;
    int c = 0;
    if (x == '+') 
    {
        num.get_top(a);
        num.pop();
        num.get_top(b);
        num.pop();
        c = a + b;
    }
    else if (x == '-')
    {
        num.get_top(a);
        num.pop();
        num.get_top(b);
        num.pop();
        c = b - a;
    }
    else if (x == '*')
    {
        num.get_top(a);
        num.pop();
        num.get_top(b);
        num.pop();
        c = a * b;
    }
    else if (x == '/')
    {
        num.get_top(a);
        num.pop();
        num.get_top(b);
        num.pop();
        c = b / a;
    }
    return c;
}

int change(char x) 
{
    int y;
    y = x - 48;
    return y;
}

int fun(string a) 
{
    Stack<int> s1;
    Stack<char> s2;
    a += '#';
    s2.push('#');
    for (int i = 0; i <= a.size(); i++) 
    {
        if (judge_1(a[i])) 
        {
            int sum = change(a[i]);
            while (judge_1(a[i + 1])) 
            {
                i++;
                sum = sum * 10 + change(a[i]);
            }
            s1.push(sum);
        }
        else
        {
            int k = 1;
            char x, y;
            s2.get_top(x);
            while (k)
            {
                if (judge_2(a[i]) > judge_2(x) || a[i] == '(') 
                {
                    s2.push(a[i]);
                    break;
                }
                else {
                    if (judge_2(a[i]) == judge_2(x) && judge_2(a[i]) == 0 || judge_2(a[i]) == judge_2(x) && judge_2(a[i]) == -1) 
                    {
                        s2.pop();
                        break;
                    }
                    else 
                    {
                        s1.push(result(x, s1));
                        s2.pop();
                        s2.get_top(y);
                        x = y;
                    }
                }
            }
        }
    }
    int p;
    s1.get_top(p);
    return p;
}

int main() 
{
    string a;
    cin >> a;
    cout << fun(a) << endl;
    return 0;
}