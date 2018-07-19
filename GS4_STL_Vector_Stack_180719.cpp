#include<iostream>
#include<vector>

using namespace std;

class Stack
{
	vector<int> vectorStack;

	public:
		void Push(int fData);
		int Pop(void);
		void Clear(void);
		bool Empty(void);
		int TopValue(void);
		int Size(void);
		void ShowStack(void);

		Stack(){Clear();}
};

void Stack::Push(int fData)
{
	vectorStack.push_back(fData);
}


int Stack::Pop(void)
{
	if(Stack::Empty() == false)
	{	
		int popData = vectorStack.back();
		vectorStack.pop_back();
		return popData;
	}
	else
		cout << "stack is empty" << endl;
}


void Stack::Clear(void)
{
	vectorStack.clear();
}


bool Stack::Empty(void)
{
	return vectorStack.empty();
}


int Stack::TopValue(void)
{
	return vectorStack.back();
}


int Stack::Size(void)
{
	return vectorStack.size();
}


void Stack::ShowStack(void)
{
	int stackSize = vectorStack.size();
	for( int index = stackSize - 1; index >= 0; index--)
		cout << "stack" << index << " value: " << vectorStack[index] << endl;
	cout << endl;
}


int main(void)
{
	Stack testStack;

	if(testStack.Empty())
		cout << "stack is empty" << endl;

	int data;
	while(true)
	{
		cin >> data;
		if(data == 0)
			break;
		else 
			testStack.Push(data);
	}

	testStack.ShowStack();

	cout << "stack size is " << testStack.Size() << endl;
	
	cout <<	testStack.Pop() << endl;
	cout <<	testStack.Pop() << endl;
	cout << testStack.Pop() << endl;
	cout << testStack.TopValue() << endl;
	cout << testStack.TopValue() << endl << endl;

	testStack.ShowStack();
	cout << endl; 

	cout << "Clear Stack" << endl;
	testStack.Clear();
	testStack.Pop();

	return 0;
}
