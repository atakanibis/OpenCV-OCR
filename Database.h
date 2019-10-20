#pragma once
#include <mysql/mysql.h>
#include <string>
#include <vector>
#include "Receipt.h"

using namespace System::Diagnostics;
using namespace System;
using System::Collections::Generic::List;

ref class Database {
private:
	static MYSQL* connection;
	void openConnection();
public:
	Database();
	~Database();
	void addMarket(System::String^ marketname);
	int GetMarketID(System::String^ marketname);
	int getLastInsertedReceiptID();
	void AddReceipt(int marketID, double total, double kdv, System::String^ bodyOFReceipt, System::String^ date);
	List<Receipt^>^ getAllReceipts();
};