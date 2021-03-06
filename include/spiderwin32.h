#pragma once

#ifndef H_WIN32SPIDER
#define H_WIN32SPIDER

#include <Windows.h>
#include <wingdi.h>
#include <map>
#include "Color.h"
#include "GraphicsContext.h"
using namespace std;
namespace winspider {
	COLORREF toWin32Color(spider::Color color);

	class Win32GraphicsContext : public spider::GraphicsContext {
	private:
		HDC hDC;
		map<string, HWND> *controls;
	public:
		Win32GraphicsContext(HDC hDC);
		~Win32GraphicsContext();
		void drawLine(int x1, int y1, int w, int h, spider::Color *color);
		void drawImage(spider::Image *image, int x1, int y1, int w, int h);
		void drawRectangle(int x1, int y1, int w, int h, spider::Color *color);
		void fillRectangle(int x1, int y1, int w, int h, spider::Color *color);
		void drawString(string *text, spider::FontStyle *fontStyle, spider::Color *color,int x, int y, int w, int h);
		void setFontStyle(spider::FontStyle *fs);
		void drawControl(int x, int y, int w, int h, char *name);
		void setOrigo(const int& x, const int& y);
	};
};
#endif
