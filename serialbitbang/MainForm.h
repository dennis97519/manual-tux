#pragma once
#include <windows.h>
#include <msclr\marshal.h>
#include<stdio.h>
#include<bitset>
using namespace msclr::interop;
namespace serialbitbang {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			recvWker.DoWork += gcnew DoWorkEventHandler(this, &MainForm::readSerial);
			recvWker.WorkerReportsProgress=true;
			recvWker.ProgressChanged += gcnew ProgressChangedEventHandler(this, &MainForm::readSerialUpdate);
			//
			//TODO: Add the constructor code here
			//
			serialSend->AppendText("Please enter the serial port number, \r\nprepending \\\\.\\ if the COM number is higher than 9.\r\n");
			comLock=0;
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TextBox^  serialSend;
	private: System::Windows::Forms::TextBox^  serialCmd;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  serialRecv;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: 
			 HANDLE hComm;
			 LPOVERLAPPED ovlStruct;
			 marshal_context mc;
			 BackgroundWorker recvWker;
			 BackgroundWorker sendWker;
			 bool comLock;
			 String^ serialmsg;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->serialSend = (gcnew System::Windows::Forms::TextBox());
			this->serialCmd = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->serialRecv = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->groupBox2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->groupBox1);
			this->splitContainer1->Size = System::Drawing::Size(1056, 912);
			this->splitContainer1->SplitterDistance = 352;
			this->splitContainer1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->Controls->Add(this->tableLayoutPanel1);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(0, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(352, 912);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sent bytes";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->serialSend, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->serialCmd, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 18);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(346, 891);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// serialSend
			// 
			this->serialSend->AcceptsReturn = true;
			this->serialSend->BackColor = System::Drawing::SystemColors::Window;
			this->serialSend->Dock = System::Windows::Forms::DockStyle::Fill;
			this->serialSend->Font = (gcnew System::Drawing::Font(L"Courier New", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->serialSend->Location = System::Drawing::Point(3, 3);
			this->serialSend->MaxLength = 2147483647;
			this->serialSend->Multiline = true;
			this->serialSend->Name = L"serialSend";
			this->serialSend->ReadOnly = true;
			this->serialSend->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->serialSend->Size = System::Drawing::Size(340, 845);
			this->serialSend->TabIndex = 1;
			// 
			// serialCmd
			// 
			this->serialCmd->AllowDrop = true;
			this->serialCmd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->serialCmd->Font = (gcnew System::Drawing::Font(L"Courier New", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->serialCmd->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->serialCmd->Location = System::Drawing::Point(3, 860);
			this->serialCmd->Name = L"serialCmd";
			this->serialCmd->Size = System::Drawing::Size(340, 28);
			this->serialCmd->TabIndex = 2;
			this->serialCmd->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::serialCmd_KeyUp);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->serialRecv);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(700, 912);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Received bytes";
			// 
			// serialRecv
			// 
			this->serialRecv->AcceptsReturn = true;
			this->serialRecv->BackColor = System::Drawing::SystemColors::Window;
			this->serialRecv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->serialRecv->Font = (gcnew System::Drawing::Font(L"Courier New", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->serialRecv->Location = System::Drawing::Point(3, 18);
			this->serialRecv->MaxLength = 2147483647;
			this->serialRecv->Multiline = true;
			this->serialRecv->Name = L"serialRecv";
			this->serialRecv->ReadOnly = true;
			this->serialRecv->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->serialRecv->Size = System::Drawing::Size(694, 891);
			this->serialRecv->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1056, 912);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: 
	Void readSerialUpdate(Object^,ProgressChangedEventArgs^ e){
		unsigned char c=e->ProgressPercentage;
		char hex[10];
		sprintf_s(hex,"0x%02x, %3u",c,c);
		String^ hexstr=gcnew String(hex);
		String^ binstr=gcnew String(std::bitset<sizeof(c) * 8>(c).to_string().c_str());
		String^ schar = (gcnew Char(c))->ToString();
		c=((0x30&c)>>1)|(7&c);
		sprintf_s(hex,"%02x",c);
		String^ r=gcnew String(hex);
		serialRecv->AppendText(binstr+", R=0x"+r+", "+hexstr+", '"+ schar+"'\r\n");
	}

	Void readSerial(System::Object^  sender, DoWorkEventArgs^  e ){
		//SetCommMask(hComm, EV_RXCHAR);
		 BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
		DWORD dwEventMask; 
		char TempChar;
		Char^ syschar;
		DWORD NoBytesRead;
		bool updated=false;
		while(1){
			if(!comLock){
				comLock=true;
				serialmsg="";
				updated=false;
				do{
				ReadFile( hComm,           //Handle of the Serial port
				 &TempChar,       //Temporary character
				 sizeof(TempChar),//Size of TempChar
				 &NoBytesRead,    //Number of bytes read
				 0);
				syschar=gcnew Char(TempChar);
				if(NoBytesRead){
					worker->ReportProgress(TempChar);
					serialmsg+=syschar->ToString();
					updated=true;
				}
				}while (NoBytesRead>0);
				
				comLock=false;
			}
			else{
				Sleep(1);
			}
		}
	}
	System::Void serialCmd_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode == Keys::Enter){
				
				hComm = CreateFile(mc.marshal_as<LPCSTR>(serialCmd->Text),                //port name
								GENERIC_READ | GENERIC_WRITE, //Read/Write
								0,                            // No Sharing
								NULL,                         // No Security
								OPEN_EXISTING,// Open existing port only
								0,            // Non Overlapped I/O
								NULL);        // Null for Comm Devices
				serialSend->AppendText(serialCmd->Text+"\r\n");
				serialCmd->Clear();
				if (hComm == INVALID_HANDLE_VALUE){
					serialSend->AppendText("Unable to open specified port. Try again.\r\n Please enter the serial port number, \r\nprepending \\\\.\\ if the COM number is higher than 9.\r\n");
				}
				else{
					DCB dcbSerialParams = { 0 }; // Initializing DCB structure
					dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
					GetCommState(hComm, &dcbSerialParams);
					dcbSerialParams.BaudRate = CBR_9600;  // Setting BaudRate = 9600
					dcbSerialParams.ByteSize = 8;         // Setting ByteSize = 8
					dcbSerialParams.StopBits = ONESTOPBIT;// Setting StopBits = 1
					dcbSerialParams.Parity   = NOPARITY;  // Setting Parity = None
					SetCommState(hComm, &dcbSerialParams);
					COMMTIMEOUTS timeouts = {0};
					GetCommTimeouts(hComm,&timeouts);
					timeouts.ReadIntervalTimeout=1;
					timeouts.ReadTotalTimeoutConstant=1;
					timeouts.ReadTotalTimeoutMultiplier=1;
					SetCommTimeouts(hComm,&timeouts);
					serialCmd->KeyUp -= gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::serialCmd_KeyUp);
					serialCmd->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::serialCmd_sendCmd);
					recvWker.RunWorkerAsync();
					serialSend->AppendText("port opened successfully\r\n");
				}
			}
		 }
		 System::Void serialCmd_sendCmd(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if(e->KeyCode == Keys::Enter){
				//sendWker.RunWorkerAsync();
				while(1){
					if(!comLock){
						comLock=true;
						array<Char>^ comma={','};
						array<String^>^ bytes=serialCmd->Text->Split(comma);
						int len=bytes->Length;
						char* data=(char*)malloc(sizeof(char)*len);
						//LPCSTR data=mc.marshal_as<LPCSTR>(serialCmd->Text);
						for(int i=0;i<len;i++){
							String^ s=bytes[i];
							if(s[0]=='x'){
								if(s->Length!=3){
									serialSend->AppendText("Invalid byte "+s+"\r\n");
									comLock=false;
									return;
								}
								sscanf_s(mc.marshal_as<const char*>(s),"x%x",&data[i]);
							}
							else if(s[0]=='b'){
								if(s->Length!=9){
									serialSend->AppendText("Invalid byte "+s+"\r\n");
									comLock=false;
									return;
								}
								data[i]=0;
								for(int ii=0;ii<8;ii++){
									data[i] |= ( (s[ii+1]=='0') ? 0 : (1<<(7-ii)) );
								}
							}
							else{
								serialSend->AppendText("Invalid format\r\n");
								comLock=false;
								return;
							}
						}
						DWORD length;
						printf(data);

						WriteFile(hComm,   // handle to file to write to
							data,              // pointer to data to write to file
							len,              // number of bytes to write
							&length,0);    // pointer to number of bytes written
						serialSend->AppendText(serialCmd->Text+"\r\n");
						serialCmd->Clear();
						//free((void*)data);
						comLock=false;
						return;
					}
				}
			}
		 }
};
}
