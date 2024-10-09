#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;




[STAThreadAttribute]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    fractal::MyForm form;
    Application::Run(% form);

}
