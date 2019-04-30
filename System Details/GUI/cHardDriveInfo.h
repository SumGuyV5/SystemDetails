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

#ifndef _CHARDDRIVEINFO_H_
#define _CHARDDRIVEINFO_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "cHardDriveInfo.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_CHARDDRIVEINFO 10027
#define SYMBOL_CHARDDRIVEINFO_STYLE 0
#define SYMBOL_CHARDDRIVEINFO_TITLE _("Hard Drive Info")
#define SYMBOL_CHARDDRIVEINFO_IDNAME ID_CHARDDRIVEINFO
#define SYMBOL_CHARDDRIVEINFO_SIZE wxSize(400, 300)
#define SYMBOL_CHARDDRIVEINFO_POSITION wxDefaultPosition
#define ID_TEXTCTRL101 10074
#define ID_TEXTCTRL102 10029
#define ID_TEXTCTRL2 10075
#define ID_TEXTCTRL1 10076
#define ID_TEXTCTRL 10077
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif

/*!
 * cHardDriveInfo class declaration
 */

class cHardDriveInfo: public wxPanel
{    
    DECLARE_DYNAMIC_CLASS( cHardDriveInfo )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    cHardDriveInfo( );
    cHardDriveInfo( wxWindow* parent, wxWindowID id = SYMBOL_CHARDDRIVEINFO_IDNAME, const wxPoint& pos = SYMBOL_CHARDDRIVEINFO_POSITION, const wxSize& size = SYMBOL_CHARDDRIVEINFO_SIZE, long style = SYMBOL_CHARDDRIVEINFO_STYLE );

	void setDriveInfo(const wxString name, const wxString type, const wxString totalspace, const wxString freespace, const wxString filesystemtype);

private:
    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CHARDDRIVEINFO_IDNAME, const wxPoint& pos = SYMBOL_CHARDDRIVEINFO_POSITION, const wxSize& size = SYMBOL_CHARDDRIVEINFO_SIZE, long style = SYMBOL_CHARDDRIVEINFO_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin cHardDriveInfo event handler declarations

////@end cHardDriveInfo event handler declarations

////@begin cHardDriveInfo member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end cHardDriveInfo member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin cHardDriveInfo member variables
    wxTextCtrl* mp_driveName;
    wxTextCtrl* mp_type;
    wxTextCtrl* mp_total;
    wxTextCtrl* mp_free;
    wxTextCtrl* mp_fileSystem;
////@end cHardDriveInfo member variables
};

#endif
    // _CHARDDRIVEINFO_H_
