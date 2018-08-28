#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "log.h"




static FILE *					LogFhd = NULL;





int LogInit(
	char *						szPathName
)
{
	char						szOutputFileName[ 256 ];



	// Copy the file 
	strcpy( szOutputFileName, szPathName );
	strcat( szOutputFileName, "\\" );
	strcat( szOutputFileName, "output.txt" );

	// Open the message file
	LogFhd = fopen( szOutputFileName, "wb" );

	if( LogFhd == NULL )
	{
		return( -1 );
	}

	else
	{
		return( 0 );
	}
}



void LogClose(
	void
)
{
	if( LogFhd )
	{
		fclose( LogFhd );

		LogFhd = NULL;
	}
}



void LogWrite(
	char *						szMsg
)
{
	if( LogFhd == NULL )
	{
		return;
	}


	fprintf( LogFhd, "%s\r\n", szMsg );

}







