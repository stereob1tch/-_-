#pragma once
#include "Task.h"

namespace оопауд {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			String^ fileName = "tasks.txt";
			try
			{
				Console::WriteLine("trying to open file {0}...", fileName);
				StreamReader^ din = File::OpenText(fileName);

				String^ d;
				String^ t;
				String^ outdated;
				String^ completed;


				int count = 0;
				while (!din->EndOfStream)
				{
					t = din->ReadLine();
					Console::WriteLine("line {0}: {1}", count, t);
					d = din->ReadLine();
					Console::WriteLine("line {0}: {1}", count, d);
					outdated = din->ReadLine();
					Console::WriteLine("line {0}: {1}", count, outdated);
					completed = din->ReadLine();
					Console::WriteLine("line {0}: {1}", count, completed);
					
					String^ day = "" + d[0] + d[1];
					String^ month = "" + d[3] + d[4];
					String^ year = "" + d[6] + d[7] + d[8] + d[9];

					this->dataGridView1->Rows->Add(t, d);

					if (Convert::ToInt32(year) > DateTime::Today.Year)
						this->dataGridView1->Rows[count]->DefaultCellStyle->BackColor = Color::Red;
					else if (Convert::ToInt32(month) > DateTime::Today.Month)
						this->dataGridView1->Rows[count]->DefaultCellStyle->BackColor = Color::Red;
					else if (Convert::ToInt32(day) > DateTime::Today.Day)
						this->dataGridView1->Rows[count]->DefaultCellStyle->BackColor = Color::Red;

					if (Convert::ToInt32(completed) == 1)
						this->dataGridView1->Rows[count]->DefaultCellStyle->BackColor = Color::Green;

					count++;
				}
				Console::WriteLine("success.");
				din->Close();
			}
			catch (Exception^ e)
			{
				if (dynamic_cast<FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", fileName);
				else
					Console::WriteLine("problem reading file '{0}'", fileName);
			} 
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox_task;
	private: System::Windows::Forms::TextBox^ textBox_date;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;






	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox_task = (gcnew System::Windows::Forms::TextBox());
			this->textBox_date = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column2,
					this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 67);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(642, 472);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column2
			// 
			this->Column2->Frozen = true;
			this->Column2->HeaderText = L"Задача";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 400;
			// 
			// Column3
			// 
			this->Column3->Frozen = true;
			this->Column3->HeaderText = L"Срок истечения";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Планировщик задач";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(661, 67);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Удалить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(661, 96);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Добавить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox_task
			// 
			this->textBox_task->Location = System::Drawing::Point(742, 96);
			this->textBox_task->Name = L"textBox_task";
			this->textBox_task->Size = System::Drawing::Size(100, 20);
			this->textBox_task->TabIndex = 4;
			// 
			// textBox_date
			// 
			this->textBox_date->Location = System::Drawing::Point(848, 96);
			this->textBox_date->Name = L"textBox_date";
			this->textBox_date->Size = System::Drawing::Size(100, 20);
			this->textBox_date->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(661, 125);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(287, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Отметить как выполненное";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(661, 154);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(287, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Сохранить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 551);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox_date);
			this->Controls->Add(this->textBox_task);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->dataGridView1->Rows->Remove(this->dataGridView1->CurrentRow);
		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			if (String::IsNullOrEmpty(this->textBox_date->Text) || String::IsNullOrEmpty(this->textBox_task->Text))
				MessageBox::Show("Заполните поля", "Ошибка");
			else
				this->dataGridView1->Rows->Add(this->textBox_task->Text, this->textBox_date->Text);
		}

		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			this->dataGridView1->Rows[this->dataGridView1->CurrentRow->Index]->DefaultCellStyle->BackColor = Color::Green;
		}

		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ fileName = "tasks1.txt";
			StreamWriter^ dout = gcnew StreamWriter(fileName);
			for (int i = 0; i < this->dataGridView1->Rows->Count; i++) {
				dout->WriteLine(this->dataGridView1->Rows[i]->Cells[0]->Value);
				dout->WriteLine(this->dataGridView1->Rows[i]->Cells[1]->Value);
				if (this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor == Color::Red)
					dout->WriteLine("1");
			    else
					dout->WriteLine("0");
				if (this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor == Color::Green)
					dout->WriteLine("1");
				else
					dout->WriteLine("0");
				}
		}

			  
private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	String^ fileName = "tasks1.txt";
	StreamWriter^ dout = gcnew StreamWriter(fileName);
	for (int i = 0; i < this->dataGridView1->Rows->Count; i++) {
		dout->WriteLine(this->dataGridView1->Rows[i]->Cells[0]->Value);
		dout->WriteLine(this->dataGridView1->Rows[i]->Cells[1]->Value);
		if (this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor == Color::Red)
			dout->WriteLine("1");
		else
			dout->WriteLine("0");
		if (this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor == Color::Green)
			dout->WriteLine("1");
		else
			dout->WriteLine("0");
	}
	dout->Close();
}
};
}
