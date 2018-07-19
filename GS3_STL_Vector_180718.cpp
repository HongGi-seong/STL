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

	// 예제1) 순방향으로 출력
	for(vector<roomUser>::iterator iterPos = vectorUser.begin();
		iterPos != vectorUser.end();
		iterPos++
	   )
	{
		cout << "캐릭터코드: " << iterPos->charCd << "  //캐릭터레벨: " << iterPos->level << endl;
	}
	cout << endl;

	// 예제2) 역방향으로 출력
	for(vector<roomUser>::reverse_iterator iterPos = vectorUser.rbegin();
		iterPos != vectorUser.rend();
		iterPos++
	   )
	{
		cout << "캐릭터코드: " << iterPos->charCd << "  //캐릭터레벨: " << iterPos->level << endl;
	}
	cout << endl;

	// 예제3) 배열로 출력
	for(int index=0; index<vectorUser.size(); index++)
	{
		cout << "캐릭터코드: " << vectorUser[index].charCd << "  //캐릭터레벨: " << vectorUser[index].level << endl;
	}
	cout << endl;

	// 예제4) 첫번째 유저 데이터 접근
	roomUser& firstUser = vectorUser.front();
	cout << "캐릭터코드: " << firstUser.charCd << "  //캐릭터레벨: " << firstUser.level << endl << endl;

	// 예제5) 마지막 유저 데이터 접근
	roomUser& lastUser = vectorUser.back();
	cout << "캐릭터코드: " << lastUser.charCd << "  //캐릭터레벨: " << lastUser.level << endl << endl;

	// 예제6) at을 사용하여 유저 데이터 접근
	roomUser& atUser = vectorUser.at(1);
	cout << "캐릭터코드: " << atUser.charCd << "  //캐릭터레벨: " << atUser.level << endl << endl;

	// 예제7) 유저 1명 삭제
	vectorUser.pop_back();
	for(vector<roomUser>::iterator iterPos = vectorUser.begin();
		iterPos != vectorUser.end();
		iterPos++
	   )
	{
		cout << "캐릭터코드: " << iterPos->charCd << "  //캐릭터레벨: " << iterPos->level << endl;
	}
	cout << endl;

	// 예제8) 유저 수 확인
	cout << "현재 유저 수: " << vectorUser.size() << endl << endl;


	// 예제9) 유저 전부 삭제
	vectorUser.clear();
	cout << "현재 유저 수: " << vectorUser.size() << endl << endl;

	return 0;

}


#elif INSERT

int main(void)
{
	vector<int> insertVector;

	insertVector.push_back(20);
	insertVector.push_back(30);

	// 예제1) iterator insert(iterator where, const Type& value)
	vector<int>::iterator iterBegin = insertVector.begin();
	insertVector.insert(iterBegin, 100);

	for(vector<int>::iterator iterPos = insertVector.begin();
		iterPos != insertVector.end();
		iterPos++
	   )
	{
		cout << "값: " << *iterPos << endl;
	}
	cout << endl;

	// 예제2) void insert(iterator where, size_type count, const Type& value) 
	vector<int>::iterator iterWhere = insertVector.begin();
	insertVector.insert(++iterWhere, 2, 200);
	
	for(vector<int>::iterator iterPos = insertVector.begin();
	 	iterPos != insertVector.end();
	 	iterPos++
	   )
	{
		cout << "값: "<< *iterPos << endl;
	}
	cout << endl;

	// 예제3) template<class InputIterator> void insert(iterator where, InputIterator first, InputIterator last)
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
        cout << "값: "<< *iterPos << endl;
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
		cout << "값: " << eraseVector[index] << endl;
	cout << endl;

	// 예제1) iterator erase(iterator where) 
	eraseVector.erase(eraseVector.begin());
	vectorSize = eraseVector.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "값: " << eraseVector[index] << endl;
	cout << endl;

	// 예제2) iterator erase(iterator first, iterator last)
	eraseVector.erase(eraseVector.begin(), eraseVector.end());
	if(eraseVector.empty())
		cout << "데이터가 전부 삭제되었습니다." << endl;
	else
		cout << "삭제 실패" << endl;
	cout << endl;

	return 0;
}

#elif ASSIGN
int main(void)
{
	vector<int> assignVector;

	// 예제1) void assgin(size_type count, const Type& value)
	assignVector.assign(7, 4);
	int	vectorSize = assignVector.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "값: " << assignVector[index] << endl;
	cout << endl;

	// 예제2) template<class InputIterator> void assign(InputIterator first, InputIterator last)
	vector<int> assignVector2;
	assignVector2.push_back(10);
	assignVector2.push_back(20);
	assignVector2.push_back(30);

	assignVector.assign(assignVector2.begin(), assignVector2.end());
	vectorSize = assignVector.size();
	for(int index=0; index < vectorSize; index++)
		cout << "값: " << assignVector[index] << endl;
	cout << endl;

	return 0;
}

#elif RESERVE
int main(void)
{
	vector<int> reserveVector;

	// 예제1) void reserve(size_type count)
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
		cout << "벡터1의 값: " << swapVector1[index] << endl;
	cout << endl;

	vectorSize = swapVector2.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "벡터2의 값: " << swapVector2[index] << endl;
	cout << endl << endl;

	swapVector1.swap(swapVector2);

	vectorSize = swapVector1.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "벡터1의 값: " << swapVector1[index] << endl;
	cout << endl;

	vectorSize = swapVector2.size();
	for(int index = 0; index < vectorSize; index++)
		cout << "벡터2의 값: " << swapVector2[index] << endl;
	cout << endl << endl;
	
	return 0;
}





#endif


