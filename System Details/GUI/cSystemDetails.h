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

#ifndef _CSYSTEMDETAILS_H_
#define _CSYSTEMDETAILS_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "cSystemDetails.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_CSYSTEMDETAILS 0
#define ID_NOTEBOOK 1
#define ID_PANEL 2
#define ID_STATICTEXT 3
#define ID_TEXTCTRL103 4
#define ID_STATICTEXT1 5
#define ID_TEXTCTRL104 6
#define ID_STATICTEXT2 7
#define ID_TEXTCTRL105 8
#define ID_STATICTEXT3 9
#define ID_TEXTCTRL3 10
#define ID_STATICTEXT13 11
#define ID_TEXTCTRL4 12
#define ID_PANEL1 13
#define ID_NOTEBOOK2 14
#define ID_PANEL2 15
#define ID_STATICTEXT15 16
#define ID_TEXTCTRL5 17
#define ID_STATICTEXT17 18
#define ID_TEXTCTRL6 19
#define ID_STATICTEXT18 20
#define ID_TEXTCTRL7 21
#define ID_STATICTEXT19 22
#define ID_TEXTCTRL8 23
#define ID_STATICTEXT21 24
#define ID_TEXTCTRL9 25
#define ID_STATICTEXT24 26
#define ID_TEXTCTRL10 27
#define ID_PANEL3 28
#define ID_STATICTEXT25 29
#define ID_TEXTCTRL11 30
#define ID_STATICTEXT26 31
#define ID_TEXTCTRL12 32
#define ID_STATICTEXT28 33
#define ID_TEXTCTRL13 34
#define ID_STATICTEXT32 35
#define ID_TEXTCTRL14 36
#define ID_STATICTEXT34 37
#define ID_TEXTCTRL15 38
#define ID_STATICTEXT36 39
#define ID_TEXTCTRL16 40
#define ID_STATICTEXT39 41
#define ID_TEXTCTRL17 42
#define ID_STATICTEXT41 43
#define ID_TEXTCTRL18 44
#define ID_PANEL4 45
#define ID_STATICTEXT42 46
#define ID_TEXTCTRL19 47
#define ID_STATICTEXT44 48
#define ID_TEXTCTRL20 49
#define ID_STATICTEXT46 50
#define ID_TEXTCTRL21 51
#define ID_STATICTEXT48 52
#define ID_TEXTCTRL22 53
#define ID_STATICTEXT50 54
#define ID_TEXTCTRL23 55
#define ID_STATICTEXT52 56
#define ID_TEXTCTRL24 57
#define ID_STATICTEXT54 58
#define ID_TEXTCTRL25 59
#define ID_STATICTEXT56 60
#define ID_TEXTCTRL26 61
#define ID_STATICTEXT59 62
#define ID_TEXTCTRL27 63
#define ID_STATICTEXT61 64
#define ID_TEXTCTRL28 65
#define ID_STATICTEXT62 66
#define ID_TEXTCTRL29 67
#define ID_STATICTEXT63 68
#define ID_TEXTCTRL30 69
#define ID_STATICTEXT66 70
#define ID_TEXTCTRL31 71
#define ID_STATICTEXT67 72
#define ID_TEXTCTRL32 73
#define ID_STATICTEXT71 74
#define ID_TEXTCTRL33 75
#define ID_STATICTEXT73 76
#define ID_TEXTCTRL34 77
#define ID_STATICTEXT75 78
#define ID_TEXTCTRL35 79
#define ID_STATICTEXT77 80
#define ID_TEXTCTRL36 81
#define ID_STATICTEXT78 82
#define ID_TEXTCTRL37 83
#define ID_STATICTEXT81 84
#define ID_TEXTCTRL38 85
#define ID_STATICTEXT83 86
#define ID_TEXTCTRL39 87
#define ID_STATICTEXT84 88
#define ID_TEXTCTRL40 89
#define ID_STATICTEXT86 90
#define ID_TEXTCTRL41 91
#define ID_STATICTEXT88 92
#define ID_TEXTCTRL42 93
#define ID_PANEL10 94
#define ID_STATICTEXT80 95
#define ID_TEXTCTRL43 96
#define ID_STATICTEXT74 97
#define ID_TEXTCTRL44 98
#define ID_STATICTEXT70 99
#define ID_TEXTCTRL45 100
#define ID_STATICTEXT76 101
#define ID_TEXTCTRL46 102
#define ID_STATICTEXT72 103
#define ID_TEXTCTRL47 104
#define ID_STATICTEXT82 105
#define ID_TEXTCTRL48 106
#define ID_PANEL11 107
#define ID_NOTEBOOK1 108
#define ID_PANEL12 109
#define ID_STATICTEXT90 110
#define ID_TEXTCTRL99 111
#define ID_STATICTEXT29 112
#define ID_TEXTCTRL49 113
#define ID_STATICTEXT31 114
#define ID_TEXTCTRL50 115
#define ID_STATICTEXT4 116
#define ID_TEXTCTRL51 117
#define ID_STATICTEXT58 118
#define ID_TEXTCTRL52 119
#define ID_STATICTEXT60 120
#define ID_TEXTCTRL53 121
#define ID_STATICTEXT33 122
#define ID_TEXTCTRL54 123
#define ID_PANEL13 124
#define ID_STATICTEXT92 125
#define ID_TEXTCTRL55 126
#define ID_STATICTEXT94 127
#define ID_TEXTCTRL56 128
#define ID_STATICTEXT16 129
#define ID_TEXTCTRL57 130
#define ID_STATICTEXT14 131
#define ID_TEXTCTRL58 132
#define ID_STATICTEXT12 133
#define ID_TEXTCTRL59 134
#define ID_STATICTEXT10 135
#define ID_TEXTCTRL60 136
#define ID_STATICTEXT8 137
#define ID_TEXTCTRL61 138
#define ID_STATICTEXT6 139
#define ID_TEXTCTRL62 140
#define ID_PANEL14 141
#define ID_NOTEBOOK4 142
#define ID_PANEL15 143
#define ID_TEXTCTRL100 144
#define ID_LISTBOX 145
#define ID_PANEL16 146
#define ID_PANEL17 147
#define ID_STATICTEXT35 148
#define ID_TEXTCTRL63 149
#define ID_STATICTEXT37 150
#define ID_TEXTCTRL64 151
#define ID_STATICTEXT96 152
#define ID_TEXTCTRL65 153
#define ID_STATICTEXT98 154
#define ID_TEXTCTRL66 155
#define ID_STATICTEXT100 156
#define ID_TEXTCTRL67 157
#define ID_PANEL18 158
#define ID_NOTEBOOK5 159
#define ID_PANEL19 160
#define ID_NOTEBOOK3 161
#define ID_PANEL20 162
#define ID_STATICTEXT102 163
#define ID_TEXTCTRL68 164
#define ID_STATICTEXT104 165
#define ID_TEXTCTRL69 166
#define ID_STATICTEXT106 167
#define ID_TEXTCTRL70 168
#define ID_STATICTEXT108 169
#define ID_TEXTCTRL71 170
#define ID_STATICTEXT110 171
#define ID_TEXTCTRL72 172
#define ID_PANEL21 173
#define ID_STATICTEXT112 174
#define ID_TEXTCTRL73 175
#define ID_STATICTEXT114 176
#define ID_TEXTCTRL74 177
#define ID_PANEL22 178
#define ID_STATICTEXT40 179
#define ID_TEXTCTRL75 180
#define ID_PANEL23 181
#define ID_STATICTEXT116 182
#define ID_TEXTCTRL76 183
#define ID_STATICTEXT118 184
#define ID_TEXTCTRL77 185
#define ID_STATICTEXT120 186
#define ID_TEXTCTRL78 187
#define ID_STATICTEXT122 188
#define ID_TEXTCTRL79 189
#define ID_STATICTEXT124 190
#define ID_TEXTCTRL80 191
#define ID_STATICTEXT126 192
#define ID_TEXTCTRL81 193
#define ID_STATICTEXT128 194
#define ID_TEXTCTRL82 195
#define ID_STATICTEXT130 196
#define ID_TEXTCTRL83 197
#define ID_STATICTEXT131 198
#define ID_TEXTCTRL84 199
#define ID_STATICTEXT133 200
#define ID_TEXTCTRL85 201
#define ID_PANEL24 202
#define ID_STATICTEXT135 203
#define ID_TEXTCTRL86 204
#define ID_STATICTEXT137 205
#define ID_TEXTCTRL87 206
#define ID_STATICTEXT139 207
#define ID_TEXTCTRL88 208
#define ID_STATICTEXT141 209
#define ID_TEXTCTRL89 210
#define ID_STATICTEXT143 211
#define ID_TEXTCTRL90 212
#define ID_STATICTEXT145 213
#define ID_TEXTCTRL91 214
#define ID_STATICTEXT147 215
#define ID_TEXTCTRL92 216
#define ID_STATICTEXT149 217
#define ID_TEXTCTRL93 218
#define ID_STATICTEXT151 219
#define ID_TEXTCTRL94 220
#define ID_STATICTEXT153 221
#define ID_TEXTCTRL95 222
#define ID_STATICTEXT155 223
#define ID_TEXTCTRL96 224
#define ID_STATICTEXT157 225
#define ID_TEXTCTRL97 226
#define ID_PANEL25 227
#define ID_STATICTEXT38 228
#define ID_TEXTCTRL98 229
#define ID_BUTTON 230
#define SYMBOL_CSYSTEMDETAILS_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_CSYSTEMDETAILS_TITLE _("System Details")
#define SYMBOL_CSYSTEMDETAILS_IDNAME ID_CSYSTEMDETAILS
#define SYMBOL_CSYSTEMDETAILS_SIZE wxSize(600, 600)
#define SYMBOL_CSYSTEMDETAILS_POSITION wxDefaultPosition
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
 * cSystemDetails class declaration
 */

