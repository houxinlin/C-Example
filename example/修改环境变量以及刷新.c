#include <Windows.h>
#include <stdio.h>
#include <string.h>
void setEnvironment(char *keyName,char *keyValue) {
	long lRet;
	HKEY hKey;
	DWORD dwSize;
	lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 0, KEY_ALL_ACCESS, &hKey);
	lRet = RegSetValueEx(hKey, keyName, 0, REG_SZ, keyValue, strlen(keyValue));
	RegCloseKey(hKey);
}
void appendEnvironmentToPath(char *target) {
	long lRet;
	HKEY hKey;
	lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 0, KEY_ALL_ACCESS, &hKey);

	char *lpData = (char *)malloc(4096);
	DWORD dataType;

	DWORD   dwSize;
	RegQueryValueEx(hKey,"path",0,NULL,(LPBYTE)lpData,&dwSize);

	int lNewLength = dwSize + strnlen_s(target, 255)+3;
	char *sNewPath = calloc(lNewLength,1);
	strcat_s(sNewPath, lNewLength, "%");
	strcat_s(sNewPath, lNewLength, target);
	strcat_s(sNewPath, lNewLength, "%;");
	strcat_s(sNewPath, lNewLength, lpData);
	setEnvironment("Path", sNewPath);
	free(lpData);
	free(sNewPath);
	RegCloseKey(hKey);
	long res = 0;
	SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, "Environment", SMTO_ABORTIFHUNG, 5000, res);
}
int main()
{
	char *data = "E:\\app\\WindowsAPP\\WeChats";
	setEnvironment("WeiChat_HOME", data);

	appendEnvironmentToPath("WeiChat_HOME");
	
	system("pause");
	return 0;
}