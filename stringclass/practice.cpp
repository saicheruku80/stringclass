#include<Windows.h>
#include<iostream>
BOOL MultiByteStrFromWideCharStr(
	UINT uiCodePage,
	CONST WCHAR* modelname,
	CHAR** ch,
	LPCCH lpDefaultChar = " "
)

{
	DWORD dwSize = 0;
	//VERBOSE(("CHPCommon::BGetMultiByteStrFromWideCharStr Start\n"));

	//[NN]Merging the CPE fix for NULL Job name issue.
	//Adding NULL check for Document Name for CR#3368
	if (NULL == modelname)
	{
		return  FALSE;
	}
	//[end of change for CR3368]

	//Get the size of the CHAR string
	dwSize = WideCharToMultiByte(uiCodePage, 0, (LPCWSTR)modelname, -1, NULL, (INT)0, lpDefaultChar, NULL);

	//Basic Validation
	if (dwSize == 0)
	{
		return FALSE;
	}

	//Account for the end of string character
	dwSize = (dwSize + 1) * sizeof(WCHAR);

	//Allocate memory for the CHAR array
	*ch = new CHAR[dwSize];

	//Get the feature name as a CHAR string
	if (!(WideCharToMultiByte(uiCodePage, 0, (LPCWSTR)modelname, -1, *ch, (INT)dwSize, lpDefaultChar, NULL)))
	{

		//Free the memory
		if (*ch)
		{
			free(*ch);
		}
		return FALSE;
	}

	//VERBOSE(("CHPCommon::BGetMultiByteStrFromWideCharStr Finish\n"));

	return TRUE;
}
int main() {
	char* ch = NULL;
	LPCCH DefChar = " ";
	WCHAR modelname[256] = L"hello";
	MultiByteStrFromWideCharStr(CP_ACP, modelname, &ch);
	std::cout << ch;
}