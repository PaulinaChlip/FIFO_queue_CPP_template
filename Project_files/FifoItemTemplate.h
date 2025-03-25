#pragma once
#include <iostream>
#include "FifoException.h"
using namespace std;

template <typename U>
class FifoItem
{
public:
	FifoItem( U* pItem = NULL );
	virtual ~FifoItem( );

private:
	U* m_pItem;
	FifoItem* m_pNext;

	template <typename T> friend class FQueue;
};


template <typename U> FifoItem <U>::FifoItem( U* pItem /*= NULL*/ ){
	m_pItem = pItem ? new(nothrow) U( *pItem ) : NULL;
	if( !m_pItem ) throw FifoException( FIFO_ALLOCATION_ERROR );
	m_pNext = NULL;
}

template <typename U> FifoItem <U>:: ~FifoItem( ){
	delete m_pItem;
	m_pNext = NULL;
}

