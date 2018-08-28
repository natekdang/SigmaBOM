#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "bomlist.h"


REF_TYPE * NewRef(
	void
)
{
	REF_TYPE *					p;


	p = ( REF_TYPE * ) malloc( sizeof( REF_TYPE ) );
	if( p == NULL )
	{
		// Log

		// Close log

	}

	else
	{
		memset( p, 0, sizeof( REF_TYPE ) );
	}

	return( p );

}


void FreeRefList(
	REF_LIST_TYPE *				pList
)
{
	REF_TYPE *					p;


	if( ( pList->pHead == NULL ) || ( pList->pTail == NULL ) )
	{
		pList->pHead = pList->pTail = NULL;
		pList->iCount = 0;
	}

	else if( pList->pHead == pList->pTail )
	{
		free( pList->pHead );

		pList->pHead = pList->pTail = NULL;
		pList->iCount = 0;
	}

	else
	{
		p = pList->pHead;
		while( p->pNext != NULL )
		{
			pList->pHead = pList->pHead->pNext;

			free( p );

			p = pList->pHead;
		}

		pList->pHead = pList->pTail = NULL;
		pList->iCount = 0;


	}

}


void InsertRefList(
	REF_LIST_TYPE *				pList,
	REF_TYPE *					p
)
{
	if( pList->pHead == NULL )
	{
		p->pNext = NULL;
		p->pPrev = NULL;
		pList->pHead = pList->pTail = p;
		pList->iCount++;

	}

	else
	{
		p->pNext = NULL;
		p->pPrev = pList->pTail;
		pList->pTail->pNext = p;
		pList->pTail = p;
		pList->iCount++;
	}

}

void ReplaceRefList(
	REF_LIST_TYPE *				pList,
	REF_TYPE *					p,
	REF_LIST_TYPE *				pNewList

)
{
	// Single element
	if( ( p->pNext == NULL ) && ( p->pPrev == NULL ) )
	{
		pList->pHead = pNewList->pHead;
		pList->pTail = pNewList->pTail;
		pList->iCount = pNewList->iCount;
		free( p );
	}

	// First
	else if( p->pPrev == NULL )
	{
		pNewList->pTail->pNext = p->pNext;
		p->pNext->pPrev = pNewList->pTail;
		pList->pHead = pNewList->pHead;
		pList->iCount += ( pNewList->iCount - 1 );
		free( p );
	}

	// Last
	else if( p->pNext == NULL )
	{
		pNewList->pHead->pPrev = p->pPrev;
		p->pPrev->pNext = pNewList->pHead;
		pList->pTail = pNewList->pTail;
		pList->iCount += ( pNewList->iCount - 1 );
		free( p );
	}

	// Middle
	else
	{
		pNewList->pHead->pPrev = p->pPrev;
		p->pPrev->pNext = pNewList->pHead;
		pNewList->pTail->pNext = p->pNext;
		p->pNext->pPrev = pNewList->pTail;
		pList->iCount += ( pNewList->iCount - 1 );
		free( p );
	}

}


void AppendRefList(
	REF_LIST_TYPE *				pList,
	REF_LIST_TYPE *				pNewList

)
{
	// Check if the append list is empty
	if( pNewList->pHead == NULL || pNewList->pTail == NULL )
	{
		return;
	}

	// Empty
	if( pList->pHead == NULL )
	{
		pList->pHead = pNewList->pHead;
		pList->pTail = pNewList->pTail;
		pList->iCount = pNewList->iCount;

	}

	else
	{
		pNewList->pHead->pPrev = pList->pTail;
		pList->pTail->pNext = pNewList->pHead;
		pList->pTail = pNewList->pTail;
		pList->iCount += pNewList->iCount;
	}

	pNewList->pHead = NULL;
	pNewList->pTail = NULL;
	pNewList->iCount = 0;


}




BOM_TYPE * NewBom(
	void
)
{
	BOM_TYPE *					p;


	p = ( BOM_TYPE * ) malloc( sizeof( BOM_TYPE ) );
	if( p == NULL )
	{
		// Log

		// Close log

	}

	else
	{
		memset( p, 0, sizeof( BOM_TYPE ) );
	}

	return( p );

}


void FreeBomList(
	BOM_LIST_TYPE *				pList
)
{
	BOM_TYPE *					p;


	if( ( pList->pHead == NULL ) || ( pList->pTail == NULL ) )
	{
		pList->pHead = pList->pTail = NULL;
	}

	else if( pList->pHead == pList->pTail )
	{
		FreeRefList( &pList->pHead->RefList );
		free( pList->pHead );
		pList->pHead = pList->pTail = NULL;
	}

	else
	{
		p = pList->pHead;
		while( p->pNext != NULL )
		{
			pList->pHead = pList->pHead->pNext;

			FreeRefList( &p->RefList );
			free( p );

			p = pList->pHead;
		}

		pList->pHead = pList->pTail = NULL;


	}

}


void InsertBomList(
	BOM_LIST_TYPE *				pList,
	BOM_TYPE *					p
)
{
	if( pList->pHead == NULL )
	{
		p->pNext = NULL;
		p->pPrev = NULL;
		pList->pHead = pList->pTail = p;
	}

	else
	{
		p->pNext = NULL;
		p->pPrev = pList->pTail;
		pList->pTail->pNext = p;
		pList->pTail = p;
	}

}


void MergeBomList(
	BOM_LIST_TYPE *				pList,
	BOM_TYPE *					p1,
	BOM_TYPE *					p2
)
{
	// Remove p2 from the list
	// Last
	if( p2->pNext == NULL )
	{
		p2->pPrev->pNext = NULL;
		pList->pTail = p2->pPrev;
	}

	// Middle
	else
	{
		p2->pPrev->pNext = p2->pNext;
		p2->pNext->pPrev = p2->pPrev;
	}
	

	// Merge the count
	p1->NoParts += p2->NoParts;

	// Merge Ref List from p2 to p1
	AppendRefList( &p1->RefList, &p2->RefList );

	// free p2
	free( p2 );
}



void RemoveBomList(
	BOM_LIST_TYPE *				pList,
	BOM_TYPE *					p
)
{
	// One element
	if( p->pNext == NULL && p->pPrev == NULL )
	{
		pList->pHead = pList->pTail = NULL;
	}

	// First
	else if( p->pPrev == NULL )
	{
		p->pNext->pPrev = NULL;
		pList->pHead = p->pNext;
	}


	// Last
	else if( p->pNext == NULL )
	{
		p->pPrev->pNext = NULL;
		pList->pTail = p->pPrev;
	}

	// Middle
	else
	{
		p->pPrev->pNext = p->pNext;
		p->pNext->pPrev = p->pPrev;
	}
	

	// free p2
	free( p );
}


