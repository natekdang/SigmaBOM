
#ifndef __H_FILELIST__
#define __H_FILELIST__





typedef struct _FILE_STRUCT {
	struct _FILE_STRUCT *		pNext;
	struct _FILE_STRUCT *		pPrev;

	char *						szItem1;
	char *						szItem2;
	char *						szItem3;
	char *						szItem4;
	char *						szItem5;
	char *						szItem6;
	char *						szItem7;
	char *						szItem8;

} FILE_TYPE;



typedef struct {
	FILE_TYPE *					pHead;
	FILE_TYPE *					pTail;

} FILE_LIST_TYPE;





FILE_TYPE * NewFile(
	char *						szItem1,
	char *						szItem2,
	char *						szItem3,
	char *						szItem4,
	char *						szItem5,
	char *						szItem6,
	char *						szItem7,
	char *						szItem8
);

void FreeFileList(
	FILE_LIST_TYPE *			pList
);

void InsertFileList(
	FILE_LIST_TYPE *			pList,
	FILE_TYPE *					p
);





#endif
