/*************************************************************************
**  Program Name:   System Details			      						**
**  Version Number: V1.6b                                     			**
**  Copyright (C):  September 22, 2008  Richard W. Allen	   			**
**  Date Started:   September 26, 2004	                      			**
**  Date Ended:     September 22, 2008                 					**
**  Author:         Richard W. Allen                         			**
**  Webpage:        http://richard-allen.homelinux.com					**
**  IDE:            Microsoft Visual Stuido .NET 2005         			**
**  Compiler:	    VC++ 2005				      						**
**  Langage:        C++					     							**
**  License:	    BSD license				      						**
**					see license.txt for for details	      				**
*************************************************************************/
/***************************************************************************************
**	System Details
**	Copyright (c) 2008, Richard W. Allen.
**	All rights reserved. 
**	Redistribution and use in source and binary forms, with or without modification,
**	are permitted provided that the following conditions are met: 
**
**	Redistributions of source code must retain the above copyright notice,
**	this list of conditions and the following disclaimer. 
**
**	Redistributions in binary form must reproduce the above copyright notice,
**	this list of conditions and the following disclaimer in the documentation 
**	and/or other materials provided with the distribution. 
**
**	Neither the names of System Detail's copyright owner nor the names of its contributors 
**	may be used to endorse or promote products derived from this software without 
**	specific prior written permission. 
**
**	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
**	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
**	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
**	IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**	INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
**	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
**	OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
**	WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
**	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
**	OF SUCH DAMAGE. 
***********************************************************************************************/

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "cHardDriveInfo.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "cHardDriveInfo.h"


////@begin XPM images
////@end XPM images

/*!
 * cHardDriveInfo type definition
 */

IMPLEMENT_DYNAMIC_CLASS( cHardDriveInfo, wxPanel )

/*!
 * cHardDriveInfo event table definition
 */

BEGIN_EVENT_TABLE( cHardDriveInfo, wxPanel )

////@begin cHardDriveInfo event table entries
////@end cHardDriveInfo event table entries

END_EVENT_TABLE()

/*!
 * cHardDriveInfo constructors
 */

cHardDriveInfo::cHardDriveInfo( )
{
}

cHardDriveInfo::cHardDriveInfo( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, pos, size, style);
}

void cHardDriveInfo::setDriveInfo(const wxString name, const wxString type, const wxString totalspace, const wxString freespace, const wxString filesystemtype)
{
	mp_driveName->SetLabel(name);
	mp_type->SetLabel(type);
	mp_total->SetLabel(totalspace);
	mp_free->SetLabel(freespace);
	mp_fileSystem->SetLabel(filesystemtype);
}

/*!
 * cHardDriveInfo creator
 */

bool cHardDriveInfo::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin cHardDriveInfo member initialisation
    mp_driveName = NULL;
    mp_type = NULL;
    mp_total = NULL;
    mp_free = NULL;
    mp_fileSystem = NULL;
////@end cHardDriveInfo member initialisation

////@begin cHardDriveInfo creation
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end cHardDriveInfo creation
    return TRUE;
}

/*!
 * Control creation for cHardDriveInfo
 */

void cHardDriveInfo::CreateControls()
{    
////@begin cHardDriveInfo content construction

    cHardDriveInfo* itemPanel1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemPanel1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemPanel1, wxID_STATIC, _("Drive Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxADJUST_MINSIZE, 5);

    mp_driveName = new wxTextCtrl( itemPanel1, ID_TEXTCTRL101, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer3->Add(mp_driveName, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer6, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemPanel1, wxID_STATIC, _("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemStaticText7, 0, wxGROW|wxRIGHT|wxADJUST_MINSIZE, 37);

    mp_type = new wxTextCtrl( itemPanel1, ID_TEXTCTRL102, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer6->Add(mp_type, 0, wxGROW, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer9, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText10 = new wxStaticText( itemPanel1, wxID_STATIC, _("Total:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer9->Add(itemStaticText10, 0, wxGROW|wxRIGHT|wxADJUST_MINSIZE, 37);

    mp_total = new wxTextCtrl( itemPanel1, ID_TEXTCTRL2, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer9->Add(mp_total, 0, wxGROW, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer12, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText13 = new wxStaticText( itemPanel1, wxID_STATIC, _("Free:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(itemStaticText13, 0, wxGROW|wxRIGHT|wxADJUST_MINSIZE, 40);

    mp_free = new wxTextCtrl( itemPanel1, ID_TEXTCTRL1, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer12->Add(mp_free, 0, wxGROW, 5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer15, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( itemPanel1, wxID_STATIC, _("File System:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer15->Add(itemStaticText16, 0, wxGROW|wxRIGHT|wxADJUST_MINSIZE, 8);

    mp_fileSystem = new wxTextCtrl( itemPanel1, ID_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer15->Add(mp_fileSystem, 0, wxGROW, 5);

////@end cHardDriveInfo content construction
}

/*!
 * Should we show tooltips?
 */

bool cHardDriveInfo::ShowToolTips()
{
    return TRUE;
}

/*!
 * Get bitmap resources
 */

wxBitmap cHardDriveInfo::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin cHardDriveInfo bitmap retrieval
    return wxNullBitmap;
////@end cHardDriveInfo bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon cHardDriveInfo::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin cHardDriveInfo icon retrieval
    return wxNullIcon;
////@end cHardDriveInfo icon retrieval
}
