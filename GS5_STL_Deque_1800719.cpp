#include<iostream>
#include<deque>
//#define BASIC 1
//#define INSERT_ERASE 1
#define ASSIGN_SWAP 1

using namespace std;


struct packet
{
	unsigned short 	index;
	unsigned short	bodySize;
	char			acBodyData[100];
};


#if BASIC
int main(void)
{
	packet pkt1;
	pkt1.index = 1;		pkt1.bodySize = 10;

	packet pkt2;
	pkt2.index = 2;		pkt2.bodySize = 12;

	packet pkt3;
	pkt3.index = 3;		pkt3.bodySize = 14;

	deque<packet> receivePackets;
	
	// 예제1) 뒤에서 추가
	receivePackets.push_back(pkt2);
	receivePackets.push_back(pkt3);

	// 예제2) 앞에서 추가
	receivePackets.push_front(pkt1);

	deque<packet>::iterator iterPos;
	for(iterPos = receivePackets.begin();
		iterPos != receivePackets.end();
		iterPos++
	   )
		cout << "인덱스: " << iterPos->index << " 바디크기: " << iterPos->bodySize << endl;
	cout << endl;

	// 예제3) 역순
	deque<packet>::reverse_iterator iterReversePos = receivePackets.rbegin();
	for(iterReversePos; iterReversePos != receivePackets.rend(); iterReversePos++)
		cout << "인덱스: " << iterReversePos->index << " 바디크기: " << iterReversePos->bodySize << endl;
	cout << endl;

	int dequeSize = receivePackets.size();
	for(int index=0; index < dequeSize; index++)
		cout<< "인덱스: " << receivePackets[index].index << " 바디크기: " << receivePackets[index].bodySize << endl;
	cout << endl;

	// 예제4) 첫번째, 마지막에 있는 데이터
	packet& firstPacket = receivePackets.front();
	cout << "첫번째 패킷의 인덱스: " << firstPacket.index << endl ;

	packet& lastPacket = receivePackets.back();
	cout << "마지막 패킷의 인덱스: " << lastPacket.index << endl ;

	// 예제5) at을 사용하여 두번째 데이터에 접근
	packet& atPacket = receivePackets.at(1);
	cout << "두번째 패킷의 인덱스: " << atPacket.index << endl ;

	// 예제6) 첫번째 데이터 삭제
	receivePackets.pop_front();
	cout << "삭제된 후 첫번째 데이터의 인덱스: " << receivePackets[0].index << endl;

	// 예제7) 마지막 데이터 삭제
	receivePackets.pop_back();
	lastPacket = receivePackets.back();
	cout << "삭제된 후 마지막 데이터의 인덱스: " << lastPacket.index << endl;

	// 예제8) 모든 패킷 삭제
	if(receivePackets.empty() == false)
	{
		receivePackets.clear();
		cout << "모든 데이터를 삭제합니다." << endl << endl ;
	}	

	return 0;

}


#elif INSERT_ERASE
int main(void)
{
	packet pkt1;
	pkt1.index = 1; pkt1.bodySize = 10;

	packet pkt2;
	pkt2.index = 2; pkt2.bodySize = 12;

	packet pkt3;
	pkt3.index = 3; pkt3.bodySize = 14;

	packet pkt4;
	pkt4.index = 4; pkt4.bodySize = 16;

	deque<packet> receivePackets;
	receivePackets.push_back(pkt1);
	receivePackets.push_back(pkt2);
	receivePackets.push_back(pkt3);

	// 예제1) iterator insert (iterator where, const Type& value)
	receivePackets.insert(receivePackets.begin(), pkt3);
	deque<packet>::iterator iterPos = receivePackets.begin();
	for(iterPos; iterPos != receivePackets.end(); iterPos++)
		cout << "인덱스: " << iterPos->index << " 사이즈: " << iterPos->bodySize << endl;
	cout << endl;

	// 예제2) void insert (iterator where, size_type count, const Type& value)
	receivePackets.insert(++receivePackets.begin(), 2, pkt4);
	for(iterPos = receivePackets.begin();
		iterPos != receivePackets.end();
		iterPos++
	   )	
		cout << "인덱스: " << iterPos->index << " 사이즈: " << iterPos->bodySize << endl;
	cout << endl; 

	// 예제3) template void insert(iterator where, InputIterator first, InputIterator last)
	deque<packet> receivePackets2;
	receivePackets2.push_back(pkt3);
	receivePackets2.push_back(pkt4);
	receivePackets2.push_back(pkt1);

	receivePackets.insert(receivePackets.begin(), receivePackets2.begin(), receivePackets2.end());
	for(iterPos=receivePackets.begin(); iterPos != receivePackets.end(); iterPos++)
		cout << "인덱스: " << iterPos->index << " 사이즈: " << iterPos->bodySize << endl;
	cout << endl;

	// 예제4) 두번째 원소 삭제
	receivePackets.erase(++receivePackets.begin());
	for(iterPos=receivePackets.begin(); iterPos != receivePackets.end(); iterPos++)
		cout << "인덱스: " << iterPos->index << " 사이즈: " << iterPos->bodySize << endl;
	cout << endl;

	// 예제5) 첫번째 이후 전부 삭제
	receivePackets.erase(++receivePackets.begin(), receivePackets.end());
	for(iterPos=receivePackets.begin(); iterPos != receivePackets.end(); iterPos++)
		cout << "인덱스: " << iterPos->index << " 사이즈: " << iterPos->bodySize << endl;
	cout << endl;

	return 0;
}


#elif ASSIGN_SWAP
int main(void)
{
	deque<int> assignDeque;
	deque<int>::iterator iterPos;
	
	// assign
	assignDeque.assign(7, 7);
	for(iterPos = assignDeque.begin(); iterPos != assignDeque.end(); iterPos++)
		cout << "값: " << *iterPos << endl;
	cout << endl;

	deque<int> assignDeque2;
	assignDeque2.assign(assignDeque.begin(), assignDeque.end());
	for(iterPos = assignDeque2.begin(); iterPos != assignDeque2.end(); iterPos++)
		cout << "값: " << *iterPos << endl;
	cout << endl;

	// swap
	deque<int> assignDeque3;
	assignDeque3.push_back(10);
	assignDeque3.push_back(20);
	assignDeque3.push_back(30);

	assignDeque3.swap(assignDeque);
	for(iterPos = assignDeque.begin(); iterPos != assignDeque.end(); iterPos++)
		cout << "값: " << *iterPos << endl;
	cout << endl;

	return 0;
}
#endif
