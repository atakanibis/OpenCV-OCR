#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

using namespace cv;
using  System::Drawing::Bitmap;
using  System::Drawing::Color;
using  System::Byte;
using  namespace System::Drawing;
using  namespace System::Diagnostics;

namespace Render {
	Bitmap^ Resize(Bitmap^ bmp, int newWidth, int newHeight);
	Bitmap^ SetGrayscale(Bitmap^ img);
	Bitmap^ RemoveNoise(Bitmap^ bmap);
}