#include "MainForm.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Diagnostics;

[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OpenCVTesseract::MainForm form;
	tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
	if (api->Init("./tessdata", "tur", tesseract::OEM_DEFAULT)) {
		MessageBox::Show("Could not initialize tesseract.");
		exit(1);
	}
	// Load image
	cv::Mat im = cv::imread("market-fis.jpg");
	cv::Mat; gray;
	cv::cvtColor(im, gray, cv::COLOR_BGR2GRAY);
	// ...other image pre-processing here...

	// Pass it to Tesseract API
	api->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);
	api->SetImage((uchar*)gray.data, gray.cols, gray.rows, 1, gray.cols);

	// Get the text
	char* out = api->GetUTF8Text();
	String^ clistr = gcnew String(out, 0, 999, System::Text::Encoding::UTF8);
	MessageBox::Show(clistr);
	Application::Run(% form);
}