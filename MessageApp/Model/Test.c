#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "User.h"

int _tmain(int argc, char** argv)
{
	PUSER user;
	LPTSTR username = TEXT("admin");
	LPTSTR password = TEXT("password");
	LPTSTR username2 = TEXT("ceva");

	PUSER user2;
	PUSER u;

	CreateUser(&user);
	CreateUser(&user2);
	CreateUser(&u);
	SetUserData(user, username, password);

	LPTSTR toStr;
	usrToString(user, &toStr);
	_tprintf_s(TEXT("%s"), toStr);

	SetUserData(user2, username2, password);

	usrFromString(toStr, u);
	

	BOOL ok = usrEquals(user, user2);
	if (ok == TRUE)
	{
		printf("SUCCESS");
	}
	else
	{
		printf("FAILURE");
	}
	
	DestroyUser(&user);
	DestroyUser(&user2);
	free(toStr);
	_CrtDumpMemoryLeaks();
}