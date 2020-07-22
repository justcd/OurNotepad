// This file is part of OurNotepad project
// Copyright (C)2020 Mapoet Niphy<mapoet.niphy@gmail.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// Note that the GPL places important restrictions on "derived works", yet
// it does not provide a detailed definition of that term.  To avoid      
// misunderstandings, we consider an application to constitute a          
// "derivative work" for the purpose of this license if it does any of the
// following:                                                             
// 1. Integrates source code from OurNotepad.
// 2. Integrates/includes/aggregates OurNotepad into a proprietary executable
//    installer, such as those produced by InstallShield.
// 3. Links to a library or executes a program that does any of the above.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


#pragma once

#include <windows.h>
#include <commctrl.h>
#include "Window.h"

class ToolTip : public Window
{
public :
	ToolTip() = default;
    
	void destroy(){
		::DestroyWindow(_hSelf);
		_hSelf = NULL;
	};

// Attributes
public:

// Implementation
public:
	virtual void init(HINSTANCE hInst, HWND hParent);
	void Show(RECT rectTitle, const TCHAR* pszTitleText, int iXOff = 0, int iWidthOff = 0);

protected:
    WNDPROC		_defaultProc = nullptr;
	BOOL		_bTrackMouse = FALSE;
	TOOLINFO	_ti;

    static LRESULT CALLBACK staticWinProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
        return (((ToolTip *)(::GetWindowLongPtr(hwnd, GWLP_USERDATA)))->runProc(Message, wParam, lParam));
    };
	LRESULT runProc(UINT Message, WPARAM wParam, LPARAM lParam);
};
