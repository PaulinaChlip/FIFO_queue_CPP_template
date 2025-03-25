#pragma once
#define FIFO_ALLOCATION_ERROR 0x01
#define FIFO_MISSING_QUEUE 0x02
#define FIFO_QUEUE_EMPTY 0x08
#define OTHER_ERROR 0x10

class FifoException
{
public:
	FifoException( int errCode = OTHER_ERROR ) : m_errCode( errCode ) {}
	const char* getReason( );
private:
	int m_errCode;
};

inline const char* FifoException::getReason( ){
	switch( m_errCode )
	{
		case FIFO_ALLOCATION_ERROR: return  "Allocation error!\n"; break;
		case FIFO_MISSING_QUEUE: return "Missing queue!\n"; break;
		case FIFO_QUEUE_EMPTY: return "Empty queue!\n"; break;
		case OTHER_ERROR: return "Other error!\n"; break;
		default: return "Unknown error!\n";
	}
}