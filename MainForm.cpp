#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Diagnostics;
using System::Drawing::Bitmap;
using namespace cv;

[STAThread]
void main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OpenCVTesseract::MainForm form;

	Application::Run(% form);
}
