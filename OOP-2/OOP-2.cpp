// OOP-2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "OOP-2.h"
#include "hardware.h"

#include "tinyxml.h"

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <iomanip>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

HWND hListbox;
HWND hCombobox, hCombobox2;

std::vector<HWND> helperW;
std::vector<std::unique_ptr<ID>> data;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OOP2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
          
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OOP2));
    MSG msg;
    // Цикл основного сообщения:
    int OK;
    while ((OK = GetMessage(&msg, nullptr, 0, 0)) != 0)
    {
        if (OK == -1)
            break;
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OOP2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OOP2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static char temp_cstr[1000];
    static int lSelectedItem;
    switch (message)
    {
    case WM_CREATE:
        
        CreateWindowExW(0, L"button", L"new RAM", WS_VISIBLE | WS_CHILD, 900, 60, 100, 40, hWnd, (HMENU)IDM_NEW_RAM, hInst, NULL);
        CreateWindowExW(0, L"button", L"new\n\rvideo adapter", WS_VISIBLE | WS_CHILD | BS_MULTILINE, 1010, 60, 100, 40, hWnd, (HMENU)IDM_NEW_VA, hInst, NULL);
        CreateWindowExW(0, L"button", L"new monitor", WS_VISIBLE | WS_CHILD, 1120, 60, 100, 40, hWnd, (HMENU)IDM_NEW_MR, hInst, NULL);

        CreateWindowExW(0, L"button", L"Edit", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 900, 110, 100, 40, hWnd, (HMENU)IDM_EDIT, hInst, NULL);
        CreateWindowExW(0, L"button", L"Delete", WS_VISIBLE | WS_CHILD, 1010, 110, 100, 40, hWnd, (HMENU)IDM_DELETE, hInst, NULL);
        CreateWindowExW(0, L"button", L"EXIT", WS_VISIBLE | WS_CHILD, 1120, 110, 100, 40, hWnd, (HMENU)IDM_EXIT, hInst, NULL);



        hListbox = CreateWindowExW(0, L"listbox", L"Размер", WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_VSCROLL | WS_BORDER | LBS_WANTKEYBOARDINPUT, 20, 60, 800, 600, hWnd, 0, hInst, NULL);
        hCombobox = CreateWindowExW(0, L"combobox", NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_HASSTRINGS, 20, 670, 200, 100, hWnd, 0, hInst, 0);
        CreateWindowExW(0, L"button", L"Save", WS_VISIBLE | WS_CHILD, 250, 670, 100, 40, hWnd, (HMENU)IDM_SAVE, hInst, NULL);
        CreateWindowExW(0, L"button", L"Open", WS_VISIBLE | WS_CHILD, 360, 670, 100, 40, hWnd, (HMENU)IDM_OPEN, hInst, NULL);

        hCombobox2 = CreateWindowExW(0, L"combobox", NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_HASSTRINGS, 600, 670, 200, 100, hWnd, 0, hInst, 0);
        
        SendMessageW(hCombobox, CB_ADDSTRING, 0, (LPARAM)L"XML file");
        SendMessageW(hCombobox, CB_ADDSTRING, 0, (LPARAM)L"Custom file");
        SendMessageW(hCombobox, CB_SETCURSEL, 0, 0);

        SendMessageW(hCombobox2, CB_ADDSTRING, 0, (LPARAM)L"nothing");
        SendMessageW(hCombobox2, CB_ADDSTRING, 0, (LPARAM)L"ciphre");
        SendMessageW(hCombobox2, CB_SETCURSEL, 0, 0);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_NEW_RAM:
                RAM::create_set(helperW, hWnd, hInst);
                break;
            case IDM_NEW_VA:
                video_adapter::create_set(helperW, hWnd, hInst);
                break;
            case IDM_NEW_MR:
                monitor::create_set(helperW, hWnd, hInst);
                break;
            case IDM_EDIT:
            {
                lSelectedItem = (int)SendMessage(hListbox, LB_GETCURSEL, 0, 0);
                if (lSelectedItem != LB_ERR) {
                    data[lSelectedItem]->edit_set(helperW, hWnd, hInst);
                }
            }
                break;
            case IDM_RAM_OK:
            {
                char temp_cs[100];
                unsigned id, cap, freq;
                std::string result = "RAM ";

                GetWindowTextA(helperW[5], temp_cs, 100);
                std::string temp(temp_cs);
                id = to_unsint(temp);
                result += temp + " ";

                GetWindowTextA(helperW[6], temp_cs, 100);
                std::string dev(temp_cs);
                result += dev + " ";

                GetWindowTextA(helperW[7], temp_cs, 100);
                std::string design(temp_cs);
                result += design + " ";

                GetWindowTextA(helperW[8], temp_cs, 100);
                temp = std::string(temp_cs);
                cap = to_unsint(temp);
                result += temp + " ";

                GetWindowTextA(helperW[9], temp_cs, 100);
                temp = std::string(temp_cs);
                freq = to_unsint(temp);
                result += temp;

                data.emplace_back(new RAM(id, dev, design, cap, freq));
                SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)result.data());
            }
                std::for_each(helperW.begin(), helperW.end(), [](const HWND h)
                    {
                        DestroyWindow(h);
                    });
                helperW.clear();
                break;
               
            case IDM_VA_OK:
            {
                char temp_cs[100];
                unsigned id, cap, freq;
                std::string result = "VA ";

                GetWindowTextA(helperW[4], temp_cs, 100);
                std::string temp(temp_cs);
                id = to_unsint(temp);
                result += temp + " ";

                GetWindowTextA(helperW[5], temp_cs, 100);
                std::string dev(temp_cs);
                result += dev + " ";

                GetWindowTextA(helperW[6], temp_cs, 100);
                std::string design(temp_cs);
                result += design + " ";

                GetWindowTextA(helperW[7], temp_cs, 100);
                temp = std::string(temp_cs);
                cap = to_unsint(temp);
                result += temp;

                data.emplace_back(new video_adapter(id, dev, design, cap));
                SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)result.data());
            }
                std::for_each(helperW.begin(), helperW.end(), [](const HWND h)
                {
                    DestroyWindow(h);
                });
                helperW.clear();
            break;

            case IDM_MR_OK:
            {
                char temp_cs[100];
                unsigned id, rate;
                std::string result = "Monitor ";

                GetWindowTextA(helperW[5], temp_cs, 100);
                std::string temp(temp_cs);
                id = to_unsint(temp);
                result += temp + " ";

                GetWindowTextA(helperW[6], temp_cs, 100);
                std::string dev(temp_cs);
                result += dev + " ";

                GetWindowTextA(helperW[7], temp_cs, 100);
                std::string design(temp_cs);
                result += design + " ";

                GetWindowTextA(helperW[8], temp_cs, 100);
                temp = std::string(temp_cs);
                rate = to_unsint(temp);
                result += temp + " ";

                GetWindowTextA(helperW[9], temp_cs, 100);
                temp = std::string(temp_cs);
                unsigned w, h;
                std::string wstr = std::string(temp.begin(), temp.begin() + temp.find(',')),
                    hstr = std::string(temp.begin() + temp.find(',') + 1, temp.end());
                w = to_unsint(wstr);
                h = to_unsint(hstr);
                result += temp;

                data.emplace_back(new monitor(id, dev, design, rate, w, h));
                SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)result.data());
            }
                std::for_each(helperW.begin(), helperW.end(), [](const HWND h)
                {
                    DestroyWindow(h);
                });
                helperW.clear();
            break;


            case IDM_EDIT_OK:
            {
                data[lSelectedItem]->edit_get(helperW, hWnd, hInst);
                std::string text = data[lSelectedItem]->get_string_info();
                SendMessageA(hListbox, LB_DELETESTRING, lSelectedItem, 0);
                SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)text.c_str());
                std::for_each(helperW.begin(), helperW.end(), [](const HWND h)
                    {
                        DestroyWindow(h);
                    });
                helperW.clear();
            }
                break;
            case IDM_DELETE:
            {
                int lSelectedItem = (int)SendMessage(hListbox, LB_GETCURSEL, 0, 0);
                if (lSelectedItem != LB_ERR) {
                    data.erase(data.begin() + lSelectedItem);
                    SendMessage(hListbox, LB_DELETESTRING, lSelectedItem, 0);
                }
            }
                break;
            case IDM_CANCEL:
                std::for_each(helperW.begin(), helperW.end(), [](const HWND h)
                    {
                        DestroyWindow(h);
                    });
                helperW.clear();
                break;
            
            case IDM_SAVE:
            {
                OPENFILENAMEA ofn = { 0 };
                ofn.lStructSize = sizeof(OPENFILENAME);
                ofn.hwndOwner = hWnd;
                char file_name[100];
                ofn.lpstrFile = file_name;
                ofn.lpstrFile[0] = L'\0';
                ofn.nMaxFile = 100;
                ofn.lpstrFilter = "All files\0*.*\0";
                ofn.nFilterIndex = 1;
                GetSaveFileNameA(&ofn);

                if (file_name == "")
                    break;

                if (SendMessageW(hCombobox, CB_GETCURSEL, 0, 0) == 0) {
                    TiXmlDocument doc;
                    TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "UTF-8", "");
                    doc.LinkEndChild(decl);
                    for (auto i = 0; i < data.size(); i++) {
                        TiXmlElement* elem = new TiXmlElement("ClassItem");
                        data[i]->set_attribs(elem);
                        doc.LinkEndChild(elem);
                    }             
                    doc.SaveFile(file_name);
                }
                if (SendMessageW(hCombobox, CB_GETCURSEL, 0, 0) == 1) {
                    std::string total;
                    for (auto i = 0; i < data.size(); i++) {
                        total += data[i]->get_string_info() + "\n";
                    }
                    std::ofstream fout(file_name);
                    fout << total;
                    fout.close();
                }

                if (SendMessageW(hCombobox2, CB_GETCURSEL, 0, 0) == 1) {
                    std::ifstream fin(file_name);
                    fin.seekg(0, std::ios::end);
                    int nFileSize = fin.tellg();
                    fin.close();
                    std::string str;
                    str.resize(nFileSize);
                    fin.open(file_name);
                    fin.read((char*)str.c_str(), nFileSize);
                    fin.close();
                    std::for_each(str.begin(), str.end(), [](char& ch) { ch ^= 0x47; });
                    std::ofstream fout(file_name);
                    fout.write((char*)str.c_str(), nFileSize);
                    fout.close();
                }
                
            }
            break;
            case IDM_OPEN:
            {
                data.clear();
                SendMessage(hListbox, LB_RESETCONTENT, 0, 0);

                OPENFILENAMEA ofn = { 0 };
                ofn.lStructSize = sizeof(OPENFILENAME);
                ofn.hwndOwner = hWnd;
                char file_name[100];
                ofn.lpstrFile = file_name;
                ofn.lpstrFile[0] = L'\0';
                ofn.nMaxFile = 100;
                ofn.lpstrFilter = "All files\0*.*\0";
                ofn.nFilterIndex = 1;
                GetOpenFileNameA(&ofn);

                if (SendMessageW(hCombobox2, CB_GETCURSEL, 0, 0) == 1) {
                    std::ifstream fin(file_name);
                    fin.seekg(0, std::ios::end);
                    int nFileSize = fin.tellg();
                    fin.close();
                    std::string str;
                    str.resize(nFileSize);
                    fin.open(file_name);
                    fin.read((char*)str.c_str(), nFileSize);
                    fin.close();
                    std::for_each(str.begin(), str.end(), [](char& ch) { ch ^= 0x47; });
                    std::ofstream fout(file_name);
                    fout.write((char*)str.c_str(), nFileSize);
                    fout.close();
                }


                if (file_name == "")
                    break;

                if (SendMessageW(hCombobox, CB_GETCURSEL, 0, 0) == 0) {                                   
                    TiXmlDocument doc(file_name);
                    if (!doc.LoadFile())
                        return 0;
                    TiXmlElement* elem = doc.FirstChildElement("ClassItem");
                    for (; elem != nullptr; elem = elem->NextSiblingElement("ClassItem")) {
                        
                        unsigned id, cap, freq, rate, w, h;
                        std::string type(elem->Attribute("type"));
                        elem->QueryUnsignedAttribute("ID", &id);
                        std::string dev(elem->Attribute("Developer"));
                        std::string des(elem->Attribute("Designation"));
                        if (type == "RAM") {
                            elem->QueryUnsignedAttribute("capacity", &cap);
                            elem->QueryUnsignedAttribute("frequency", &freq);
                            data.emplace_back(new RAM(id, dev, des, cap, freq));
                        }
                        if (type == "VA") {
                            elem->QueryUnsignedAttribute("capacity", &cap);
                            data.emplace_back(new video_adapter(id, dev, des, cap));
                        }
                        if (type == "MR") {
                            elem->QueryUnsignedAttribute("Rate", &rate);
                            elem->QueryUnsignedAttribute("width", &w);
                            elem->QueryUnsignedAttribute("height", &h);
                            data.emplace_back(new monitor(id, dev, des, rate, w, h));
                        }
                        std::string text = data.back()->get_string_info();
                        SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)text.c_str());
                        InvalidateRect(hListbox, NULL, TRUE);
                    }
                }
                if (SendMessageW(hCombobox, CB_GETCURSEL, 0, 0) == 1) {
                    unsigned id, cap, freq, rate, w, h;
                    std::string dev, des;
                    char buffer[10000];
                    std::ifstream fin(file_name);
                    fin.read(buffer, 10000);
                    fin.close();
                    std::string text(buffer);
                    std::replace(text.begin(), text.end(), '\n', ' ');
                    int pos, prev_pos = 0;
                    for (;;) {
                        pos = text.find(" ");
                        if (pos == text.npos) {
                            break;
                        }
                        std::string word(text.begin(), text.begin() + pos);
                        text.erase(text.begin(), text.begin() + pos + 1);
                        if (word == "RAM") {
                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            id = to_unsint(word);

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            dev = word;

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            des = word;

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            cap = to_unsint(word);

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            freq = to_unsint(word);

                            data.emplace_back(new RAM(id, dev, des, cap, freq));
                        }
                        if (word == "VA") {
                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            id = to_unsint(word);

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            dev = word;

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            des = word;

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            cap = to_unsint(word);

                            data.emplace_back(new video_adapter(id, dev, des, cap));
                        }
                        if (word == "Monitor") {
                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            id = to_unsint(word);

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            dev = word;

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            des = word;

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            rate = to_unsint(word);

                            pos = text.find(' ');
                            word = std::string(text.begin(), text.begin() + pos);
                            text.erase(text.begin(), text.begin() + pos + 1);
                            std::string wstr = std::string(word.begin(), word.begin() + word.find(',')),
                                hstr = std::string(word.begin() + word.find(',') + 1, word.end());
                            w = to_unsint(wstr);
                            h = to_unsint(hstr);
                            data.emplace_back(new monitor(id, dev, des, rate, w, h));
                        }
                        
                        std::string text = data.back()->get_string_info();
                        SendMessageA(hListbox, LB_ADDSTRING, 0, (LPARAM)text.c_str());
                        InvalidateRect(hListbox, NULL, TRUE);

                    }
                }
            }
            break;



            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
