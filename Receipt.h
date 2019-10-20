#pragma once
ref struct Receipt {
	int MarketID;
	System::String^ MarketName;
	int ReceiptID;
	double TotalPrice;
	double KDV;
	System::String^ Products;
	System::String^ Date;
};