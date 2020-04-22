#include "User.h"

int CreateUser(PUSER* user)
{
	PUSER newUser = (PUSER)malloc(sizeof(USER));

	if (newUser == NULL)
	{
		return -1;
	}

	*user = newUser;
	return 0;
}

int DestroyUser(PUSER* user)
{
	if (user == NULL || (*user) == NULL)
	{
		return -1;
	}

	free((*user)->Username);
	free((*user)->Password);
	free((*user));
	user = NULL;
	return 0;
}

int SetUserData(PUSER user, LPTSTR Username, LPTSTR Password)
{
	size_t usernameLen;
	size_t passwordLen;

	LPTSTR newUsername = NULL;
	LPTSTR newPassword = NULL;

	if (StringCchLength(Username, STRSAFE_MAX_CCH, &usernameLen) != S_OK)
	{
		goto cleanup;
	}

	newUsername = (LPTSTR)malloc((usernameLen + 1) * sizeof(TCHAR));
	if (newUsername == NULL)
	{
		goto cleanup;
	}
	
	if (StringCchLength(Password, STRSAFE_MAX_CCH, &passwordLen) != S_OK)
	{
		goto cleanup;
	}	
	newPassword = (LPTSTR)malloc((passwordLen + 1) * sizeof(TCHAR));
	if (newPassword == NULL)
	{
		goto cleanup;
	}

	if (StringCchCopy(newUsername, usernameLen + 1, Username) != S_OK)
	{
		goto cleanup;
	}
	if (StringCchCopy(newPassword, passwordLen + 1, Password) != S_OK)
	{
		goto cleanup;
	}

	user->Username = newUsername;
	user->Password = newPassword;
	return 0;


	cleanup:
		free(newUsername);
		free(newPassword);
		free(user->Username);
		free(user->Password);
		return -1;
}

int usrToString(PUSER user, LPTSTR* usrToString)
{
	size_t len;
	LPTSTR toReturn = NULL;

	size_t usernameLen;
	size_t passwordLen;

	if (user == NULL || user->Username == NULL || user->Password == NULL)
	{
		goto cleanup;
	}

	if (StringCchLength(user->Username, STRSAFE_MAX_CCH, &usernameLen) != S_OK)
	{
		goto cleanup;
	}
	if (StringCchLength(user->Password, STRSAFE_MAX_CCH, &passwordLen) != S_OK)
	{
		goto cleanup;
	}

	len = usernameLen + passwordLen + 3; // Add characters for separator, new line and \0x0	

	toReturn = (LPTSTR)malloc(len * sizeof(TCHAR));

	if (StringCchCopy(toReturn, len, user->Username) != S_OK)
	{
		goto cleanup;
	}

	if (StringCchCat(toReturn, len, TEXT(",")) != S_OK)
	{
		goto cleanup;
	}	
	if (StringCchCat(toReturn, len, user->Password) != S_OK)
	{
		goto cleanup;
	}
	if (StringCchCat(toReturn, len, TEXT("\n")) != S_OK)
	{
		goto cleanup;
	}

	*usrToString = toReturn;
	return 0;
	// newUsername = (LPTSTR)malloc((usernameLen + 1) * sizeof(TCHAR));
	// if (newUsername == NULL)
	// {
	// 	goto cleanup;
	// }
	cleanup:
		free(toReturn);
		return -1;
}

BOOL usrEquals(PUSER user1, PUSER user2)
{
	if (user1 == NULL || user2 == NULL || user1->Username == NULL || user2->Username == NULL || user1->Password == NULL || user2->Password == NULL)
	{
		return FALSE;
	}

	if (_tcscmp(user1->Username, user2->Username) == 0 && _tcscmp(user1->Username, user2->Username) == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}