#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <strsafe.h>

typedef struct _USER
{
	LPTSTR Username;
	LPTSTR Password;
} USER, *PUSER;



// Allocates Memory for User struct
int CreateUser(PUSER *user);

// Destroys object including everything inside it
int DestroyUser(PUSER* user);


// Allocats memory for both strings
int SetUserData(PUSER user, LPTSTR Username, LPTSTR Password);


// get a string representation of the user of the following format:
// [username],[password]\n
// usrToString will have to be freed
int usrToString(PUSER user, LPTSTR* usrToString);


// returns TRUE if the username and password from both users are equal
// returns FALSE if any field is NULL or username or password differ
BOOL usrEquals(PUSER user1, PUSER user2);


// Assigns the usrString components to the user
// usrString has to be created by the function usrToString or respect the format: [username],[password]\n
// user has to be initialized with CreateUser function
int usrFromString(LPTSTR usrString, PUSER user);