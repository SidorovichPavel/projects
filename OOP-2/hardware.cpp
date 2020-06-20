#include "hardware.h"

unsigned to_unsint(std::string str)
{
	unsigned res = 0;
	std::for_each(str.begin(), str.end(), [&res](const char var)
		{
			res *= 10;
			res += static_cast<unsigned>(var - '0');
		});
	return res;
}


ID::ID():
	id(0),
	develpoer_name(""),
	designation(""),
	type("ID")
{}

ID::~ID()
{}

RAM::RAM():
	capacity(0),
	frequency(0)
{
	this->type = "RAM";
}

RAM::RAM(unsigned _id, std::string dev_name, std::string design, unsigned cap, unsigned freq)
{
	this->id = _id;
	this->develpoer_name = dev_name;
	this->designation = design;
	this->type = "RAM";
	this->capacity = cap;
	this->frequency = freq;
}

std::string RAM::get_developers_name()
{
	return this->develpoer_name;
}

std::string RAM::get_designation()
{
	return this->designation;
}

std::string RAM::get_type()
{
	return this->type;
}

unsigned RAM::get_capacity()
{
	return this->capacity;
}

unsigned RAM::get_frequency()
{
	return this->frequency;
}

unsigned RAM::get_id()
{
	return this->id;
}

void RAM::create_set(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	helperW.push_back(CreateWindow(L"static", L"ID: ", WS_CHILD | WS_VISIBLE, 900, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"developers\n\rname: ", WS_CHILD | WS_VISIBLE | BS_MULTILINE, 900, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Designation: ", WS_CHILD | WS_VISIBLE, 900, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Capacity: ", WS_CHILD | WS_VISIBLE, 900, 360, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Frequency: ", WS_CHILD | WS_VISIBLE, 900, 410, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 360, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 410, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"button", L"OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 900, 600, 120, 40, hWnd, (HMENU)IDM_RAM_OK, hInst, 0));
	helperW.push_back(CreateWindow(L"button", L"Cancel", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1030, 600, 120, 40, hWnd, (HMENU)IDM_CANCEL, hInst, 0));
}

