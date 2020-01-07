#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "pch.h"
#include "Winsock2.h"
#include "Ws2tcpip.h"
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include "Form1.h"
using namespace System;
using namespace System::Windows::Forms;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}




[STAThread]
int main() {
	//System::Threading::ThreadStart^ RecvFunc = gcnew System::Threading::ThreadStart(Work::DoWork);

	//System::Threading::Thread RecvTask(RecvFunc);
	//RecvTask.Start();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 
	return 0;
}
