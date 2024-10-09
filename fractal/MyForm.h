#pragma once
#include <math.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#include "MyForm1.h"

namespace fractal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class SierpinskiSquare {
	public:

		double x_, y_;
		int angle_, length_;
		float width;
		int order_;
		void Draw(Graphics^ g, int x, int y, int length, int order, float width) {
			length_ = length;
			x_ = x;
			y_ = y;
			angle_ = 0;
			order_ = order;
			this->width = width;
			String^ s = "F+XF+F+XF";
			for (int i = 0; i < order; ++i) {
				s = Rewrite(s);
			}
			Execute(g, s);
		}

		Color getColor() {
			if (order_ == 1)
				return Color::Red; 
			if (order_ == 2)
				return Color::Blue;
			if (order_ == 3)
				return Color::DeepPink;
			if (order_ == 4)
				return Color::Green;
			if (order_ == 5)
				return Color::Gray;
			if (order_ == 6)
				return Color::Purple;
			if (order_ == 7)
				return Color::Orange;


		}

		String^ Rewrite(String^ s) {
			String^ t = "";
			for each (char c in s) {
				if (c == 'X')
					t += "XF-F+F-XF+F+XF-F+F-X";
				else
					t += gcnew String(c, 1);
			}
			return t;
		}

		void Line(Graphics^ g) {
			double theta = (3.14159265359 * angle_) / 180.0;
			double new_x = x_ + length_ * cos(theta);
			double new_y = y_ + length_ * sin(theta);
			Pen^ pen = gcnew Pen(getColor(), width); // Здесь 5.0f - это толщина линии
			g->DrawLine(pen, (float)x_, (float)y_, (float)new_x, (float)new_y);
			x_ = new_x;
			y_ = new_y;
		}

		void Execute(Graphics^ g, String^ s) {
			for each (char c in s) {
				switch (c) {
				case 'F':
					Line(g);
					break;
				case '+':
					angle_ = (angle_ + 90) % 360;
					break;
				case '-':
					angle_ = (angle_ - 90) % 360;
					break;
				}
			}
		}
	};
	

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
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

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	protected:

	private:
		
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(803, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Пример фрактала";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(788, 68);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(319, 104);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(26, 19);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(729, 504);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(788, 453);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 57);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Фрактал";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(963, 453);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 57);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Дерево";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(784, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(324, 42);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введите уровень прорисовки фрактала\r\nУровень по умолчанию: 4\r\n";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(788, 262);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(103, 29);
			this->textBox1->TabIndex = 7;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(783, 319);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(144, 21);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Размер фрактала\r\n";
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"1", L"2", L"3", L"4", L"5", L"6", L"7" });
			this->comboBox1->Location = System::Drawing::Point(787, 354);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(145, 29);
			this->comboBox1->TabIndex = 9;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(788, 414);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 33);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Очистить";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->BackColor = System::Drawing::Color::White;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Location = System::Drawing::Point(775, 19);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(343, 164);
			this->pictureBox3->TabIndex = 11;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox4->BackColor = System::Drawing::Color::White;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox4->Location = System::Drawing::Point(775, 189);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(343, 203);
			this->pictureBox4->TabIndex = 12;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox5->BackColor = System::Drawing::Color::White;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox5->Location = System::Drawing::Point(775, 398);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(343, 125);
			this->pictureBox5->TabIndex = 13;
			this->pictureBox5->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::OldLace;
			this->ClientSize = System::Drawing::Size(1155, 563);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int order = 4;
		int length;
		int scale = 20;
		int x = 2;
		int y = 15;
		MyForm1^ newForm = gcnew MyForm1(order);
		 
		Graphics^ graphics;
		SierpinskiSquare sierpinski;
	
		bool draw = false;


	void MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			// Проверка, какая клавиша была нажата
			if (e->KeyCode == System::Windows::Forms::Keys::Up) {
				// Перемещение pictureBox1 вверх
				int size = Math::Min(pictureBox2->Width, pictureBox2->Height);
				y -= size/15;
				if (draw) {
					
					float width = size / 1000;
				order = Single::Parse(textBox1->Text);
				graphics->Clear(pictureBox2->BackColor);
				sierpinski.Draw(graphics, x, y, length, order, width);
				}
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::Down) {
				// Перемещение pictureBox1 вниз
				int size = Math::Min(pictureBox2->Width, pictureBox2->Height);
				y += size / 15;
				if (draw) {
					
					float width = size / 1000;
					order = Single::Parse(textBox1->Text);
					graphics->Clear(pictureBox2->BackColor);
					sierpinski.Draw(graphics, x, y, length, order, width);
				}
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::Left) {
				// Перемещение pictureBox1 влево
				int size = Math::Min(pictureBox2->Width, pictureBox2->Height);
				x -= size / 15;
				if (draw) {
					
					float width = size / 1000;
					order = Single::Parse(textBox1->Text);
					graphics->Clear(pictureBox2->BackColor);
					sierpinski.Draw(graphics, x, y, length, order, width);
				}
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::Right) {
				// Перемещение pictureBox1 вправо
				int size = Math::Min(pictureBox2->Width, pictureBox2->Height);
				x += size / 15;
				if (draw) {
					
					float width = size / 1000;
					order = Single::Parse(textBox1->Text);
					graphics->Clear(pictureBox2->BackColor);
					sierpinski.Draw(graphics, x, y, length, order, width);
				}
			}
		}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "4";
		comboBox1->Text = "  Выберите...";
		this->pictureBox3->SendToBack();
		this->pictureBox4->SendToBack();
		this->pictureBox5->SendToBack();
		
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	    graphics = pictureBox2->CreateGraphics();
		graphics->Clear(pictureBox2->BackColor);

		order = Single::Parse(textBox1->Text);
		draw = true;
		int size = Math::Min(pictureBox2->Width, pictureBox2->Height);
		 length = size / (scale* order);
		System::Diagnostics::Debug::WriteLine("Width: " + pictureBox2->Width);
		 x = pictureBox2->Width/ 2;
		 y = pictureBox2->Height / 15;
		 float width = size / 1000;
		sierpinski.Draw(graphics, x, y, length, order, width);
		newForm->new_oreder(order);
	}
	

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	switch (comboBox1->SelectedIndex)
	{
	case 6: scale = 5; break;
	case 5: scale = 10; break;
	case 4: scale = 15; break;
	case 3: scale = 20; break;
	case 2: scale = 30; break;
	case 1: scale = 40; break;
	case 0: scale = 50; break;
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	graphics->Clear(pictureBox2->BackColor);
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	newForm->new_oreder(order);
	newForm->Show();
}
};

}
