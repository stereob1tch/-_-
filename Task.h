#pragma once
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

ref class Task {
private:
	String^ text;
	String^ date;
	bool completed;
	bool outdated;
public:
	Task() { text = gcnew String("Undefined"), date = gcnew String("01.01.2000"), completed = false, outdated = false; }
	Task(String^& text_, String^& date_) { text = gcnew String(text_), date = gcnew String(date_), completed = false, outdated = false; }

	System::Void set_text(String^ text_) {
		this->text = text_;
	}
	System::Void set_date(String^ date_) {
		this->date = date_;
	}
	System::Void set_completed(bool comp) {
		this->completed = comp;
	}
	System::Void set_outdated(bool outd) {
		this->outdated = outd;
	}

	System::String^ get_text() {
		return this->text;
	}
	System::String^ get_date() {
		return this->date;
	}
	bool get_completed() {
		return this->completed;
	}
	bool get_outdated() {
		return this->outdated;
	}


	bool is_outdated() {
		String^ day = "" + this->date[0] + this->date[1];
		String^ month = "" + this->date[3] + this->date[4];
		String^ year = "" + this->date[6] + this->date[7] + this->date[8] + this->date[9];

		if (Convert::ToInt32(year) > DateTime::Today.Year)
			return true;
		else if (Convert::ToInt32(month) > DateTime::Today.Month)
			return true;
		else if (Convert::ToInt32(day) > DateTime::Today.Day)
			return true;	
		return false;
	}
};