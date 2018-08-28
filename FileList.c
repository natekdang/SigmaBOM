#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "filelist.h"



FILE_TYPE * NewFile(
	char *						szItem1,
	char *						szItem2,
	char *						szItem3,
	char *						szItem4,
	char *						szItem5,
	char *						szItem6,
	char *						szItem7,
	char *						szItem8
)
{
	FILE_TYPE *					p;
	int							length;


	p = ( FILE_TYPE * ) malloc( sizeof( FILE_TYPE ) );
	if( p == NULL )
	{
		// Log

		// Close log

	}

	else
	{
		memset( p, 0, sizeof( FILE_TYPE ) );

		if( szItem1 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem1 );
		}

		p->szItem1 = ( char * ) malloc( length + 8 );
		if( p->szItem1 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem1 == NULL )
		{
			strcpy( p->szItem1, "" );
		}

		else
		{
			strcpy( p->szItem1, szItem1 );
		}


		if( szItem2 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem2 );
		}

		p->szItem2 = ( char * ) malloc( length + 8 );
		if( p->szItem2 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem2 == NULL )
		{
			strcpy( p->szItem2, "" );
		}

		else
		{
			strcpy( p->szItem2, szItem2 );
		}


		if( szItem3 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem3 );
		}

		p->szItem3 = ( char * ) malloc( length + 8 );
		if( p->szItem3 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem3 == NULL )
		{
			strcpy( p->szItem3, "" );
		}

		else
		{
			strcpy( p->szItem3, szItem3 );
		}

		if( szItem4 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem4 );
		}

		p->szItem4 = ( char * ) malloc( length + 8 );
		if( p->szItem2 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem4 == NULL )
		{
			strcpy( p->szItem4, "" );
		}

		else
		{
			strcpy( p->szItem4, szItem4 );
		}

		if( szItem5 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem5 );
		}

		p->szItem5 = ( char * ) malloc( length + 8 );
		if( p->szItem5 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem5 == NULL )
		{
			strcpy( p->szItem5, "" );
		}

		else
		{
			strcpy( p->szItem5, szItem5 );
		}

		if( szItem6 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem6 );
		}

		p->szItem6 = ( char * ) malloc( length + 8 );
		if( p->szItem6 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem6 == NULL )
		{
			strcpy( p->szItem6, "" );
		}

		else
		{
			strcpy( p->szItem6, szItem6 );
		}

		if( szItem7 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem7 );
		}

		p->szItem7 = ( char * ) malloc( length + 8 );
		if( p->szItem7 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem7 == NULL )
		{
			strcpy( p->szItem7, "" );
		}

		else
		{
			strcpy( p->szItem7, szItem7 );
		}

		if( szItem8 == NULL )
		{
			length = 8;
		}

		else
		{
			length = strlen( szItem8 );
		}

		p->szItem8 = ( char * ) malloc( length + 8 );
		if( p->szItem8 == NULL )
		{
			// Log

			// Close log

			p = NULL;
		}

		else if( szItem8 == NULL )
		{
			strcpy( p->szItem8, "" );
		}

		else
		{
			strcpy( p->szItem8, szItem8 );
		}

	}

	
	return( p );

}

void FreeFileList(
	FILE_LIST_TYPE *			pList
)
{
	FILE_TYPE *					p;


	if( ( pList->pHead == NULL ) || ( pList->pTail == NULL ) )
	{
		pList->pHead = pList->pTail = NULL;
	}

	else if( pList->pHead == pList->pTail )
	{
		free( pList->pHead->szItem1 );
		free( pList->pHead->szItem2 );
		free( pList->pHead->szItem3 );
		free( pList->pHead->szItem4 );
		free( pList->pHead->szItem5 );
		free( pList->pHead->szItem6 );
		free( pList->pHead->szItem7 );
		free( pList->pHead->szItem8 );
		free( pList->pHead );

		pList->pHead = pList->pTail = NULL;
	}

	else
	{
		p = pList->pHead;
		while( p->pNext != NULL )
		{
			pList->pHead = pList->pHead->pNext;

			free( p->szItem1 );
			free( p->szItem2 );
			free( p->szItem3 );
			free( p->szItem4 );
			free( p->szItem5 );
			free( p->szItem6 );
			free( p->szItem7 );
			free( p->szItem8 );
			free( p );

			p = pList->pHead;
		}

		pList->pHead = pList->pTail = NULL;


	}



}

void InsertFileList(
	FILE_LIST_TYPE *			pList,
	FILE_TYPE *					p
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


