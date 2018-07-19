#include <iostream>
#include <list>

using namespace std ;


struct Item 
{
	int itemCd ;
	int buyMoney ;
	
	Item ( int fItemCd, int fBuyMoney )
	{
		itemCd = fItemCd ;
		buyMoney = fBuyMoney ;
	}
} ;


int main ( void ) 
{
//////////////////////////push, pop, front, back, begin, end, empty, clear ////////////////////////////
	list < Item > list1 ;
	
	Item item1 ( 1, 1000 ) ;
	list1.push_front ( item1 ) ;
	
	Item item2 ( 2, 2000 ) ;
	list1.push_front ( item2 ) ;
	
	Item item3 ( 3, 3000 ) ;
	list1.push_back ( item3 ) ;
	
	Item item4 ( 4, 4000 ) ;
	list1.push_back ( item4 ) ;
	
	
	for ( list < Item >:: iterator iterPos = list1.begin ( );
		iterPos != list1.end ( ) ;
		iterPos++
		)
		cout << "Item code= " << (*iterPos).itemCd << "  Item Price= " << (*iterPos).buyMoney << endl ;			

	list1.pop_front ( ) ;
	
	Item test = list1.front ( ) ;
	cout << endl << "Item Code= " << test.itemCd << endl ;
	
	list1.pop_back ( ) ;
	
	test = list1.back ( ) ;
	cout << endl << "Item Code= " << test.itemCd << endl ;

	if ( list1.empty ( ) == false ) {
		list < Item >:: size_type count = list1.size ( ) ;
		cout << endl << "The number of data= " << count << endl ;
	}
	
	list1.clear ( ) ;
	list < Item >:: size_type count = list1.size ( ) ;
	cout << endl << "The number of data= " << count << endl ;

/////////////////////////// insert /////////////////////////////////////////////////////////	
// case1 iterator insert ( iterator where, const Type& value )
// case2 void insert ( iterator where, size_type repeat, const Type& value ) 
// case3 template void insert ( iterator where, InputIterator first, InputIterator last ) 
////////////////////////////////////////////////////////////////////////////////////////////
	// case1
	list < int > list2 ;
	
	list2.push_back ( 40 ) ;
	
	list < int >:: iterator iterInsertPos = list2.begin ( ) ;
	list < int >:: iterator iterEnd = list2.end ( ) ;
	list2.insert ( iterInsertPos, 100 ) ;
	for ( list < int >::iterator iterPos = list2.begin ( ) ;
		iterPos != iterEnd;
		iterPos++ )
		cout << "list2 first case value= " << *iterPos << endl ; 
	
	// case2
	iterInsertPos = list2.begin ( ) ;
	++iterInsertPos ;
	list2.insert ( iterInsertPos, 2, 200 ) ;
	for ( list < int >:: iterator iterPos = list2.begin ( ) ;
		iterPos != list2.end ( ) ;
		iterPos++ ) 
		cout << "list2 second case value= " << *iterPos << endl ; 
	
	// case3
	list < int > list3 ;
	list3.push_back ( 1000 ) ;
	list3.push_back ( 2000 ) ;
	list3.push_back ( 3000 ) ;
	
	iterInsertPos = list2.begin ( ) ;
	list2.insert ( ++iterInsertPos, list3.begin ( ), list3.end ( ) ) ;
	for ( list < int >:: iterator iterPos = list2.begin ( ) ;
		iterPos != list2.end ( ) ;
		iterPos++ ) 
		cout << "list2 Third case value= " << *iterPos << endl ; 

//////////////////////////// erase /////////////////////////////
// case1 iterator erase ( iterator where ) 
// case2 iterator erase ( iterator first, iterator last ) 
////////////////////////////////////////////////////////////////
	cout << endl ;
	
	// vase1
	list2.erase ( list2.begin ( ) ) ;
	for ( list < int >:: iterator iterPos = list2.begin ( ) ;
		iterPos != list2.end ( ) ;
		iterPos++ 
		) 
		cout << "The erase case1= " << *iterPos << endl ; 
	
	// case2
	list < int >:: iterator iterErase = list2.begin ( ) ;
	iterErase++ ;
	list2.erase ( iterErase, list2.end ( ) ) ;
	for ( list < int >:: iterator iterPos = list2.begin ( ) ;
		iterPos != list2.end ( ) ;
		iterPos++ ) 
		cout << endl << "The erase case2= " << *iterPos << endl ; 
		
//////////////////////////// remove /////////////////////////////
// case1 void remove ( const Type& value ) 
// case2 list struct remove 
/////////////////////////////////////////////////////////////////
	cout << endl ;
	
	// case1
	list < int > removeList1 ;
	
	removeList1.push_back ( 10 ) ;
	removeList1.push_back ( 20 ) ;
	removeList1.push_back ( 20 ) ;
	removeList1.push_back ( 30 ) ;
	
	for ( list < int >:: iterator iterPos = removeList1.begin ( ) ;
		iterPos != removeList1.end ( ) ;
		iterPos++ 
		)
		cout << "The remove case1= " << *iterPos << endl ;
	
	cout << endl ;
	
	removeList1.remove ( 20 ) ;
	
	for ( list < int >:: iterator iterPos = removeList1.begin ( ) ;
		iterPos != removeList1.end ( ) ;
		iterPos++ 
		)
		cout << "The remove case1= " << *iterPos << endl ;

	// case2
	cout << endl ;
	
	list < Item* > removeList2 ;
	
	Item* pItem1 = new Item ( 1, 1000 ) ;
	removeList2.push_back ( pItem1 ) ;
	Item* pItem2 = new Item ( 2, 2000 ) ;
	removeList2.push_back ( pItem2 ) ;
	Item* pItem3 = new Item ( 3, 3000 ) ;
	removeList2.push_back ( pItem3 ) ;
	
	removeList2.remove ( pItem2 ) ;
	
	for ( list < Item* >:: iterator iterPos = removeList2.begin ( ) ;
		iterPos != removeList2.end ( ) ;
		iterPos++ 
		)
		cout << "The remove case2= " << ( *iterPos ) -> itemCd << endl ;
		
	delete pItem1 ; delete pItem2 ; delete pItem3 ;

	return 0 ;
}
















