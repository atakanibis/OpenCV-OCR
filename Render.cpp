#include "Render.h"

namespace Render{
	double FindKDV(String^ text) {
		String^ replace = (String^)text->Clone();
		auto lines = replace->Split('\n');
		for each (auto line in lines)
		{
			String^ uppercase = line->ToUpper();
			uppercase = uppercase->Replace(" ", "");
			if (line->Contains("KDV") || line->Contains("KOV")) {
				uppercase = uppercase->Replace(",", ".");
				Regex^ regex = gcnew Regex("[0-9]+\\.[0-9]+");
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
		if (uppercase->Contains("IYI GUNLER") || uppercase->Contains("İYİ GÜNLER") || uppercase->Contains("TESEKKURLER") || uppercase->Contains("TEŞEKKÜRLER")) {
			line = lines[1];
			uppercase = line->ToUpper();			
		}
		return uppercase;
	}
	int FindReceiptNo(String^ text) {
		String^ replace = (String^)text->Clone();
		replace = replace->Replace(" ", "")->Replace("ı", "i")->Replace("ş","s");
		replace = replace->ToUpper();
		Debug::WriteLine(replace->Contains("POPEYES"));
		Debug::WriteLine(replace->Contains("FİSNO"));
		Regex^ regex = gcnew Regex("F\\D*NO\\D*(\\d*)");
		//Debug::WriteLine(replace);
		//Debug::WriteLine(regex->ToString());
		Match^ m = regex->Match(replace);
		int response = -1;
		if (m->Success) {
			Int32::TryParse(m->Groups[1]->Value, response);
		}
		return response;
	}
	String^ FindProducts(String^ text)
	{
		String^ replace = (String^)text->Clone();
		replace = replace->Replace(" ", "")->Replace(",", ".")->ToUpper();
		auto lines = replace->Split('\n');
		String^ productions = "";
		for each (auto line in lines)
		{
			Regex^ regex = gcnew Regex("(\\d+)(\\D)([0-9]+\\.[0-9]+)$");
			Match^ m = regex->Match(line);
			if (m->Success) {
				if (productions != "") productions += ", ";
				productions += line;
			}
		}
		return productions;
	}
	double FindPrice(String^ text) {
		String^ replace = (String^)text->Clone();
		auto lines = replace->Split('\n');
		bool startsearch = false;
		for each (auto line in lines)
		{
			String^ uppercase = line->ToUpper();
			uppercase = uppercase->Replace(" ", "");
			if (uppercase->Contains("KDV") || uppercase->Contains("KOV")) {
				startsearch = true;
			}
			else if (startsearch) {
				if (uppercase->Contains("TOPLAM") || uppercase->Contains("TOP")) {
					uppercase = uppercase->Replace(",", ".");
					Regex^ regex = gcnew Regex("[0-9]+\\.[0-9]+");
					Match^ m = regex->Match(uppercase);
					double response;
					if (m->Success) {
						Debug::WriteLine(m->Value);
						response = Convert::ToDouble(m->Value, CultureInfo::InvariantCulture);
						return response;
					}
				}
			}
		}
		return -1;
	}
	String^ FindDate(String^ text) {
		String^ replace = (String^)text->Clone();
		replace = replace->Replace(" ", "");
		String^ response = "00-00-0000";
		Regex^ regex = gcnew Regex("([0-2][0-9]|(3)[0-1])((.|\\/|\\-))(((0)[0-9])|((1)[0-2]))((.|\\/|\\-))\\d{4}");
		Match^ m = regex->Match(replace);
		if (m->Success) {
			response = m->Value;
		}
		response = response->Replace("/", "-")->Replace(".", "-");
		return response;
	}
}
