#include<iostream>
#include<string>
#include<stack>
# include <stdlib.h>
#define MAX_SIZE 20
using namespace std;
class stack1
{
private:
	int  mSize;
	int top1;
	double* st;
public:
	stack1()
	{
		mSize = MAX_SIZE;
		top1 = -1;
		st = new double[mSize];
		cout << "成功" << endl;
	}
	
	bool push(double item)
	{
		if (top1 == mSize - 1)
		{
			cout << "栈满溢出" << endl;
		}
		else
		{
			st[++top1] = item;
			return true;
		}


	};
	double pop()
	{
		if (top1 == -1)
		{
			cout << "栈为空" << endl;
			return false;
		}
		else
		{
			double item;
			item = st[top1--];
			return item;
		}
	}
	double top()
	{
		if (top1 == -1)
		{
			cout << "栈为空" << endl;
		}
		else
		{
			double TopNumber = -1;
			TopNumber = st[top1];
			return TopNumber;
		}

	}
};
bool calculate(string str, stack1 mystack)
{
	string Empty = " ";
	string ch = "+-*/";
	string numbers = "0123456789";
	string s = "0123456789+-*/#";
	int start, end;
	double num, secondnum, firstnum;
	for (int i = 0; i < str.length();)
	{
		start = str.find_first_of(s, i);//查找第一个数字或者运算符
		end = str.find_first_of(Empty, i);//查找第一空格
		if (end == -1)
		{
			end = str.length();
		 }
		string TempStr = str.substr(start, end - start);//取出这一个元素
		if ((TempStr == "+")||(TempStr == "-")||(TempStr == "*")|| (TempStr == "*"))
		{
			secondnum = mystack.top();
			mystack.pop();
			firstnum = mystack.top();
			mystack.pop();
			if (TempStr == "+")
			{
				num = secondnum + firstnum;
				//cout << num;
				mystack.push(num);
			}
			else if (TempStr == "-")
			{
				num = secondnum - firstnum;
				//cout << num;
				mystack.push(num);
			}
			else if (TempStr == "*")
			{
				num = secondnum * firstnum;
				//cout << num;
				mystack.push(num);
			}
			else if (TempStr == "/")
			{
				num = secondnum / firstnum;
				//cout << num;
				mystack.push(num);
			}
		}
		else if (TempStr == "#")
		{
			cout << mystack.pop();
			return true;
		}
		else
		{
			double temp;
			temp = stod(TempStr);
			mystack.push(temp);
		}
		i = end + 1;//控制下标的移动
	}

}
int main()
{
	stack1 mystack;
	string str;
	getline(cin, str);
	calculate(str, mystack);



 }