#pragma once
#include <string>
//#include "SocketWindows.h"
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net::Sockets;
	using namespace System::Net;
	using namespace System::Diagnostics;
	using namespace System::Threading;
	using namespace System::Text;
	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		static String^ s;
		
	private: System::Windows::Forms::Button^ connect_bt;
	public:
			
	public:
		SocketType serverType = SocketType::Stream;
		ProtocolType severProtocol = ProtocolType::Tcp;
		AddressFamily serverFamily = AddressFamily::InterNetwork;
	private: System::Windows::Forms::Timer^ timer1;
	public:
		Socket^ serverSocket = gcnew Socket(serverFamily, serverType, severProtocol);
		//System::Threading::Thread RecvTask(RecvFunc);

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//

		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ RecvTXT;
	private: System::Windows::Forms::TextBox^ IPServerTXT;

	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ SendTXT;

	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->RecvTXT = (gcnew System::Windows::Forms::TextBox());
			this->IPServerTXT = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SendTXT = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->connect_bt = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// RecvTXT
			// 
			this->RecvTXT->Location = System::Drawing::Point(15, 49);
			this->RecvTXT->Multiline = true;
			this->RecvTXT->Name = L"RecvTXT";
			this->RecvTXT->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->RecvTXT->Size = System::Drawing::Size(259, 174);
			this->RecvTXT->TabIndex = 0;
			// 
			// IPServerTXT
			// 
			this->IPServerTXT->Location = System::Drawing::Point(68, 12);
			this->IPServerTXT->Name = L"IPServerTXT";
			this->IPServerTXT->Size = System::Drawing::Size(135, 20);
			this->IPServerTXT->TabIndex = 1;
			this->IPServerTXT->Text = L"192.168.1.216";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Send to: ";
			// 
			// SendTXT
			// 
			this->SendTXT->Location = System::Drawing::Point(15, 229);
			this->SendTXT->Name = L"SendTXT";
			this->SendTXT->Size = System::Drawing::Size(188, 20);
			this->SendTXT->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(210, 229);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"&Send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// connect_bt
			// 
			this->connect_bt->Location = System::Drawing::Point(210, 10);
			this->connect_bt->Name = L"connect_bt";
			this->connect_bt->Size = System::Drawing::Size(61, 23);
			this->connect_bt->TabIndex = 5;
			this->connect_bt->Text = L"Connect";
			this->connect_bt->UseVisualStyleBackColor = true;
			this->connect_bt->Click += gcnew System::EventHandler(this, &Form1::connect_bt_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->connect_bt);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->SendTXT);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->IPServerTXT);
			this->Controls->Add(this->RecvTXT);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		SocketType serverType = SocketType::Stream;
		ProtocolType severProtocol = ProtocolType::Tcp;
		AddressFamily serverFamily = AddressFamily::InterNetwork;
		Socket^ sendSocket = gcnew Socket(serverFamily, serverType, severProtocol);

		/*sendSocket->Connect(this->IPServerTXT->Text, 1234);*/
		System::Net::EndPoint^ RecvEP = gcnew System::Net::IPEndPoint(System::Net::IPAddress::Parse(IPServerTXT->Text), 1234);
		sendSocket->Connect(RecvEP);
		
		try
		{
			array<unsigned char>^ msgToSend = gcnew array<unsigned char>(1024);
			System::Text::ASCIIEncoding ^ascii = gcnew System::Text::ASCIIEncoding();
			ascii->GetBytes(SendTXT->Text, 0, SendTXT->Text->Length, msgToSend, 0);
			System::Net::Sockets::SocketFlags flag = System::Net::Sockets::SocketFlags::None;
			sendSocket->Send(msgToSend,SendTXT->Text->Length, flag);
			s = "send: " + SendTXT->Text + "\r\n";
			
		} 
		catch(...)
		{
			Debug::WriteLine("Send fales");
			}
		sendSocket->Disconnect(false);
		sendSocket->Close();

	}
private: static void connectFunc()
{
	SocketType serverType = SocketType::Stream;
	ProtocolType severProtocol = ProtocolType::Tcp;
	AddressFamily serverFamily = AddressFamily::InterNetwork;
	Socket^ sendSocket = gcnew Socket(serverFamily, serverType, severProtocol);

	System::Net::EndPoint^ RecvEP = gcnew System::Net::IPEndPoint(System::Net::IPAddress::Parse("192.168.1.216"), 2222);
	sendSocket->Bind(RecvEP);
	sendSocket->Listen(10);
	while (true)
	{
		Socket^ clientSock = sendSocket->Accept();
		Debug::WriteLine("have request connection");
		Debug::WriteLine("client: " + clientSock->RemoteEndPoint->ToString());
		array<unsigned char>^ buff = gcnew array<unsigned char>(1024);
		while (true)
		{
			int byteSend = clientSock->Receive(buff);
			if (byteSend > 0)
			{
				Debug::WriteLine(Encoding::UTF8->GetString(buff));
				s = "Recv: " + Encoding::UTF8->GetString(buff) + "\r\n";
				clientSock->Close();
				break;
			}
		}
	}
	
}

private: System::Void connect_bt_Click(System::Object^ sender, System::EventArgs^ e) {
	ThreadStart^ RecvFunc = gcnew ThreadStart(connectFunc);
	Thread^ th1 = gcnew Thread(RecvFunc);
	th1->Start();
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	RecvTXT->Text += s;
	s = "";
}
};

}