void RAM::edit_set(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	helperW.push_back(CreateWindow(L"static", L"ID: ", WS_CHILD | WS_VISIBLE, 900, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"developers\n\rname: ", WS_CHILD | WS_VISIBLE | BS_MULTILINE, 900, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Designation: ", WS_CHILD | WS_VISIBLE, 900, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Capacity: ", WS_CHILD | WS_VISIBLE, 900, 360, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Frequency: ", WS_CHILD | WS_VISIBLE, 900, 410, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 210, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), std::to_string(this->id).c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 260, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), this->develpoer_name.c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 310, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), this->designation.c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 360, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), std::to_string(this->capacity).c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 410, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), std::to_string(this->frequency).c_str());

	helperW.push_back(CreateWindow(L"button", L"OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 900, 600, 120, 40, hWnd, (HMENU)IDM_EDIT_OK, hInst, 0));
	helperW.push_back(CreateWindow(L"button", L"Cancel", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1030, 600, 120, 40, hWnd, (HMENU)IDM_CANCEL, hInst, 0));
}

void RAM::edit_get(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	char buf[100];
	GetWindowTextA(helperW[5], buf, 100);
	id = to_unsint(std::string(buf));
	GetWindowTextA(helperW[6], buf, 100);
	develpoer_name = std::string(buf);
	GetWindowTextA(helperW[7], buf, 100);
	designation = std::string(buf);
	GetWindowTextA(helperW[8], buf, 100);
	capacity = to_unsint(std::string(buf));
	GetWindowTextA(helperW[9], buf, 100);
	frequency = to_unsint(std::string(buf));
}

void RAM::set_attribs(TiXmlElement* element)
{
	element->SetAttribute("type", "RAM");
	element->SetAttribute("ID", id);
	element->SetAttribute("Developer", develpoer_name.c_str());
	element->SetAttribute("Designation", designation.c_str());
	element->SetAttribute("capacity", capacity);
	element->SetAttribute("frequency", frequency);
}

std::string RAM::get_string_info()
{
	std::string res = "RAM ";
	res += std::to_string(id) + " ";
	res += develpoer_name + " ";
	res += designation + " ";
	res += std::to_string(capacity) + " ";
	res += std::to_string(frequency) + " ";
	return res;
}



RAM::~RAM()
{
}




video_adapter::video_adapter():
	capacity(0)
{
	this->type = "VA";
}

video_adapter::video_adapter(unsigned _id, std::string dev_name, std::string design, unsigned cap)
{
	this->id = _id;
	this->develpoer_name = dev_name;
	this->designation = design;
	this->type = "VA";
	this->capacity = cap;
}

void video_adapter::create_set(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	helperW.push_back(CreateWindow(L"static", L"ID: ", WS_CHILD | WS_VISIBLE, 900, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"developers\n\rname: ", WS_CHILD | WS_VISIBLE | BS_MULTILINE, 900, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Designation: ", WS_CHILD | WS_VISIBLE, 900, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Capacity: ", WS_CHILD | WS_VISIBLE, 900, 360, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 360, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"button", L"OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 900, 600, 120, 40, hWnd, (HMENU)IDM_VA_OK, hInst, 0));
	helperW.push_back(CreateWindow(L"button", L"Cancel", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1030, 600, 120, 40, hWnd, (HMENU)IDM_CANCEL, hInst, 0));
}

void video_adapter::edit_set(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	helperW.push_back(CreateWindow(L"static", L"ID: ", WS_CHILD | WS_VISIBLE, 900, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"developers\n\rname: ", WS_CHILD | WS_VISIBLE | BS_MULTILINE, 900, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Designation: ", WS_CHILD | WS_VISIBLE, 900, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Capacity: ", WS_CHILD | WS_VISIBLE, 900, 360, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 210, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), std::to_string(this->id).c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 260, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), this->develpoer_name.c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 310, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), this->designation.c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 360, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), std::to_string(this->capacity).c_str());

	helperW.push_back(CreateWindow(L"button", L"OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 900, 600, 120, 40, hWnd, (HMENU)IDM_EDIT_OK, hInst, 0));
	helperW.push_back(CreateWindow(L"button", L"Cancel", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1030, 600, 120, 40, hWnd, (HMENU)IDM_CANCEL, hInst, 0));
}

void video_adapter::edit_get(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	char buf[100];
	GetWindowTextA(helperW[4], buf, 100);
	id = to_unsint(std::string(buf));
	GetWindowTextA(helperW[5], buf, 100);
	develpoer_name = std::string(buf);
	GetWindowTextA(helperW[6], buf, 100);
	designation = std::string(buf);
	GetWindowTextA(helperW[7], buf, 100);
	capacity = to_unsint(std::string(buf));
}

void video_adapter::set_attribs(TiXmlElement* element)
{
	element->SetAttribute("type", "VA");
	element->SetAttribute("ID", id);
	element->SetAttribute("Developer", develpoer_name.c_str());
	element->SetAttribute("Designation", designation.c_str());
	element->SetAttribute("Capacity", capacity);
}

std::string video_adapter::get_string_info()
{
	std::string res = "VA ";
	res += std::to_string(id) + " ";
	res += develpoer_name + " ";
	res += designation + " ";
	res += std::to_string(capacity);
	return res;
}

std::string video_adapter::get_developers_name()
{
	return develpoer_name;
}

std::string video_adapter::get_designation()
{
	return designation;
}

std::string video_adapter::get_type()
{
	return type;
}

unsigned video_adapter::get_id()
{
	return id;
}

unsigned video_adapter::get_capacity()
{
	return capacity;
}

video_adapter::~video_adapter()
{
}

monitor::monitor():
	rate(0)
{
	this->type = "MR";
}

monitor::monitor(unsigned _id, std::string dev_name, std::string design, unsigned rate, unsigned w, unsigned h)
{
	this->id = _id;
	this->develpoer_name = dev_name;
	this->designation = design;
	this->type = "MR";
	this->rate = rate;
	this->size.setSize(w, h);
}

void monitor::create_set(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	helperW.push_back(CreateWindow(L"static", L"ID: ", WS_CHILD | WS_VISIBLE, 900, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"developers\n\rname: ", WS_CHILD | WS_VISIBLE | BS_MULTILINE, 900, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Designation: ", WS_CHILD | WS_VISIBLE, 900, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"rate: ", WS_CHILD | WS_VISIBLE, 900, 360, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"size(w,h): ", WS_CHILD | WS_VISIBLE, 900, 410, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 360, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 410, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"button", L"OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 900, 600, 120, 40, hWnd, (HMENU)IDM_MR_OK, hInst, 0));
	helperW.push_back(CreateWindow(L"button", L"Cancel", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1030, 600, 120, 40, hWnd, (HMENU)IDM_CANCEL, hInst, 0));
}

void monitor::edit_set(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	helperW.push_back(CreateWindow(L"static", L"ID: ", WS_CHILD | WS_VISIBLE, 900, 210, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"developers\n\rname: ", WS_CHILD | WS_VISIBLE | BS_MULTILINE, 900, 260, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Designation: ", WS_CHILD | WS_VISIBLE, 900, 310, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Rate: ", WS_CHILD | WS_VISIBLE, 900, 360, 120, 40, hWnd, 0, hInst, 0));
	helperW.push_back(CreateWindow(L"static", L"Frequency: ", WS_CHILD | WS_VISIBLE, 900, 410, 120, 40, hWnd, 0, hInst, 0));

	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 210, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), std::to_string(this->id).c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 260, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), this->develpoer_name.c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 310, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), this->designation.c_str());
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 360, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), std::to_string(this->rate).c_str());

	std::string text = std::to_string(this->size.getSize().first) + "," + std::to_string(this->size.getSize().second);
	helperW.push_back(CreateWindow(L"edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 1030, 410, 120, 40, hWnd, 0, hInst, 0));
	SetWindowTextA(helperW.back(), text.c_str());

	helperW.push_back(CreateWindow(L"button", L"OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 900, 600, 120, 40, hWnd, (HMENU)IDM_EDIT_OK, hInst, 0));
	helperW.push_back(CreateWindow(L"button", L"Cancel", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1030, 600, 120, 40, hWnd, (HMENU)IDM_CANCEL, hInst, 0));
}

void monitor::edit_get(std::vector<HWND>& helperW, HWND hWnd, HINSTANCE hInst)
{
	char buf[100];
	GetWindowTextA(helperW[5], buf, 100);
	id = to_unsint(std::string(buf));
	GetWindowTextA(helperW[6], buf, 100);
	develpoer_name = std::string(buf);
	GetWindowTextA(helperW[7], buf, 100);
	designation = std::string(buf);
	GetWindowTextA(helperW[8], buf, 100);
	rate = to_unsint(std::string(buf)); 
	GetWindowTextA(helperW[9], buf, 100);
	std::string temp = std::string(buf);
	unsigned w, h;
	std::string wstr = std::string(temp.begin(), temp.begin() + temp.find(',')),
		hstr = std::string(temp.begin() + temp.find(',') + 1, temp.end());
	w = to_unsint(wstr);
	h = to_unsint(hstr);
	this->size.setSize(w, h);
}

std::string monitor::get_string_info()
{
	std::string res = "Monitor ";
	res += std::to_string(id) + " ";
	res += develpoer_name + " ";
	res += designation + " ";
	res += std::to_string(rate) + " ";
	res += std::to_string(size.getSize().first) + "," + std::to_string(size.getSize().second);
	return res;
}

void monitor::set_attribs(TiXmlElement* element)
{
	element->SetAttribute("type", "MR");
	element->SetAttribute("ID", id);
	element->SetAttribute("Developer", develpoer_name.c_str());
	element->SetAttribute("Designation", designation.c_str());
	element->SetAttribute("Rate", rate);
	element->SetAttribute("width", size.getSize().first);
	element->SetAttribute("height", size.getSize().second);
}

monitor::~monitor()
{
}

Size::Size():
	width(0),
	height(0)
{
}

void Size::setSize(int w, int h)
{
	width = w;
	height = h;
}

std::pair<int, int> Size::getSize()
{
	return std::pair<int, int>(width, height);
}
