#pragma once

using namespace System::Diagnostics;
using namespace System::Globalization;
using namespace System;
using namespace System::Text::RegularExpressions;

namespace Render {
	String^ FindName(String^ text);
	double FindKDV(String^ text);
	double FindPrice(String^ text);
	String^ FindDate(String^ text);
}