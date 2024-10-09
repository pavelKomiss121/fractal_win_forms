#pragma once
#include <vector>
#include <iostream>

namespace fractal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// —водка дл€ MyForm1
	/// </summary>
	

	ref struct TreeNode {
		double x;
		double y;
		List<TreeNode^>^ children;

		TreeNode(double x, double y) {
			this->x = x;
			this->y = y;
			this->children = gcnew List<TreeNode^>();
		}
	};

	int order_;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(int order)
		{
			order_ = order;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void new_oreder(int order) {
			order_ = order;
		}

	protected:
		
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
		TreeNode^ root;
		int treeHeight=7;
		array<Color>^ levelColors;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

#pragma endregion

		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(1040, 448);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 33);
			this->button3->TabIndex = 13;
			this->button3->Text = L"ќчистить";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1006, 487);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 57);
			this->button1->TabIndex = 11;
			this->button1->Text = L"ќтрисовать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(12, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(925, 532);
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::OldLace;
			this->ClientSize = System::Drawing::Size(1162, 574);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}

		TreeNode^ BuildTree(int height, double x, double y, double width, double levelHeight, int level) {
			if (height == 0)
				return nullptr;

			TreeNode^ node = gcnew TreeNode(x, y);
			double childOffsetY = levelHeight;
			double childOffsetX = width / 5;

			for (int i = 0; i < 5; ++i) {
				node->children->Add(BuildTree(height - 1, x - width / 2 + childOffsetX * i, y + childOffsetY, childOffsetX, levelHeight, level + 1));
			}

			return node;
		}
		void DrawTree(Graphics^ g, TreeNode^ node, int level) {
			if (node == nullptr)
				return;

			Color nodeColor = this->levelColors[level % this->treeHeight];
			Brush^ brush = gcnew SolidBrush(nodeColor);
			float nodeRadius = 10;

			// ќтрисовка дочерних узлов
			for each (TreeNode ^ child in node->children) {
				if (child != nullptr) {
					g->DrawLine(Pens::Black, (float)node->x, (float)node->y, (float)child->x, (float)child->y);
					DrawTree(g, child, level + 1);
				}
			}

			// ќтрисовка текущего узла
			g->FillEllipse(brush, (float)node->x - nodeRadius / 2, (float)node->y - nodeRadius / 2, nodeRadius, nodeRadius);
		}
		void InitializeLevelColors() {
			this->levelColors = gcnew array<Color>(Math::Max(7, this->treeHeight));
			this->levelColors[0] = Color::Red;
			this->levelColors[1] = Color::Blue;
			this->levelColors[2] = Color::DeepPink;
			this->levelColors[3] = Color::Green;
			this->levelColors[4] = Color::Gray;
			this->levelColors[5] = Color::Purple;
			this->levelColors[6] = Color::Orange;


			// Additional colors in case treeHeight > 5
			array<Color>^ additionalColors = gcnew array<Color> { Color::Yellow, Color::Cyan, Color::Magenta, Color::Brown, Color::Pink };
			for (int i = 7; i < this->treeHeight; ++i) {
				this->levelColors[i] = additionalColors[i % additionalColors->Length];
			}
		}


		Graphics^ graphics;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		InitializeLevelColors();
		this->root = BuildTree(order_, this->pictureBox2->Width / 1.62, 20, this->pictureBox2->Width-15, this->pictureBox2->Height / order_, 0);
		
		graphics = pictureBox2->CreateGraphics();
		graphics->Clear(Color::White);
		DrawTree(graphics, this->root, 0);
	
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		graphics->Clear(Color::White);
	}
};
}
