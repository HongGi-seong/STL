#include <iostream>
#include <list>

using namespace std;


struct polygon
{
	char name;
	int x, y;

	polygon(char fName, int fX, int fY)
	{
		name = fName;
		x = fX;
		y = fY;
	}
};


int main ( void ) 
{
	// 예제1) 오각형의 꼭지점을 순서대로 출력하기
	polygon A('A', 50, 200);
	polygon B('B', 20, 80);
	polygon C('C', 75, 10);
	polygon D('D', 130, 80);
	polygon E('E', 100, 200);

	list<polygon> polygonList ;

	polygonList.push_back(A);
	polygonList.push_back(B);
	polygonList.push_back(C);
	polygonList.push_back(D);
	polygonList.push_back(E);

	// 예제2) 점 F를 E 앞에 넣기
	polygon F('F', 180, 150); 
	list<polygon>::iterator iterF = polygonList.end();
	iterF--;
	polygonList.insert(iterF, F);

    // 예제3) 점 C를 삭제하기
	list<polygon>::iterator iterC = polygonList.begin();
	iterC++; iterC++;
	polygonList.erase(iterC);
	
	list<polygon>::iterator iterEnd = polygonList.end();
	for ( list<polygon>::iterator iterPos = polygonList.begin();
		iterPos != iterEnd ;
		iterPos++
		)
	{
		cout << "Name= " << iterPos->name << "  X= " << iterPos->x << "  Y= " << iterPos->y << endl ;
	}

	return 0;
}
