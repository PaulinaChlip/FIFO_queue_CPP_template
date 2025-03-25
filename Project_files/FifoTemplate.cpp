
#include "FQueueTemplate.h"

int main( )
{
	try{
		FQueue<int> FIFO;
		int x = FIFO.FQEmpty( );
		cout << "Czy kolejka pusta: " << x << endl;
		int info1 = 6;
		FIFO.FQEnqueue( &info1 );
		int info2 = 12;
		FIFO.FQEnqueue( &info2 );
		int info3 = 20;
		FIFO.FQEnqueue( &info3 );
		x = FIFO.FQEmpty( );
		cout << "Czy kolejka pusta: " << x << endl;
		cout << *FIFO.FQDequeue( ) << endl;
		cout << *FIFO.FQDequeue( ) << endl;
		x = FIFO.FQEmpty( );
		cout << "Czy kolejka pusta: " << x << endl;
	}
	catch( FifoException& except ) {
		cerr << except.getReason( ) << endl;
	}
	catch( ... ) {
		cerr << "Caught all other exceptions." << endl;
	}

	return 0;
}