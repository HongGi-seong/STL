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
	
	// ����1) �ڿ��� �߰�
	receivePackets.push_back(pkt2);
	receivePackets.push_back(pkt3);

	// ����2) �տ��� �߰�
	receivePackets.push_front(pkt1);

	deque<packet>::iterator iterPos;
	for(iterPos = receivePackets.begin();
		iterPos != receivePackets.end();
		iterPos++
	   )
		cout << "�ε���: " << iterPos->index << " �ٵ�ũ��: " << iterPos->bodySize << endl;
	cout << endl;

	// ����3) ����
	deque<packet>::reverse_iterator iterReversePos = receivePackets.rbegin();
	for(iterReversePos; iterReversePos != receivePackets.rend(); iterReversePos++)
		cout << "�ε���: " << iterReversePos->index << " �ٵ�ũ��: " << iterReversePos->bodySize << endl;
	cout << endl;

	int dequeSize = receivePackets.size();
	for(int index=0; index < dequeSize; index++)
		cout<< "�ε���: " << receivePackets[index].index << " �ٵ�ũ��: " << receivePackets[index].bodySize << endl;
	cout << endl;

	// ����4) ù��°, �������� �ִ� ������
	packet& firstPacket = receivePackets.front();
	cout << "ù��° ��Ŷ�� �ε���: " << firstPacket.index << endl ;

	packet& lastPacket = receivePackets.back();
	cout << "������ ��Ŷ�� �ε���: " << lastPacket.index << endl ;

	// ����5) at�� ����Ͽ� �ι�° �����Ϳ� ����
	packet& atPacket = receivePackets.at(1);
	cout << "�ι�° ��Ŷ�� �ε���: " << atPacket.index << endl ;

	// ����6) ù��° ������ ����
	receivePackets.pop_front();
	cout << "������ �� ù��° �������� �ε���: " << receivePackets[0].index << endl;

	// ����7) ������ ������ ����
	receivePackets.pop_back();
	lastPacket = receivePackets.back();
	cout << "������ �� ������ �������� �ε���: " << lastPacket.index << endl;

	// ����8) ��� ��Ŷ ����
	if(receivePackets.empty() == false)
	{
		receivePackets.clear();
		cout << "��� �����͸� �����մϴ�." << endl << endl ;
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

	// ����1) iterator insert (iterator where, const Type& value)
	receivePackets.insert(receivePackets.begin(), pkt3);
	deque<packet>::iterator iterPos = receivePackets.begin();
	for(iterPos; iterPos != receivePackets.end(); iterPos++)
		cout << "�ε���: " << iterPos->index << " ������: " << iterPos->bodySize << endl;
	cout << endl;

	// ����2) void insert (iterator where, size_type count, const Type& value)
	receivePackets.insert(++receivePackets.begin(), 2, pkt4);
	for(iterPos = receivePackets.begin();
		iterPos != receivePackets.end();
		iterPos++
	   )	
		cout << "�ε���: " << iterPos->index << " ������: " << iterPos->bodySize << endl;
	cout << endl; 

	// ����3) template void insert(iterator where, InputIterator first, InputIterator last)
	deque<packet> receivePackets2;
	receivePackets2.push_back(pkt3);
	receivePackets2.push_back(pkt4);
	receivePackets2.push_back(pkt1);

	receivePackets.insert(receivePackets.begin(), receivePackets2.begin(), receivePackets2.end());
	for(iterPos=receivePackets.begin(); iterPos != receivePackets.end(); iterPos++)
		cout << "�ε���: " << iterPos->index << " ������: " << iterPos->bodySize << endl;
	cout << endl;

	// ����4) �ι�° ���� ����
	receivePackets.erase(++receivePackets.begin());
	for(iterPos=receivePackets.begin(); iterPos != receivePackets.end(); iterPos++)
		cout << "�ε���: " << iterPos->index << " ������: " << iterPos->bodySize << endl;
	cout << endl;

	// ����5) ù��° ���� ���� ����
	receivePackets.erase(++receivePackets.begin(), receivePackets.end());
	for(iterPos=receivePackets.begin(); iterPos != receivePackets.end(); iterPos++)
		cout << "�ε���: " << iterPos->index << " ������: " << iterPos->bodySize << endl;
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
		cout << "��: " << *iterPos << endl;
	cout << endl;

	deque<int> assignDeque2;
	assignDeque2.assign(assignDeque.begin(), assignDeque.end());
	for(iterPos = assignDeque2.begin(); iterPos != assignDeque2.end(); iterPos++)
		cout << "��: " << *iterPos << endl;
	cout << endl;

	// swap
	deque<int> assignDeque3;
	assignDeque3.push_back(10);
	assignDeque3.push_back(20);
	assignDeque3.push_back(30);

	assignDeque3.swap(assignDeque);
	for(iterPos = assignDeque.begin(); iterPos != assignDeque.end(); iterPos++)
		cout << "��: " << *iterPos << endl;
	cout << endl;

	return 0;
}
#endif
