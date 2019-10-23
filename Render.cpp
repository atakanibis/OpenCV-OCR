#include "Render.h"

namespace Render{
	double FindKDV(String^ text) {
		auto lines = text->Split('\n');
		for each (auto line in lines)
		{
			String^ uppercase = line->ToUpper();
			uppercase = uppercase->Replace(" ", "");
			if (line->Contains("TOPKDV") || line->Contains("TOPKOV") || line->Contains("TOPLAMKDV") || line->Contains("TOPLAMKOV")) {
				uppercase = uppercase->Replace(",", ".");
				Debug::WriteLine("bura");
				Debug::WriteLine(uppercase);
				Regex^ regex = gcnew Regex("[0-9]+\.?[0-9]*");
				Match^ m = regex->Match(uppercase);
				double response;
				if (m->Success) {
					response = Convert::ToDouble(m->Value, CultureInfo::InvariantCulture);
					return response;
				}
			}
		}
		return -1;
	}
	String^ FindName(String^ text) {
		auto lines = text->Split('\n');
		auto line = lines[0];
		auto uppercase = line->ToUpper();
		if (uppercase->Contains("IYI GUNLER") || uppercase->Contains("ÝYÝ GÜNLER") || uppercase->Contains("TESEKKURLER") || uppercase->Contains("TEÞEKKÜRLER")) {
			line = lines[1];
			uppercase = line->ToUpper();			
		}
		return uppercase;
	}
	double FindPrice(String^ text) {
		auto lines = text->Split('\n');
		bool startsearch = false;
		for each (auto line in lines)
		{
			if (line->Contains("TOPKDV") || line->Contains("TOPKOV") || line->Contains("TOPLAMKDV") || line->Contains("TOPLAMKOV")) {
				startsearch = true;
			}
			else if (startsearch) {
				String^ uppercase = line->ToUpper();
				uppercase = uppercase->Replace(" ", "");
				if (line->Contains("TOPLAM") || line->Contains("TOP")) {
					uppercase = uppercase->Replace(",", ".");
					Regex^ regex = gcnew Regex("[0-9]+\.?[0-9]*");
					Match^ m = regex->Match(uppercase);
					double response;
					if (m->Success) {
						response = Convert::ToDouble(m->Value, CultureInfo::InvariantCulture);
						return response;
					}
				}
			}
		}
		return -1;
	}
	String^ FindDate(String^ text) {
		String^ response = "00-00-0000";
		Regex^ regex = gcnew Regex("([0-2][0-9]|(3)[0-1])((.|\\/|\\-))(((0)[0-9])|((1)[0-2]))((.|\\/|\\-))\\d{4}");
		Match^ m = regex->Match(text);
		if (m->Success) {
			response = m->Value;
		}
		response = response->Replace("/", "-")->Replace(".", "-");
		return response;
	}
}
