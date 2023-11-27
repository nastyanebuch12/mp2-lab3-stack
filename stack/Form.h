#pragma once
#include "TCalculator.h"
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Figure** arr;
		Graphics^ gr;
		int size;
		int dx, dy;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			size = 15;
			arr = new Figure * [size];
			arr[0] = new Rectanglee(40, 100, 210, 110);
			arr[1] = new Ellipse(80, 227, 35, 35);
			arr[2] = new Ellipse(205, 227, 35, 35);
			arr[3] = new Rectanglee(55, 110, 50, 65);
			arr[4] = new Rectanglee(120, 110, 50, 65);
			arr[5] = new Rectanglee(185, 110, 50, 65);
			arr[6] = new Line(250, 155, 300, 155);
			arr[7] = new Rectanglee(300, 100, 210, 110);
			arr[8] = new Ellipse(340, 227, 35, 35);
			arr[9] = new Ellipse(465, 227, 35, 35);
			arr[10] = new Rectanglee(315, 110, 50, 65);
			arr[11] = new Rectanglee(380, 110, 50, 65);
			arr[12] = new Rectanglee(445, 110, 50, 65);
			arr[13] = new Line(510, 135, 610, 210);
			arr[14] = new Line(510, 210, 610, 210);

			gr = CreateGraphics();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1236, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(603, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 47);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Move";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Animation";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(354, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(469, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(360, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"¬ведите dx:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(475, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"¬ведите dy:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(106, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(143, 48);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Show";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(106, 47);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(143, 48);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Hide";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1470, 770);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int dx, dy;
		dx = Convert::ToInt32(textBox1->Text);
		dy = Convert::ToInt32(textBox2->Text);

		for (int i = 0; i < size; i++) {
			arr[i]->Move(gr, dx, dy);
		}

	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < size; i++)
		{
			arr[i]->Show(gr);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < size; i++)
		{
			arr[i]->Hide(gr);
		}
	}
	};
}

