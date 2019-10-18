#include "Render.h"
namespace Render{

	Bitmap^ Resize(Bitmap^ bmp, int newWidth, int newHeight)
	{

		Bitmap^ temp = (Bitmap^)bmp->Clone();

		Bitmap^ bmap = gcnew Bitmap(newWidth, newHeight, temp->PixelFormat);

		double nWidthFactor = (double)temp->Width / (double)newWidth;
		double nHeightFactor = (double)temp->Height / (double)newHeight;

		double fx, fy, nx, ny;
		int cx, cy, fr_x, fr_y;
		Color color1;
		Color color2;
		Color color3;
		Color color4;
		Byte nRed, nGreen, nBlue;

		Byte bp1, bp2;

		for (int x = 0; x < bmap->Width; ++x)
		{
			for (int y = 0; y < bmap->Height; ++y)
			{

				fr_x = (int)System::Math::Floor(x * nWidthFactor);
				fr_y = (int)System::Math::Floor(y * nHeightFactor);
				cx = fr_x + 1;
				if (cx >= temp->Width) cx = fr_x;
				cy = fr_y + 1;
				if (cy >= temp->Height) cy = fr_y;
				fx = x * nWidthFactor - fr_x;
				fy = y * nHeightFactor - fr_y;
				nx = 1.0 - fx;
				ny = 1.0 - fy;

				color1 = temp->GetPixel(fr_x, fr_y);
				color2 = temp->GetPixel(cx, fr_y);
				color3 = temp->GetPixel(fr_x, cy);
				color4 = temp->GetPixel(cx, cy);

				// Blue
				bp1 = (Byte)(nx * color1.B + fx * color2.B);

				bp2 = (Byte)(nx * color3.B + fx * color4.B);

				nBlue = (Byte)(ny * (double)(bp1)+fy * (double)(bp2));

				// Green
				bp1 = (Byte)(nx * color1.G + fx * color2.G);

				bp2 = (Byte)(nx * color3.G + fx * color4.G);

				nGreen = (Byte)(ny * (double)(bp1)+fy * (double)(bp2));

				// Red
				bp1 = (Byte)(nx * color1.R + fx * color2.R);

				bp2 = (Byte)(nx * color3.R + fx * color4.R);

				nRed = (Byte)(ny * (double)(bp1)+fy * (double)(bp2));

				bmap->SetPixel(x, y, System::Drawing::Color::FromArgb
				(255, nRed, nGreen, nBlue));
			}
		}



		bmap = SetGrayscale(bmap);
		bmap = RemoveNoise(bmap);

		return bmap;

	}


	//SetGrayscale
	Bitmap^ SetGrayscale(Bitmap^ img)
	{

		Bitmap^ temp = (Bitmap^)img;
		Bitmap^ bmap = (Bitmap^)temp->Clone();
		Color c;
		for (int i = 0; i < bmap->Width; i++)
		{
			for (int j = 0; j < bmap->Height; j++)
			{
				c = bmap->GetPixel(i, j);
				Byte gray = (Byte)(.299 * c.R + .587 * c.G + .114 * c.B);

				bmap->SetPixel(i, j, Color::FromArgb(gray, gray, gray));
			}
		}
		return (Bitmap^)bmap->Clone();

	}
	//RemoveNoise
	Bitmap^ RemoveNoise(Bitmap^ bmap)
	{

		for (auto x = 0; x < bmap->Width; x++)
		{
			for (auto y = 0; y < bmap->Height; y++)
			{
				auto pixel = bmap->GetPixel(x, y);
				if (pixel.R < 162 && pixel.G < 162 && pixel.B < 162)
					bmap->SetPixel(x, y, Color::Black);
				else if (pixel.R > 162 && pixel.G > 162 && pixel.B > 162)
					bmap->SetPixel(x, y, Color::White);
			}
		}
		return bmap;
	}

}
