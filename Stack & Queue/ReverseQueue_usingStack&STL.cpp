#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void Print(queue<int>& Queue)
{
	while (!Queue.empty())
	{
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

void Reverse(queue<int>& Queue)
{
	stack<int> Stack;
	while (!Queue.empty())
	{
		Stack.push(Queue.front());
		Queue.pop();
	}

	while (!Stack.empty())
	{
		Queue.push(Stack.top());
		Stack.pop();
	}
}

int main()
{
	queue<int> Queue;
	int i;

	//cout << "Queue before:" << endl;
	for (i = 0; i < 6; i++)
	{
		Queue.push(i);
		//Print(Queue);
	}

	cout << "Queue after:" << endl;
	Reverse(Queue);
	Print(Queue);
	
}