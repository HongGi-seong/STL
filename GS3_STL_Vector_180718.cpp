#include <iostream>
#include <vector>
//#define BASIC 1
//#define INSERT 1
//#define ERASE 1
//#define ASSIGN 1
//#define RESERVE 1
#define SWAP 1

using namespace std;


#if BASIC
struct roomUser 
{
	int charCd;
	int level;

	roomUser(int fCharCd, int fLevel)
	{
		charCd = fCharCd;
		level = fLevel;
	}
};


int main(void)
{
	roomUser user1(1, 10);
	roomUser user2(2, 5);
	roomUser user3(3, 12);

	vector<roomUser> vectorUser;

	vectorUser.push_back(user1);
	vectorUser.push_back(user2);
	vectorUser.push_back(user3);

	// ����1) ���������� ���
	for(vector<roomUser>::iterator iterPos = vectorUser.begin();
		iterPos != vectorUser.end();
		iterPos++
	   )
	{
		cout << "ĳ�����ڵ�: " << iterPos->charCd << "  //ĳ���ͷ���: " << iterPos->level << endl;
	}
	cout << endl;

	// ����2) ���������� ���
	for(vector<roomUser>::reverse_iterator iterPos = vectorUser.rbegin();
		iterPos != vectorUser.rend();
		iterPos++
	   )
	{
		cout << "ĳ�����ڵ�: " << iterPos->charCd << "  //ĳ���ͷ���: " << iterPos->level << endl;
	}
	cout << endl;

	// ����3) �迭�� ���
	for(int index=0; index<vectorUser.size(); index++)
	{
		cout << "ĳ�����ڵ�: " << vectorUser[index].charCd << "  //ĳ���ͷ���: " << vectorUser[index].level << endl;
	}
	cout << endl;

	// ����4) ù��° ���� ������ ����
	roomUser& firstUser = vectorUser.front();
	cout << "ĳ�����ڵ�: " << firstUser.charCd << "  //ĳ���ͷ���: " << firstUser.level << endl << endl;

	// ����5) ������ ���� ������ ����
	roomUser& lastUser = vectorUser.back();
	cout << "ĳ�����ڵ�: " << lastUser.charCd << "  //ĳ���ͷ���: " << lastUser.level << endl << endl;

	// ����6) at�� ����Ͽ� ���� ������ ����
	roomUser& atUser = vectorUser.at(1);
	cout << "ĳ�����ڵ�: " << atUser.charCd << "  //ĳ���ͷ���: " << atUser.level << endl << endl;

	// ����7) ���� 1�� ����
	vectorUser.pop_back();
	for(vector<roomUser>::iterator iterPos = vectorUser.begin();
		iterPos != vectorUser.end();
		iterPos++
	   )
	{
		cout << "ĳ�����ڵ�: " << iterPos->charCd << "  //ĳ���ͷ���: " << iterPos->level << endl;
	}
	cout << endl;

	// ����8) ���� �� Ȯ��
	cout << "���� ���� ��: " << vectorUser.size() << endl << endl;


	// ����9) ���� ���� ����
	vectorUser.clear();
	cout << "���� ���� ��: " << vectorUser.size() << endl << endl;

	return 0;

}


#elif INSERT

int main(void)
{
	vector<int> insertVector;

	insertVector.push_back(20);
	insertVector.push_back(30);

	// ����1) iterator insert(iterator where, const Type& value)
	vector<int>::iterator iterBegin = insertVector.begin();
	insertVector.insert(iterBegin, 100);

	for(vector<int>::iterator iterPos = insertVector.begin();
		iterPos != insertVector.end();
		iterPos++
	   )
	{
		cout << "��: " << *iterPos << endl;
	}
	cout << endl;

	// ����2) void insert(iterator where, size_type count, const Type& value) 
	vector<int>::iterator iterWhere = insertVector.begin();
	insertVector.insert(++iterWhere, 2, 200);
	
	for(vector<int>::iterator iterPos = insertVector.begin();
	 	iterPos != insertVector.end();
	 	iterPos++
	   )
	{
		cout << "��: "<< *iterPos << endl;
	}
	cout << endl;

	// ����3) template<class InputIterator> void insert(iterator where, InputIterator first, InputIterator last)
	vector<int> insertVector2;
	insertVector2.push_back(1000);
	insertVector2.push_back(2000);
	insertVector2.push_back(3000);

	vector<int>::iterator iterEx3 = insertVector.begin();
	insertVector.insert(++iterEx3, insertVector2.begin(), insertVector2.end());

	for(vector<int>::iterator iterPos = insertVector.begin();
	    iterPos != insertVector.end();
        iterPos++
       )
    {
        cout << "��: "<< *iterPos << endl;
    }
    cout << endl;

	return 0;
}	

#elif ERASE
int main(void)
{
	vector<int> eraseVector;

	eraseVector.push_back(10);
	eraseVector.push_back(20);
	eraseVector.push_back(30);
	eraseVector.push_back(40);
	eraseVector.push_back(50);
	
	int vectorSize = eraseVector.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "��: " << eraseVector[index] << endl;
	cout << endl;

	// ����1) iterator erase(iterator where) 
	eraseVector.erase(eraseVector.begin());
	vectorSize = eraseVector.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "��: " << eraseVector[index] << endl;
	cout << endl;

	// ����2) iterator erase(iterator first, iterator last)
	eraseVector.erase(eraseVector.begin(), eraseVector.end());
	if(eraseVector.empty())
		cout << "�����Ͱ� ���� �����Ǿ����ϴ�." << endl;
	else
		cout << "���� ����" << endl;
	cout << endl;

	return 0;
}

#elif ASSIGN
int main(void)
{
	vector<int> assignVector;

	// ����1) void assgin(size_type count, const Type& value)
	assignVector.assign(7, 4);
	int	vectorSize = assignVector.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "��: " << assignVector[index] << endl;
	cout << endl;

	// ����2) template<class InputIterator> void assign(InputIterator first, InputIterator last)
	vector<int> assignVector2;
	assignVector2.push_back(10);
	assignVector2.push_back(20);
	assignVector2.push_back(30);

	assignVector.assign(assignVector2.begin(), assignVector2.end());
	vectorSize = assignVector.size();
	for(int index=0; index < vectorSize; index++)
		cout << "��: " << assignVector[index] << endl;
	cout << endl;

	return 0;
}

#elif RESERVE
int main(void)
{
	vector<int> reserveVector;

	// ����1) void reserve(size_type count)
	reserveVector.reserve(10);

	return 0;
}

#elif SWAP
int main(void)
{
	vector<int> swapVector1;
	swapVector1.push_back(1);
	swapVector1.push_back(2);
	swapVector1.push_back(3);

	vector<int> swapVector2;
	swapVector2.push_back(10);
	swapVector2.push_back(20);
	swapVector2.push_back(30);
	swapVector2.push_back(40);
	swapVector2.push_back(50);
	
	int vectorSize = swapVector1.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "����1�� ��: " << swapVector1[index] << endl;
	cout << endl;

	vectorSize = swapVector2.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "����2�� ��: " << swapVector2[index] << endl;
	cout << endl << endl;

	swapVector1.swap(swapVector2);

	vectorSize = swapVector1.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "����1�� ��: " << swapVector1[index] << endl;
	cout << endl;

	vectorSize = swapVector2.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "����2�� ��: " << swapVector2[index] << endl;
	cout << endl << endl;
	
	return 0;
}





#endif


