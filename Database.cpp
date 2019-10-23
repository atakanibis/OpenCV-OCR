#include "Database.h"

Database::Database() {
	if(connection == NULL) openConnection();
}
void Database::openConnection() {
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "", "opencv_ocr", 3306, 0, NULL);
	if (connection) Debug::WriteLine("Database baðlantýsý kuruldu");
	else Debug::WriteLine("Database baðlantýsý kurulamadý");
}
void Database::addMarket(System::String^ marketname) {
	String^ query = "INSERT INTO `markets`(`mname`) VALUES (\"" + marketname + "\")";
	char * charquery = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(query).ToPointer();
	int success = mysql_query(connection, charquery);
	if(success == 0) Debug::WriteLine("Market is successfully added.");
	else Debug::WriteLine("Something went wrong while adding new market.");
}
int Database::GetMarketID(System::String^ marketname) {
	String^ query = "SELECT `mid` FROM `markets` WHERE mname = \""+ marketname +"\"";
	char* charquery = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(query).ToPointer();
	int success = mysql_query(connection, charquery);
	if (success == 0) {
		MYSQL_RES* response;
		response = mysql_store_result(connection);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(response)) {
			String^ strNew = gcnew String(row[0]);
			int response;
			Int32::TryParse(strNew, response);
			return response;
		}
	}
	return -1;
}
int Database::getLastInsertedReceiptID() {
	char* query = "SELECT `rid` FROM `receipts` WHERE rid = (SELECT max(rid) FROM `receipts`)";
	int success = mysql_query(connection, query);
	if (success == 0) {
		MYSQL_RES* response;
		response = mysql_store_result(connection);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(response)) {
			String^ strNew = gcnew String(row[0]);
			int response;
			Int32::TryParse(strNew, response);
			return response;
		}
	}
	return -1;
}
void Database::AddReceipt(int marketID, int receiptNo, double total, double kdv, System::String^ bodyOFReceipt, System::String^ date) {
	String^ query = "INSERT INTO `receipts`(`rno`, `rtotal`, `rkdv`, `rproducts`, `rdate`) VALUES (\"" + receiptNo + "\", \"" + total + "\", \"" + kdv + "\", \"" + bodyOFReceipt + "\", \"" + date + "\")";
	char* charquery = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(query).ToPointer();
	int success = mysql_query(connection, charquery);
	if (success == 0) Debug::WriteLine("Receipt is successfully added.");
	else Debug::WriteLine("Something went wrong while adding new receipt.");
	int rid = this->getLastInsertedReceiptID();
	query = "INSERT INTO `market_receipt`(`mid`, `rid`) VALUES (\"" + marketID + "\", \"" + rid + "\")";
	charquery = (char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(query).ToPointer();
	success = mysql_query(connection, charquery);
	if (success == 0) Debug::WriteLine("Market and receipt successfully connected.");
	else Debug::WriteLine("Something went wrong while connecting new market and receipt.");
}

List<Receipt^>^ Database::getAllReceipts() {
	List<Receipt^>^ Receipts = gcnew List<Receipt^>();
	char* query = "SELECT markets.mid, receipts.rid, markets.mname, receipts.rtotal, receipts.rkdv, receipts.rproducts, receipts.rdate, receipts.rno FROM receipts, market_receipt, markets WHERE receipts.rid = market_receipt.rid AND market_receipt.mid = markets.mid";
	int success = mysql_query(connection, query);
	if (success == 0) {
		MYSQL_RES* response;
		response = mysql_store_result(connection);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(response)) {
			Receipt^ currentReceipt = gcnew Receipt();
			String^ handler = gcnew String(row[0]);
			Int32::TryParse(handler, currentReceipt->MarketID);
			handler = gcnew String(row[1]);
			Int32::TryParse(handler, currentReceipt->ReceiptID);
			currentReceipt->MarketName = gcnew String(row[2]);
			handler = gcnew String(row[3]);
			Double::TryParse(handler, currentReceipt->TotalPrice);
			handler = gcnew String(row[4]);
			Double::TryParse(handler, currentReceipt->KDV);
			currentReceipt->Products = gcnew String(row[5]);
			currentReceipt->Date = gcnew String(row[6]);
			handler = gcnew String(row[7]);
			Int32::TryParse(handler, currentReceipt->ReceiptNO);
			Receipts->Add(currentReceipt);
		}
	}
	return Receipts;
}

Database::~Database() {

}