class cSystemDetails: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( cSystemDetails )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    cSystemDetails( );
    cSystemDetails( wxWindow* parent, wxWindowID id = SYMBOL_CSYSTEMDETAILS_IDNAME, const wxString& caption = SYMBOL_CSYSTEMDETAILS_TITLE, const wxPoint& pos = SYMBOL_CSYSTEMDETAILS_POSITION, const wxSize& size = SYMBOL_CSYSTEMDETAILS_SIZE, long style = SYMBOL_CSYSTEMDETAILS_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CSYSTEMDETAILS_IDNAME, const wxString& caption = SYMBOL_CSYSTEMDETAILS_TITLE, const wxPoint& pos = SYMBOL_CSYSTEMDETAILS_POSITION, const wxSize& size = SYMBOL_CSYSTEMDETAILS_SIZE, long style = SYMBOL_CSYSTEMDETAILS_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin cSystemDetails event handler declarations

    /// wxEVT_CLOSE_WINDOW event handler for ID_CSYSTEMDETAILS
    void OnCloseWindow( wxCloseEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void CloseClick( wxCommandEvent& event );

////@end cSystemDetails event handler declarations

////@begin cSystemDetails member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end cSystemDetails member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin cSystemDetails member variables
    wxTextCtrl* mp_osNameLbl;
    wxTextCtrl* mp_buildNumberLbl;
    wxTextCtrl* mp_platformLbl;
    wxTextCtrl* mp_osVersionLbl;
    wxTextCtrl* mp_servicePackLbl;
    wxTextCtrl* mp_cpuBrandLbl;
    wxTextCtrl* mp_cpuSpeedLbl;
    wxTextCtrl* mp_cpuNumLbl;
    wxTextCtrl* mp_cpuFamilyLbl;
    wxTextCtrl* mp_cpuModelLbl;
    wxTextCtrl* mp_cpuSteppingLbl;
    wxTextCtrl* mp_mmxLbl;
    wxTextCtrl* mp_mmxExtLbl;
    wxTextCtrl* mp_3dnowLbl;
    wxTextCtrl* mp_3dnowExtLbl;
    wxTextCtrl* mp_sseLbl;
    wxTextCtrl* mp_sse2Lbl;
    wxTextCtrl* mp_altiVecLbl;
    wxTextCtrl* mp_rdtscLbl;
    wxTextCtrl* mp_FPULbl;
    wxTextCtrl* mp_PGELbl;
    wxTextCtrl* mp_VMELbl;
    wxTextCtrl* mp_MCALbl;
    wxTextCtrl* mp_DELbl;
    wxTextCtrl* mp_CMOVLbl;
    wxTextCtrl* mp_PSELbl;
    wxTextCtrl* mp_PATLbl;
    wxTextCtrl* mp_TSCLbl;
    wxTextCtrl* mp_PSE36Lbl;
    wxTextCtrl* mp_MSRLbl;
    wxTextCtrl* mp_PSNUMLbl;
    wxTextCtrl* mp_PAELbl;
    wxTextCtrl* mp_CLFLUSHLbl;
    wxTextCtrl* mp_MCELbl;
    wxTextCtrl* mp_DTSLbl;
    wxTextCtrl* mp_CX8Lbl;
    wxTextCtrl* mp_ACPILbl;
    wxTextCtrl* mp_APICLbl;
    wxTextCtrl* mp_FXSRLbl;
    wxTextCtrl* mp_SEPLbl;
    wxTextCtrl* mp_SSLbl;
    wxTextCtrl* mp_MTRRLbl;
    wxTextCtrl* mp_TMLbl;
    wxTextCtrl* mp_totalMemoryLbl;
    wxTextCtrl* mp_freeMemoryLbl;
    wxTextCtrl* mp_totalPageLbl;
    wxTextCtrl* mp_freePageLbl;
    wxTextCtrl* mp_totalVirtualLbl;
    wxTextCtrl* mp_freeVirtualLbl;
    wxTextCtrl* mp_venderNameLbl;
    wxTextCtrl* mp_videoNameLbl;
    wxTextCtrl* mp_videoDriversLbl;
    wxTextCtrl* mp_videoMemoryLbl;
    wxTextCtrl* mp_videoMemoryFreeLbl;
    wxTextCtrl* mp_screenResolutionLbl;
    wxTextCtrl* mp_colourQuality;
    wxTextCtrl* mp_surfacesLbl;
    wxTextCtrl* mp_hardtohardBlits;
    wxTextCtrl* mp_hardtohardColourLbl;
    wxTextCtrl* mp_hardtohardAlphaLbl;
    wxTextCtrl* mp_softtohardBlitsLbl;
    wxTextCtrl* mp_softtohardColourLbl;
    wxTextCtrl* mp_softtohardApha;
    wxTextCtrl* mp_accelerColourLbl;
    wxTextCtrl* mp_openGLVersionLbl;
    wxListBox* mp_openGLExtentionsList;
    wxTextCtrl* mp_installedSoundLbl;
    wxTextCtrl* mp_volumeControlLbl;
    wxTextCtrl* mp_RLVolumeLbl;
    wxTextCtrl* mp_companyNameLbl;
    wxTextCtrl* mp_productNameLbl;
    wxNotebook* mp_hardDriveNoteBook;
    wxTextCtrl* mp_presentLbl;
    wxTextCtrl* mp_btnSwappedLbl;
    wxTextCtrl* mp_thresholdXLbl;
    wxTextCtrl* mp_thresholdYLbl;
    wxTextCtrl* mp_speedLbl;
    wxTextCtrl* mp_repeatLbl;
    wxTextCtrl* mp_delayLbl;
    wxTextCtrl* mp_joystickNumber;
    wxTextCtrl* mp_versionLbl;
    wxTextCtrl* mp_highestVersionLbl;
    wxTextCtrl* mp_descriptionLbl;
    wxTextCtrl* mp_systemStatusLbl;
    wxTextCtrl* mp_maxLbl;
    wxTextCtrl* mp_addressLbl;
    wxTextCtrl* mp_domainNameLbl;
    wxTextCtrl* mp_UDPLbl;
    wxTextCtrl* mp_computerNameLbl;
    wxTextCtrl* mp_userNameLbl;
    wxTextCtrl* mp_codePageLbl;
    wxTextCtrl* mp_calenderTypeLbl;
    wxTextCtrl* mp_oemCodePageLbl;
    wxTextCtrl* mp_languageLbl;
    wxTextCtrl* mp_dateFormatLbl;
    wxTextCtrl* mp_countryLbl;
    wxTextCtrl* mp_countryCodeLbl;
    wxTextCtrl* mp_timeFormatLbl;
    wxTextCtrl* mp_currencyLbl;
    wxTextCtrl* mp_timeFormatSpecifierLbl;
    wxTextCtrl* mp_localLanguageLbl;
    wxTextCtrl* mp_timeZoneLbl;
    wxTextCtrl* mp_cdDriveCountLbl;
    wxButton* mp_closeButton;
////@end cSystemDetails member variables
};

#endif
    // _CSYSTEMDETAILS_H_
