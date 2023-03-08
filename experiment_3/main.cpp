#include<iostream>
#include<string>
#define maxsize 16
using namespace std;
typedef struct 
{
	int data[maxsize];
	int front, rear;
}queue;
void initqueue(queue& q) 
{
	q.rear = q.front = 0;
}
bool isempty(queue q)
{
	if (q.rear == q.front) return true;
	else return false;
}
bool isfull(queue q)
{
	if ((q.rear + 1) % maxsize == q.front) return true;
	else return false;
}
void enqueue(queue& q, int x) 
{
	if (isfull(q)) cout << "������" << endl;
	else {
		q.data[q.rear] = x;
		q.rear = (q.rear + 1) % maxsize;
	}
}
void dequeue(queue& q,int n) 
{
	int t = n;
	int i = 0;
	queue p = q;
		while (n > 0)
		{
			if (isempty(p))
			{
				cout << "���п�" << endl;
				i = 1;
				break;
			}
		
			//cout << q.data[q.front] << " ";
			p.front = (p.front + 1) % maxsize;
			n--;
		}
		n = t;
		if (i == 0)
		{
			while (n > 0)
			{
				cout << q.data[q.front] << " ";
				q.front = (q.front + 1) % maxsize;
				n--;
			}
		}

	
}
//void gethead(queue q) 
//{
//	if (isempty(q))  cout << "���п�" << endl;
//	else {
//		cout << q.data[q.front] << endl;
//	}
//}
int main() 
{
	queue q;
	initqueue(q);
	int n;
	
	while (1)
	{
		cout << "������������ݸ�����";
		cin >> n;
		int m;
		cout << "���������ݣ�";
		while (n > 0)
		{
			cin >> m;
			enqueue(q, m);
			n--;
		}
		cout << "������������ݸ�����";
		int t;
		cin >> t;
		dequeue(q, t);
		string str;
		cout << '\n' << "�Ƿ��˳���";
		cin >> str;
		
		if (str == "Yes")
		{
			break;
		}
	}
	return 0;
}