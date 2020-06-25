#pragma once
#include "Resource.h"

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "tinyxml.h"
#include <Windows.h>

unsigned to_unsint(std::string str);

class base
{
public:
	virtual void edit_set(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst) = 0;
	virtual void edit_get(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst) = 0;
	virtual std::string get_string_info() = 0;
	virtual void set_attribs(TiXmlElement* element) = 0;
	base() {};
	virtual ~base() {};
};

class ID : public base
{
public:
	ID();
	virtual ~ID();
protected:
	unsigned id;
	std::string develpoer_name;
	std::string type;
	std::string designation;
};

class RAM : public ID
{
public:
	RAM();
	RAM(unsigned id, std::string dev_name, std::string design, unsigned cap, unsigned freq);
	std::string get_developers_name();
	std::string get_designation();
	std::string get_type();
	unsigned get_capacity();
	unsigned get_frequency();
	unsigned get_id();
	static void create_set(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void edit_set(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void edit_get(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void set_attribs(TiXmlElement* element);
	std::string get_string_info() override;
	virtual ~RAM();
protected:
	unsigned
		capacity,
		frequency;
};

class video_adapter : public ID
{
public:
	video_adapter();
	video_adapter(unsigned id, std::string dev_name, std::string design, unsigned cap);
	static void create_set(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void edit_set(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void edit_get(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void set_attribs(TiXmlElement* element);
	std::string get_string_info();
	std::string get_developers_name();
	std::string get_designation();
	std::string get_type();
	unsigned get_id();
	unsigned get_capacity();

	virtual ~video_adapter();
private:
	unsigned capacity;
};

class Size
{
public:
	Size();
	void setSize(int w, int h);
	std::pair<int, int> getSize();
private:
	unsigned
		width,
		height;
};

class monitor : public ID
{
public:
	monitor();
	monitor(unsigned id, std::string dev_name, std::string design, unsigned rate, unsigned w, unsigned h);
	static void create_set(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void edit_set(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	void edit_get(std::vector<HWND>& ws, HWND hWnd, HINSTANCE hInst);
	std::string get_string_info();
	void set_attribs(TiXmlElement* element);
	std::string get_developers_name();
	std::string get_designation();
	std::string get_type();
	unsigned get_rate();
	unsigned get_size();
	virtual ~monitor();
private:
	unsigned rate;
	Size size;
};

template<typename T>
struct creater
{
	static T* create() {
		return new T;
	}
};