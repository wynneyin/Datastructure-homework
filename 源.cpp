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
		cout << "�ɹ�" << endl;
	}
	
	bool push(double item)
	{
		if (top1 == mSize - 1)
		{
			cout << "ջ�����" << endl;
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
			cout << "ջΪ��" << endl;
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
			cout << "ջΪ��" << endl;
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
		start = str.find_first_of(s, i);//���ҵ�һ�����ֻ��������
		end = str.find_first_of(Empty, i);//���ҵ�һ�ո�
		if (end == -1)
		{
			end = str.length();
		 }
		string TempStr = str.substr(start, end - start);//ȡ����һ��Ԫ��
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
		i = end + 1;//�����±���ƶ�
	}

}
int main()
{
	stack1 mystack;
	string str;
	getline(cin, str);
	calculate(str, mystack);



 }