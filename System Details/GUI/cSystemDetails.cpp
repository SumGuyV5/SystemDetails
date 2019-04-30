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
#pragma implementation "cSystemDetails.h"
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

#include "cSystemDetails.h"
#include "cHardDriveInfo.h"
#include "../System Information/System Information.hpp"
#include <SDL.h>

////@begin XPM images
////@end XPM images

/*!
 * cSystemDetails type definition
 */

IMPLEMENT_DYNAMIC_CLASS( cSystemDetails, wxDialog )

/*!
 * cSystemDetails event table definition
 */

BEGIN_EVENT_TABLE( cSystemDetails, wxDialog )

////@begin cSystemDetails event table entries
    EVT_CLOSE( cSystemDetails::OnCloseWindow )

    EVT_BUTTON( ID_BUTTON, cSystemDetails::CloseClick )

////@end cSystemDetails event table entries

END_EVENT_TABLE()

/*!
 * cSystemDetails constructors
 */

cSystemDetails::cSystemDetails( )
{
}

cSystemDetails::cSystemDetails( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);

///My Code starts here.
///Operating System Start
	///OS Description	
	mp_osNameLbl->SetLabel(System_Information::Operating_System::OSDescription());

	///Build Number
	mp_buildNumberLbl->SetLabel(System_Information::Operating_System::BuildNumber());

	///Platform
	mp_platformLbl->SetLabel(System_Information::Operating_System::Platform());

	///OS Version
	mp_osVersionLbl->SetLabel(System_Information::Operating_System::MinorVersion());

	///Service Pack
	mp_servicePackLbl->SetLabel(System_Information::Operating_System::ServicePack());
///Operating System End

///CPU Details Start
	///General CPU Info Start
		///CPU Brand
		mp_cpuBrandLbl->SetLabel(System_Information::CPU_Details::General_CPU_Info::CPUBrand());

		///CPU Speed
		mp_cpuSpeedLbl->SetLabel(System_Information::CPU_Details::General_CPU_Info::CPUSpeed());

		///Number of CPUs
		mp_cpuNumLbl->SetLabel(System_Information::CPU_Details::General_CPU_Info::NumberofCPU());

		///CPU family
		mp_cpuFamilyLbl->SetLabel(System_Information::CPU_Details::General_CPU_Info::CPUFamily());

		///CPU Model
		mp_cpuModelLbl->SetLabel(System_Information::CPU_Details::General_CPU_Info::CPUModel());

		///CPU Stepping
		mp_cpuSteppingLbl->SetLabel(System_Information::CPU_Details::General_CPU_Info::CPUStepping());
	///General CPU Info End
	///CPU Extensions Start
		///MMX
		mp_mmxLbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::MMX());


		///MMX Ext.
		mp_mmxExtLbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::MMXExt());

		///3D Now!
		mp_3dnowLbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::_3DNow());

		///3D Now! Ext.
		mp_3dnowExtLbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::_3DNowExt());

		///SSE
		mp_sseLbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::SSE());

		///SSE2
		mp_sse2Lbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::SSE2());

		///AltiVec
		mp_altiVecLbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::AltiVec());

		///RDTSC
		mp_rdtscLbl->SetLabel(System_Information::CPU_Details::CPU_Extensions::RDTSC());
	///CPU Extensions End
	///More CPU Extensions Start
		///FPU
		mp_FPULbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::FPU());

		///VME
		mp_VMELbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::VME());

		///DE
		mp_DELbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::DE());

		///PSE
		mp_PSELbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::PSE());

		///TSC
		mp_TSCLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::TSC());

		///MSR
		mp_MSRLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::MSR());

		///PAE
		mp_PAELbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::PAE());

		///MCE
		mp_MCELbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::MCE());

		///CX8
		mp_CX8Lbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::CX8());

		///APIC	
		mp_APICLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::APIC());

		///SEP
		mp_SEPLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::SEP());

		///MTRR
		mp_MTRRLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::MTRR());

		///PGE
		mp_PGELbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::PGE());

		///MCA
		mp_MCALbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::MCA());

		///CMOV
		mp_CMOVLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::CMOV());

		///PAT
		mp_PATLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::PAT());

		///PSE36
		mp_PSE36Lbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::PSE36());

		///PSNUM
		mp_PSNUMLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::PSNUM());

		///CLFLUSH
		mp_CLFLUSHLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::CLFLUSH());

		///DTS
		mp_DTSLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::DTS());

		///ACPI
		mp_ACPILbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::ACPI());

		///FXSR
		mp_FXSRLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::FXSR());

		///SS
		mp_SSLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::SS());

		///TM
		mp_TMLbl->SetLabel(System_Information::CPU_Details::More_CPU_Extensions::TM());
	///More CPU Extensions End
///CPU Details End
///Memory Start
	///Total memory
	mp_totalMemoryLbl->SetLabel(System_Information::Memory::TotalMemory());

	///Freememory
	mp_freeMemoryLbl->SetLabel(System_Information::Memory::FreeMemory());

	///Total memory Page
	mp_totalPageLbl->SetLabel(System_Information::Memory::TotalPage());

	///Free memory Page
	mp_freePageLbl->SetLabel(System_Information::Memory::FreePage());

	///Total memory Virtual
	mp_totalVirtualLbl->SetLabel(System_Information::Memory::TotalVirtual());

	///Free memory Virtual
	mp_freeVirtualLbl->SetLabel(System_Information::Memory::FreeVirtual());
///Memory End
///Vidow Card Info Start
	///General Card Info Start
		///We are going to use OpenGL SDL will make things easy with no OS dependant coded
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Surface* MainWindow = SDL_SetVideoMode(680, 480, 16, SDL_OPENGL);
		///Vender Name
		mp_venderNameLbl->SetLabel(System_Information::Video_Card_Info::General_Card_Info::Vender());

		///Video Card Name
		mp_videoNameLbl->SetLabel(System_Information::Video_Card_Info::General_Card_Info::VideoCard());

		///Driver Version
		mp_videoDriversLbl->SetLabel(System_Information::Video_Card_Info::General_Card_Info::VideoDrivers());

		///Total Video Memory
		mp_videoMemoryLbl->SetLabel(System_Information::Video_Card_Info::General_Card_Info::TotalVideoMemory());

		///Free Video Memory
		mp_videoMemoryFreeLbl->SetLabel(System_Information::Video_Card_Info::General_Card_Info::FreeVideoMemory());

		///Screen Resolution
		mp_screenResolutionLbl->SetLabel(System_Information::Video_Card_Info::General_Card_Info::ScreenResolution());

		///Colour Quality
		mp_colourQuality->SetLabel(System_Information::Video_Card_Info::General_Card_Info::ColourQuality());
	///General Card Info Ends
	///2D Card Info Start
		///2D Surfaces
		mp_surfacesLbl->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::_2DSurfaces());

		///Hardware to Hardware Blit
		mp_hardtohardBlits->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::HardtoHardBlits());

		///Hardware to Hardware Colour Blit
		mp_hardtohardColourLbl->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::HardtoHardColourBlits());

		///Hardware to Hardware Alpha Blit
		mp_hardtohardAlphaLbl->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::HardtoHardAlphaBlits());

		///Software to Hardware Blit
		mp_softtohardBlitsLbl->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::SofttoHardBlits());

		///Software to Hardware Colour Blit	
		mp_softtohardColourLbl->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::SofttoHardColourBlits());

		///Software to Hardware Alpha Blit
		mp_softtohardApha->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::SofttoHardAlphaBlits());

		///Acceler Colour
		mp_accelerColourLbl->SetLabel(System_Information::Video_Card_Info::_2D_Card_Info::AcceleratedColourFills());
	///2D Card Info End
	///3D Card Info Start
		///OpenGL Info Start
			///OpenGL Version
			mp_openGLVersionLbl->SetLabel(System_Information::Video_Card_Info::_3D_Card_Info::OpenGL_Info::OpenGLVersion());
			///OpenGL Extentions
			System_Information::Video_Card_Info::_3D_Card_Info::OpenGL_Info::OpenGLExtenitons(*mp_openGLExtentionsList);
		///OpenGL Info End
		///DirectX Info Start
		///DirectX Info End
	///3D Card Info End
///Video Card Info End
///Sound Card Info Start
	///Sound Installed 
	mp_installedSoundLbl->SetLabel(System_Information::Sound_Card_Info::Installed());

	///Volume Control
	mp_volumeControlLbl->SetLabel(System_Information::Sound_Card_Info::VolumeContarol());

	///RL Volume Control
	mp_RLVolumeLbl->SetLabel(System_Information::Sound_Card_Info::SeparateRLVolCtrl());

	///Company Name
	mp_companyNameLbl->SetLabel(System_Information::Sound_Card_Info::CompanyName());

	///Product Name
	mp_productNameLbl->SetLabel(System_Information::Sound_Card_Info::ProductName());
///Sound Card Info End
///Hard Drive Info Start
	wxString name, type, totalspace, freespace, filesystemtype;

	for (;System_Information::Hard_Drive_Info::GetHardDriveInfo(name, type, totalspace, freespace, filesystemtype) == true;)
	{
		cHardDriveInfo* temp = new cHardDriveInfo(mp_hardDriveNoteBook);
		temp->setDriveInfo(name, type, totalspace, freespace, filesystemtype);
		mp_hardDriveNoteBook->AddPage(temp, name);
	}
///Hard Drive Info End
///Input Info Start
	///Mouse Start
		///Mouse Present
		mp_presentLbl->SetLabel(System_Information::Input_Info::Mouse::Present());

		///Button Swapped
		mp_btnSwappedLbl->SetLabel(System_Information::Input_Info::Mouse::ButtonSwapped());

		///Threshold X
		mp_thresholdXLbl->SetLabel(System_Information::Input_Info::Mouse::ThresholdX());


		///Threshold Y
		mp_thresholdYLbl->SetLabel(System_Information::Input_Info::Mouse::ThresholdY());

		///Speed
		mp_speedLbl->SetLabel(System_Information::Input_Info::Mouse::Speed());
	///Mouse End
	///Keyboard Start
		///Repeat
		mp_repeatLbl->SetLabel(System_Information::Input_Info::Keyboard::Repeat());

		///Delay
		mp_delayLbl->SetLabel(System_Information::Input_Info::Keyboard::Delay());
	///Keyboard End
	///Joystick Start
		///Number of Joysticks
		mp_joystickNumber->SetLabel(System_Information::Input_Info::Joystick::NumberofJoysticks());
	///Joystick End
///Input Info End
///Socket Info Start
	///Socket Version
	mp_versionLbl->SetLabel(System_Information::Socket_Info::Version());

	///Highest Ver
	mp_highestVersionLbl->SetLabel(System_Information::Socket_Info::HighestVersion());

	///Socket Description
	mp_descriptionLbl->SetLabel(System_Information::Socket_Info::Description());

	///Socket Status
	mp_systemStatusLbl->SetLabel(System_Information::Socket_Info::SystemStatus());

	///Socket Max
	mp_maxLbl->SetLabel(System_Information::Socket_Info::Max());

	///Socket IP
	mp_addressLbl->SetLabel(System_Information::Socket_Info::IPAddress());

	///Socket Domain Name
	mp_domainNameLbl->SetLabel(System_Information::Socket_Info::DomainName());

	///Socket UDP
	mp_UDPLbl->SetLabel(System_Information::Socket_Info::UDPMax());

	///Socket Computer name
	mp_computerNameLbl->SetLabel(System_Information::Socket_Info::ComputerName());

	///Socket User Name
	mp_userNameLbl->SetLabel(System_Information::Socket_Info::UserName());
///Socket Info End
///Locale Info Start
	///Code page
	mp_codePageLbl->SetLabel(System_Information::Locale_Info::CodePage());

	///Calender Type
	mp_calenderTypeLbl->SetLabel(System_Information::Locale_Info::CalendarType());

	///OEM Code page
	mp_oemCodePageLbl->SetLabel(System_Information::Locale_Info::OEMCodePage());

	///Language
	mp_languageLbl->SetLabel(System_Information::Locale_Info::Language());

	///Date format
	mp_dateFormatLbl->SetLabel(System_Information::Locale_Info::DateFormat());

	///Country
	mp_countryLbl->SetLabel(System_Information::Locale_Info::Country());

	///Country code
	mp_countryCodeLbl->SetLabel(System_Information::Locale_Info::CountryCode());

	///Time format
	mp_timeFormatLbl->SetLabel(System_Information::Locale_Info::TimeFormat());

	///Currency
	mp_currencyLbl->SetLabel(System_Information::Locale_Info::Currency());

	///Time Format
	mp_timeFormatSpecifierLbl->SetLabel(System_Information::Locale_Info::TimeFormat());

	///Local Language
	mp_localLanguageLbl->SetLabel(System_Information::Locale_Info::LocaleLanguage());

	///Time Zone
	mp_timeZoneLbl->SetLabel(System_Information::Locale_Info::TimeZone());
///Locale Info End
///Misc Info Start
	///Number of CD Drives 
	mp_cdDriveCountLbl->SetLabel(System_Information::Misc_Info::NumberofCDDrives());
///Misc Info End
	SDL_Quit();
///My Code Ends Here.
}

/*!
 * cSystemDetails creator
 */

bool cSystemDetails::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin cSystemDetails member initialisation
    mp_osNameLbl = NULL;
    mp_buildNumberLbl = NULL;
    mp_platformLbl = NULL;
    mp_osVersionLbl = NULL;
    mp_servicePackLbl = NULL;
    mp_cpuBrandLbl = NULL;
    mp_cpuSpeedLbl = NULL;
    mp_cpuNumLbl = NULL;
    mp_cpuFamilyLbl = NULL;
    mp_cpuModelLbl = NULL;
    mp_cpuSteppingLbl = NULL;
    mp_mmxLbl = NULL;
    mp_mmxExtLbl = NULL;
    mp_3dnowLbl = NULL;
    mp_3dnowExtLbl = NULL;
    mp_sseLbl = NULL;
    mp_sse2Lbl = NULL;
    mp_altiVecLbl = NULL;
    mp_rdtscLbl = NULL;
    mp_FPULbl = NULL;
    mp_PGELbl = NULL;
    mp_VMELbl = NULL;
    mp_MCALbl = NULL;
    mp_DELbl = NULL;
    mp_CMOVLbl = NULL;
    mp_PSELbl = NULL;
    mp_PATLbl = NULL;
    mp_TSCLbl = NULL;
    mp_PSE36Lbl = NULL;
    mp_MSRLbl = NULL;
    mp_PSNUMLbl = NULL;
    mp_PAELbl = NULL;
    mp_CLFLUSHLbl = NULL;
    mp_MCELbl = NULL;
    mp_DTSLbl = NULL;
    mp_CX8Lbl = NULL;
    mp_ACPILbl = NULL;
    mp_APICLbl = NULL;
    mp_FXSRLbl = NULL;
    mp_SEPLbl = NULL;
    mp_SSLbl = NULL;
    mp_MTRRLbl = NULL;
    mp_TMLbl = NULL;
    mp_totalMemoryLbl = NULL;
    mp_freeMemoryLbl = NULL;
    mp_totalPageLbl = NULL;
    mp_freePageLbl = NULL;
    mp_totalVirtualLbl = NULL;
    mp_freeVirtualLbl = NULL;
    mp_venderNameLbl = NULL;
    mp_videoNameLbl = NULL;
    mp_videoDriversLbl = NULL;
    mp_videoMemoryLbl = NULL;
    mp_videoMemoryFreeLbl = NULL;
    mp_screenResolutionLbl = NULL;
    mp_colourQuality = NULL;
    mp_surfacesLbl = NULL;
    mp_hardtohardBlits = NULL;
    mp_hardtohardColourLbl = NULL;
    mp_hardtohardAlphaLbl = NULL;
    mp_softtohardBlitsLbl = NULL;
    mp_softtohardColourLbl = NULL;
    mp_softtohardApha = NULL;
    mp_accelerColourLbl = NULL;
    mp_openGLVersionLbl = NULL;
    mp_openGLExtentionsList = NULL;
    mp_installedSoundLbl = NULL;
    mp_volumeControlLbl = NULL;
    mp_RLVolumeLbl = NULL;
    mp_companyNameLbl = NULL;
    mp_productNameLbl = NULL;
    mp_hardDriveNoteBook = NULL;
    mp_presentLbl = NULL;
    mp_btnSwappedLbl = NULL;
    mp_thresholdXLbl = NULL;
    mp_thresholdYLbl = NULL;
    mp_speedLbl = NULL;
    mp_repeatLbl = NULL;
    mp_delayLbl = NULL;
    mp_joystickNumber = NULL;
    mp_versionLbl = NULL;
    mp_highestVersionLbl = NULL;
    mp_descriptionLbl = NULL;
    mp_systemStatusLbl = NULL;
    mp_maxLbl = NULL;
    mp_addressLbl = NULL;
    mp_domainNameLbl = NULL;
    mp_UDPLbl = NULL;
    mp_computerNameLbl = NULL;
    mp_userNameLbl = NULL;
    mp_codePageLbl = NULL;
    mp_calenderTypeLbl = NULL;
    mp_oemCodePageLbl = NULL;
    mp_languageLbl = NULL;
    mp_dateFormatLbl = NULL;
    mp_countryLbl = NULL;
    mp_countryCodeLbl = NULL;
    mp_timeFormatLbl = NULL;
    mp_currencyLbl = NULL;
    mp_timeFormatSpecifierLbl = NULL;
    mp_localLanguageLbl = NULL;
    mp_timeZoneLbl = NULL;
    mp_cdDriveCountLbl = NULL;
    mp_closeButton = NULL;
////@end cSystemDetails member initialisation

////@begin cSystemDetails creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end cSystemDetails creation
    return TRUE;
}

/*!
 * Control creation for cSystemDetails
 */

void cSystemDetails::CreateControls()
{    
////@begin cSystemDetails content construction
    cSystemDetails* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxNotebook* itemNotebook3 = new wxNotebook( itemDialog1, ID_NOTEBOOK, wxDefaultPosition, wxSize(400, 400), wxNB_DEFAULT|wxNB_TOP );

    wxPanel* itemPanel4 = new wxPanel( itemNotebook3, ID_PANEL, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    itemPanel4->SetSizer(itemBoxSizer5);

    itemBoxSizer5->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer7, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText8 = new wxStaticText( itemPanel4, ID_STATICTEXT, _("OS:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(itemStaticText8, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer7->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 53);

    mp_osNameLbl = new wxTextCtrl( itemPanel4, ID_TEXTCTRL103, _("OS DESCRIPTION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer7->Add(mp_osNameLbl, 1, wxGROW, 5);

    itemBoxSizer7->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer12, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText13 = new wxStaticText( itemPanel4, ID_STATICTEXT1, _("Build Number:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(itemStaticText13, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer12->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_buildNumberLbl = new wxTextCtrl( itemPanel4, ID_TEXTCTRL104, _("BUILD NUMBER"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer12->Add(mp_buildNumberLbl, 1, wxGROW, 5);

    itemBoxSizer12->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer17, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText18 = new wxStaticText( itemPanel4, ID_STATICTEXT2, _("Platform:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer17->Add(itemStaticText18, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer17->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 27);

    mp_platformLbl = new wxTextCtrl( itemPanel4, ID_TEXTCTRL105, _("PLATFORM"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer17->Add(mp_platformLbl, 1, wxGROW, 5);

    itemBoxSizer17->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer22, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText23 = new wxStaticText( itemPanel4, ID_STATICTEXT3, _("OS Version:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer22->Add(itemStaticText23, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer22->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 15);

    mp_osVersionLbl = new wxTextCtrl( itemPanel4, ID_TEXTCTRL3, _("OS VERSION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer22->Add(mp_osVersionLbl, 1, wxGROW, 5);

    itemBoxSizer22->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer27, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText28 = new wxStaticText( itemPanel4, ID_STATICTEXT13, _("Service Pack:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer27->Add(itemStaticText28, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer27->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 7);

    mp_servicePackLbl = new wxTextCtrl( itemPanel4, ID_TEXTCTRL4, _("SERVICE PACK"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer27->Add(mp_servicePackLbl, 1, wxGROW, 5);

    itemBoxSizer27->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel4, _("Operating System"));

    wxPanel* itemPanel32 = new wxPanel( itemNotebook3, ID_PANEL1, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer33 = new wxBoxSizer(wxVERTICAL);
    itemPanel32->SetSizer(itemBoxSizer33);

    wxNotebook* itemNotebook34 = new wxNotebook( itemPanel32, ID_NOTEBOOK2, wxDefaultPosition, wxSize(200, 200), wxNB_DEFAULT|wxNB_TOP );

    wxPanel* itemPanel35 = new wxPanel( itemNotebook34, ID_PANEL2, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer36 = new wxBoxSizer(wxVERTICAL);
    itemPanel35->SetSizer(itemBoxSizer36);

    itemBoxSizer36->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer38 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer38, 0, wxGROW, 5);
    itemBoxSizer38->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText40 = new wxStaticText( itemPanel35, ID_STATICTEXT15, _("CPU Brand:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer38->Add(itemStaticText40, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer38->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 32);

    mp_cpuBrandLbl = new wxTextCtrl( itemPanel35, ID_TEXTCTRL5, _("CPU BRAND"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer38->Add(mp_cpuBrandLbl, 1, wxGROW, 5);

    itemBoxSizer38->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer44 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer44, 0, wxGROW, 5);
    itemBoxSizer44->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText46 = new wxStaticText( itemPanel35, ID_STATICTEXT17, _("CPU Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer44->Add(itemStaticText46, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer44->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 30);

    mp_cpuSpeedLbl = new wxTextCtrl( itemPanel35, ID_TEXTCTRL6, _("CPU SPEED"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer44->Add(mp_cpuSpeedLbl, 1, wxGROW, 5);

    itemBoxSizer44->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer50 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer50, 0, wxGROW, 5);
    itemBoxSizer50->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText52 = new wxStaticText( itemPanel35, ID_STATICTEXT18, _("Number of CPUs:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer50->Add(itemStaticText52, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer50->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_cpuNumLbl = new wxTextCtrl( itemPanel35, ID_TEXTCTRL7, _("NUMBER OF CPUS"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer50->Add(mp_cpuNumLbl, 1, wxGROW, 5);

    itemBoxSizer50->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer56 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer56, 0, wxGROW, 5);
    itemBoxSizer56->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText58 = new wxStaticText( itemPanel35, ID_STATICTEXT19, _("CPU Family:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer56->Add(itemStaticText58, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer56->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 30);

    mp_cpuFamilyLbl = new wxTextCtrl( itemPanel35, ID_TEXTCTRL8, _("CPU FAMILY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer56->Add(mp_cpuFamilyLbl, 1, wxGROW, 5);

    itemBoxSizer56->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer62 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer62, 0, wxGROW, 5);
    itemBoxSizer62->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText64 = new wxStaticText( itemPanel35, ID_STATICTEXT21, _("CPU Model:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer62->Add(itemStaticText64, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer62->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 32);

    mp_cpuModelLbl = new wxTextCtrl( itemPanel35, ID_TEXTCTRL9, _("CPU MODEL"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer62->Add(mp_cpuModelLbl, 1, wxGROW, 5);

    itemBoxSizer62->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer68 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer36->Add(itemBoxSizer68, 0, wxGROW, 5);
    itemBoxSizer68->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText70 = new wxStaticText( itemPanel35, ID_STATICTEXT24, _("CPU Stepping:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer68->Add(itemStaticText70, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer68->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 18);

    mp_cpuSteppingLbl = new wxTextCtrl( itemPanel35, ID_TEXTCTRL10, _("CPU STEPPING"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer68->Add(mp_cpuSteppingLbl, 1, wxGROW, 5);

    itemBoxSizer68->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    itemNotebook34->AddPage(itemPanel35, _("General Info"));

    wxPanel* itemPanel74 = new wxPanel( itemNotebook34, ID_PANEL3, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer75 = new wxBoxSizer(wxVERTICAL);
    itemPanel74->SetSizer(itemBoxSizer75);

    itemBoxSizer75->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer77 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer77, 0, wxGROW|wxALL, 1);
    itemBoxSizer77->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText79 = new wxStaticText( itemPanel74, ID_STATICTEXT25, _("MMX:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer77->Add(itemStaticText79, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer77->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 43);

    mp_mmxLbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL11, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer77->Add(mp_mmxLbl, 1, wxGROW, 5);

    itemBoxSizer77->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer83 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer83, 0, wxGROW|wxALL, 1);
    itemBoxSizer83->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText85 = new wxStaticText( itemPanel74, ID_STATICTEXT26, _("MMX Ext.:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer83->Add(itemStaticText85, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer83->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 20);

    mp_mmxExtLbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL12, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer83->Add(mp_mmxExtLbl, 1, wxGROW, 5);

    itemBoxSizer83->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer89 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer89, 0, wxGROW|wxALL, 1);
    itemBoxSizer89->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText91 = new wxStaticText( itemPanel74, ID_STATICTEXT28, _("3D Now!:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer89->Add(itemStaticText91, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer89->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 24);

    mp_3dnowLbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL13, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer89->Add(mp_3dnowLbl, 1, wxGROW, 5);

    itemBoxSizer89->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer95 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer95, 0, wxGROW|wxALL, 1);
    itemBoxSizer95->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText97 = new wxStaticText( itemPanel74, ID_STATICTEXT32, _("3D Now! Ext:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer95->Add(itemStaticText97, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer95->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_3dnowExtLbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL14, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer95->Add(mp_3dnowExtLbl, 1, wxGROW, 5);

    itemBoxSizer95->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer101 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer101, 0, wxGROW|wxALL, 1);
    itemBoxSizer101->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText103 = new wxStaticText( itemPanel74, ID_STATICTEXT34, _("SSE:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer101->Add(itemStaticText103, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer101->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 47);

    mp_sseLbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL15, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer101->Add(mp_sseLbl, 1, wxALIGN_CENTER_VERTICAL, 5);

    itemBoxSizer101->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer107 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer107, 0, wxGROW|wxALL, 1);
    itemBoxSizer107->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText109 = new wxStaticText( itemPanel74, ID_STATICTEXT36, _("SSE2:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer107->Add(itemStaticText109, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer107->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 41);

    mp_sse2Lbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL16, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer107->Add(mp_sse2Lbl, 1, wxGROW, 5);

    itemBoxSizer107->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer113 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer113, 0, wxGROW|wxALL, 1);
    itemBoxSizer113->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText115 = new wxStaticText( itemPanel74, ID_STATICTEXT39, _("AltiVec:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer113->Add(itemStaticText115, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer113->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 33);

    mp_altiVecLbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL17, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer113->Add(mp_altiVecLbl, 1, wxALIGN_CENTER_VERTICAL, 5);

    itemBoxSizer113->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer119 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer75->Add(itemBoxSizer119, 0, wxGROW|wxALL, 1);
    itemBoxSizer119->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText121 = new wxStaticText( itemPanel74, ID_STATICTEXT41, _("RDTSC:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer119->Add(itemStaticText121, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer119->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 32);

    mp_rdtscLbl = new wxTextCtrl( itemPanel74, ID_TEXTCTRL18, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer119->Add(mp_rdtscLbl, 1, wxGROW, 5);

    itemBoxSizer119->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    itemNotebook34->AddPage(itemPanel74, _("CPU Extensions"));

    wxPanel* itemPanel125 = new wxPanel( itemNotebook34, ID_PANEL4, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer126 = new wxBoxSizer(wxVERTICAL);
    itemPanel125->SetSizer(itemBoxSizer126);

    itemBoxSizer126->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxGridSizer* itemGridSizer128 = new wxGridSizer(12, 2, 0, 0);
    itemBoxSizer126->Add(itemGridSizer128, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    wxBoxSizer* itemBoxSizer129 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer129, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText130 = new wxStaticText( itemPanel125, ID_STATICTEXT42, _("FPU:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer129->Add(itemStaticText130, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer129->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 14);

    mp_FPULbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL19, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer129->Add(mp_FPULbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer133 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer133, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText134 = new wxStaticText( itemPanel125, ID_STATICTEXT44, _("PGE:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer133->Add(itemStaticText134, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer133->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 29);

    mp_PGELbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL20, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer133->Add(mp_PGELbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer137 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer137, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText138 = new wxStaticText( itemPanel125, ID_STATICTEXT46, _("VME:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer137->Add(itemStaticText138, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer137->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 12);

    mp_VMELbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL21, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer137->Add(mp_VMELbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer141 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer141, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText142 = new wxStaticText( itemPanel125, ID_STATICTEXT48, _("MCA:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer141->Add(itemStaticText142, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer141->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 26);

    mp_MCALbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL22, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer141->Add(mp_MCALbl, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer145 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer145, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText146 = new wxStaticText( itemPanel125, ID_STATICTEXT50, _("DE:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer145->Add(itemStaticText146, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer145->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 20);

    mp_DELbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL23, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer145->Add(mp_DELbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer149 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer149, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText150 = new wxStaticText( itemPanel125, ID_STATICTEXT52, _("CMOV:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer149->Add(itemStaticText150, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer149->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 19);

    mp_CMOVLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL24, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer149->Add(mp_CMOVLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer153 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer153, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText154 = new wxStaticText( itemPanel125, ID_STATICTEXT54, _("PSE:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer153->Add(itemStaticText154, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer153->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 15);

    mp_PSELbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL25, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer153->Add(mp_PSELbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer157 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer157, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText158 = new wxStaticText( itemPanel125, ID_STATICTEXT56, _("PAT:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer157->Add(itemStaticText158, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer157->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 29);

    mp_PATLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL26, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer157->Add(mp_PATLbl, 1, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer161 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer161, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText162 = new wxStaticText( itemPanel125, ID_STATICTEXT59, _("TSC:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer161->Add(itemStaticText162, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer161->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 14);

    mp_TSCLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL27, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer161->Add(mp_TSCLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer165 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer165, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText166 = new wxStaticText( itemPanel125, ID_STATICTEXT61, _("PSE36:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer165->Add(itemStaticText166, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer165->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 18);

    mp_PSE36Lbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL28, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer165->Add(mp_PSE36Lbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer169 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer169, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText170 = new wxStaticText( itemPanel125, ID_STATICTEXT62, _("MSR:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer169->Add(itemStaticText170, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer169->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 12);

    mp_MSRLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL29, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer169->Add(mp_MSRLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer173 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer173, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText174 = new wxStaticText( itemPanel125, ID_STATICTEXT63, _("PSNUM:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer173->Add(itemStaticText174, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer173->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 14);

    mp_PSNUMLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL30, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer173->Add(mp_PSNUMLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer177 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer177, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText178 = new wxStaticText( itemPanel125, ID_STATICTEXT66, _("PAE:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer177->Add(itemStaticText178, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer177->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 14);

    mp_PAELbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL31, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer177->Add(mp_PAELbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer181 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer181, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText182 = new wxStaticText( itemPanel125, ID_STATICTEXT67, _("CLFLUSH:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer181->Add(itemStaticText182, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer181->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_CLFLUSHLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL32, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer181->Add(mp_CLFLUSHLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer185 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer185, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText186 = new wxStaticText( itemPanel125, ID_STATICTEXT71, _("MCE:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer185->Add(itemStaticText186, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer185->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 12);

    mp_MCELbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL33, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer185->Add(mp_MCELbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer189 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer189, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText190 = new wxStaticText( itemPanel125, ID_STATICTEXT73, _("DTS:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer189->Add(itemStaticText190, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer189->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 29);

    mp_DTSLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL34, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer189->Add(mp_DTSLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer193 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer193, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText194 = new wxStaticText( itemPanel125, ID_STATICTEXT75, _("CX8"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer193->Add(itemStaticText194, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer193->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 18);

    mp_CX8Lbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL35, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer193->Add(mp_CX8Lbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer197 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer197, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText198 = new wxStaticText( itemPanel125, ID_STATICTEXT77, _("ACPI:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer197->Add(itemStaticText198, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer197->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 24);

    mp_ACPILbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL36, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer197->Add(mp_ACPILbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer201 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer201, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText202 = new wxStaticText( itemPanel125, ID_STATICTEXT78, _("APIC:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer201->Add(itemStaticText202, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer201->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 9);

    mp_APICLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL37, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer201->Add(mp_APICLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer205 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer205, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText206 = new wxStaticText( itemPanel125, ID_STATICTEXT81, _("FXSR:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer205->Add(itemStaticText206, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer205->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 23);

    mp_FXSRLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL38, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer205->Add(mp_FXSRLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer209 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer209, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText210 = new wxStaticText( itemPanel125, ID_STATICTEXT83, _("SEP:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer209->Add(itemStaticText210, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer209->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 15);

    mp_SEPLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL39, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer209->Add(mp_SEPLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer213 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer213, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText214 = new wxStaticText( itemPanel125, ID_STATICTEXT84, _("SS:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer213->Add(itemStaticText214, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer213->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 36);

    mp_SSLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL40, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer213->Add(mp_SSLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer217 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer217, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText218 = new wxStaticText( itemPanel125, ID_STATICTEXT86, _("MTRR:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer217->Add(itemStaticText218, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer217->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_MTRRLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL41, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer217->Add(mp_MTRRLbl, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer221 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer128->Add(itemBoxSizer221, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 1);
    wxStaticText* itemStaticText222 = new wxStaticText( itemPanel125, ID_STATICTEXT88, _("TM:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer221->Add(itemStaticText222, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer221->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 34);

    mp_TMLbl = new wxTextCtrl( itemPanel125, ID_TEXTCTRL42, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer221->Add(mp_TMLbl, 1, wxGROW, 5);

    itemNotebook34->AddPage(itemPanel125, _("More CPU Extensions"));

    itemBoxSizer33->Add(itemNotebook34, 1, wxGROW, 5);

    itemNotebook3->AddPage(itemPanel32, _("CPU Details"));

    wxPanel* itemPanel225 = new wxPanel( itemNotebook3, ID_PANEL10, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer226 = new wxBoxSizer(wxVERTICAL);
    itemPanel225->SetSizer(itemBoxSizer226);

    itemBoxSizer226->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer228 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer226->Add(itemBoxSizer228, 0, wxGROW|wxALL, 1);
    itemBoxSizer228->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText230 = new wxStaticText( itemPanel225, ID_STATICTEXT80, _("Total Memory:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer228->Add(itemStaticText230, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer228->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_totalMemoryLbl = new wxTextCtrl( itemPanel225, ID_TEXTCTRL43, _("MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer228->Add(mp_totalMemoryLbl, 1, wxGROW, 5);

    itemBoxSizer228->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer234 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer226->Add(itemBoxSizer234, 0, wxGROW|wxALL, 1);
    itemBoxSizer234->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText236 = new wxStaticText( itemPanel225, ID_STATICTEXT74, _("Free Memory:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer234->Add(itemStaticText236, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer234->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 7);

    mp_freeMemoryLbl = new wxTextCtrl( itemPanel225, ID_TEXTCTRL44, _("MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer234->Add(mp_freeMemoryLbl, 1, wxGROW, 5);

    itemBoxSizer234->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer240 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer226->Add(itemBoxSizer240, 0, wxGROW|wxALL, 1);
    itemBoxSizer240->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText242 = new wxStaticText( itemPanel225, ID_STATICTEXT70, _("Total Page:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer240->Add(itemStaticText242, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer240->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 19);

    mp_totalPageLbl = new wxTextCtrl( itemPanel225, ID_TEXTCTRL45, _("MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer240->Add(mp_totalPageLbl, 1, wxGROW, 5);

    itemBoxSizer240->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer246 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer226->Add(itemBoxSizer246, 0, wxGROW|wxALL, 1);
    itemBoxSizer246->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText248 = new wxStaticText( itemPanel225, ID_STATICTEXT76, _("Free Page:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer246->Add(itemStaticText248, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer246->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 21);

    mp_freePageLbl = new wxTextCtrl( itemPanel225, ID_TEXTCTRL46, _("MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer246->Add(mp_freePageLbl, 1, wxGROW, 5);

    itemBoxSizer246->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer252 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer226->Add(itemBoxSizer252, 0, wxGROW|wxALL, 1);
    itemBoxSizer252->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText254 = new wxStaticText( itemPanel225, ID_STATICTEXT72, _("Total Virtual:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer252->Add(itemStaticText254, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer252->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 13);

    mp_totalVirtualLbl = new wxTextCtrl( itemPanel225, ID_TEXTCTRL47, _("MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer252->Add(mp_totalVirtualLbl, 1, wxGROW, 5);

    itemBoxSizer252->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer258 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer226->Add(itemBoxSizer258, 0, wxGROW|wxALL, 1);
    itemBoxSizer258->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText260 = new wxStaticText( itemPanel225, ID_STATICTEXT82, _("Free Virtual:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer258->Add(itemStaticText260, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer258->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 15);

    mp_freeVirtualLbl = new wxTextCtrl( itemPanel225, ID_TEXTCTRL48, _("MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer258->Add(mp_freeVirtualLbl, 1, wxGROW, 5);

    itemBoxSizer258->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel225, _("Memory"));

    wxPanel* itemPanel264 = new wxPanel( itemNotebook3, ID_PANEL11, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer265 = new wxBoxSizer(wxVERTICAL);
    itemPanel264->SetSizer(itemBoxSizer265);

    wxNotebook* itemNotebook266 = new wxNotebook( itemPanel264, ID_NOTEBOOK1, wxDefaultPosition, wxSize(200, 200), wxNB_DEFAULT|wxNB_TOP );

    wxPanel* itemPanel267 = new wxPanel( itemNotebook266, ID_PANEL12, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer268 = new wxBoxSizer(wxVERTICAL);
    itemPanel267->SetSizer(itemBoxSizer268);

    itemBoxSizer268->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer270 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer268->Add(itemBoxSizer270, 0, wxGROW|wxALL, 1);
    itemBoxSizer270->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText272 = new wxStaticText( itemPanel267, ID_STATICTEXT90, _("Vender:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer270->Add(itemStaticText272, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer270->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 64);

    mp_venderNameLbl = new wxTextCtrl( itemPanel267, ID_TEXTCTRL99, _("VENDER NAME"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer270->Add(mp_venderNameLbl, 1, wxGROW, 5);

    itemBoxSizer270->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer276 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer268->Add(itemBoxSizer276, 0, wxGROW|wxALL, 1);
    itemBoxSizer276->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText278 = new wxStaticText( itemPanel267, ID_STATICTEXT29, _("Video Card:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer276->Add(itemStaticText278, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer276->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 46);

    mp_videoNameLbl = new wxTextCtrl( itemPanel267, ID_TEXTCTRL49, _("VIDEO CARD NAME"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer276->Add(mp_videoNameLbl, 1, wxGROW, 5);

    itemBoxSizer276->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer282 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer268->Add(itemBoxSizer282, 0, wxGROW|wxALL, 1);
    itemBoxSizer282->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText284 = new wxStaticText( itemPanel267, ID_STATICTEXT31, _("Video Drivers:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer282->Add(itemStaticText284, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer282->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 35);

    mp_videoDriversLbl = new wxTextCtrl( itemPanel267, ID_TEXTCTRL50, _("DRIVER VERSION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer282->Add(mp_videoDriversLbl, 1, wxGROW, 5);

    itemBoxSizer282->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer288 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer268->Add(itemBoxSizer288, 0, wxGROW|wxALL, 1);
    itemBoxSizer288->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText290 = new wxStaticText( itemPanel267, ID_STATICTEXT4, _("Total Video Memory:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer288->Add(itemStaticText290, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer288->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_videoMemoryLbl = new wxTextCtrl( itemPanel267, ID_TEXTCTRL51, _("VIDEO MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer288->Add(mp_videoMemoryLbl, 1, wxGROW, 5);

    itemBoxSizer288->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer294 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer268->Add(itemBoxSizer294, 0, wxGROW|wxALL, 1);
    itemBoxSizer294->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText296 = new wxStaticText( itemPanel267, ID_STATICTEXT58, _("Free Video Memory:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer294->Add(itemStaticText296, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer294->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 7);

    mp_videoMemoryFreeLbl = new wxTextCtrl( itemPanel267, ID_TEXTCTRL52, _("VIDEO MEMORY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer294->Add(mp_videoMemoryFreeLbl, 1, wxGROW, 5);

    itemBoxSizer294->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer300 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer268->Add(itemBoxSizer300, 0, wxGROW|wxALL, 1);
    itemBoxSizer300->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText302 = new wxStaticText( itemPanel267, ID_STATICTEXT60, _("Screen Resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer300->Add(itemStaticText302, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer300->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 13);

    mp_screenResolutionLbl = new wxTextCtrl( itemPanel267, ID_TEXTCTRL53, _("SCREEN RESOLUTION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer300->Add(mp_screenResolutionLbl, 1, wxGROW, 5);

    itemBoxSizer300->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer306 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer268->Add(itemBoxSizer306, 0, wxGROW|wxALL, 1);
    itemBoxSizer306->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText308 = new wxStaticText( itemPanel267, ID_STATICTEXT33, _("Colour Quality:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer306->Add(itemStaticText308, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer306->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 31);

    mp_colourQuality = new wxTextCtrl( itemPanel267, ID_TEXTCTRL54, _("8\\\\16\\\\24\\\\32 bit"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer306->Add(mp_colourQuality, 1, wxGROW, 5);

    itemBoxSizer306->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    itemNotebook266->AddPage(itemPanel267, _("General Info."));

    wxPanel* itemPanel312 = new wxPanel( itemNotebook266, ID_PANEL13, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer313 = new wxBoxSizer(wxVERTICAL);
    itemPanel312->SetSizer(itemBoxSizer313);

    itemBoxSizer313->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer315 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer315, 0, wxGROW|wxALL, 1);
    itemBoxSizer315->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText317 = new wxStaticText( itemPanel312, ID_STATICTEXT92, _("2D Surfaces:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer315->Add(itemStaticText317, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer315->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 131);

    mp_surfacesLbl = new wxTextCtrl( itemPanel312, ID_TEXTCTRL55, _("HARDWARE\\\\SOFTWARE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer315->Add(mp_surfacesLbl, 1, wxGROW, 5);

    itemBoxSizer315->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer321 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer321, 0, wxGROW|wxALL, 1);
    itemBoxSizer321->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText323 = new wxStaticText( itemPanel312, ID_STATICTEXT94, _("Hardware to Hardware Blits:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer321->Add(itemStaticText323, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer321->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 57);

    mp_hardtohardBlits = new wxTextCtrl( itemPanel312, ID_TEXTCTRL56, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer321->Add(mp_hardtohardBlits, 1, wxGROW, 5);

    itemBoxSizer321->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer327 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer327, 0, wxGROW|wxALL, 1);
    itemBoxSizer327->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText329 = new wxStaticText( itemPanel312, ID_STATICTEXT16, _("Hardware to Hardware ColourKey Blits:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer327->Add(itemStaticText329, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer327->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_hardtohardColourLbl = new wxTextCtrl( itemPanel312, ID_TEXTCTRL57, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer327->Add(mp_hardtohardColourLbl, 1, wxGROW, 5);

    itemBoxSizer327->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer333 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer333, 0, wxGROW|wxALL, 1);
    itemBoxSizer333->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText335 = new wxStaticText( itemPanel312, ID_STATICTEXT14, _("Hardware to Hardware Alpha Blits:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer333->Add(itemStaticText335, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer333->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 27);

    mp_hardtohardAlphaLbl = new wxTextCtrl( itemPanel312, ID_TEXTCTRL58, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer333->Add(mp_hardtohardAlphaLbl, 1, wxGROW, 5);

    itemBoxSizer333->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer339 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer339, 0, wxGROW|wxALL, 1);
    itemBoxSizer339->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText341 = new wxStaticText( itemPanel312, ID_STATICTEXT12, _("Software to Hardware Blits:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer339->Add(itemStaticText341, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer339->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 60);

    mp_softtohardBlitsLbl = new wxTextCtrl( itemPanel312, ID_TEXTCTRL59, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer339->Add(mp_softtohardBlitsLbl, 1, wxGROW, 5);

    itemBoxSizer339->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer345 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer345, 0, wxGROW|wxALL, 1);
    itemBoxSizer345->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText347 = new wxStaticText( itemPanel312, ID_STATICTEXT10, _("Software to Hardware ColourKey Blits:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer345->Add(itemStaticText347, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer345->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 8);

    mp_softtohardColourLbl = new wxTextCtrl( itemPanel312, ID_TEXTCTRL60, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer345->Add(mp_softtohardColourLbl, 1, wxGROW, 5);

    itemBoxSizer345->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer351 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer351, 0, wxGROW|wxALL, 1);
    itemBoxSizer351->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText353 = new wxStaticText( itemPanel312, ID_STATICTEXT8, _("Software to Hardware Alpha Blits:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer351->Add(itemStaticText353, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer351->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 30);

    mp_softtohardApha = new wxTextCtrl( itemPanel312, ID_TEXTCTRL61, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer351->Add(mp_softtohardApha, 1, wxGROW, 5);

    itemBoxSizer351->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer357 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer313->Add(itemBoxSizer357, 0, wxGROW|wxALL, 1);
    itemBoxSizer357->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText359 = new wxStaticText( itemPanel312, ID_STATICTEXT6, _("Accelerated Colour Fills:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer357->Add(itemStaticText359, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer357->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 78);

    mp_accelerColourLbl = new wxTextCtrl( itemPanel312, ID_TEXTCTRL62, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer357->Add(mp_accelerColourLbl, 1, wxGROW, 5);

    itemBoxSizer357->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL, 5);

    itemNotebook266->AddPage(itemPanel312, _("2D Card Info."));

    wxPanel* itemPanel363 = new wxPanel( itemNotebook266, ID_PANEL14, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer364 = new wxBoxSizer(wxVERTICAL);
    itemPanel363->SetSizer(itemBoxSizer364);

    wxNotebook* itemNotebook365 = new wxNotebook( itemPanel363, ID_NOTEBOOK4, wxDefaultPosition, wxSize(200, 200), wxNB_DEFAULT|wxNB_TOP );

    wxPanel* itemPanel366 = new wxPanel( itemNotebook365, ID_PANEL15, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer367 = new wxBoxSizer(wxVERTICAL);
    itemPanel366->SetSizer(itemBoxSizer367);

    wxBoxSizer* itemBoxSizer368 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer367->Add(itemBoxSizer368, 0, wxGROW|wxRIGHT|wxTOP|wxBOTTOM, 5);
    wxStaticText* itemStaticText369 = new wxStaticText( itemPanel366, wxID_STATIC, _("OpenGL Version:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer368->Add(itemStaticText369, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    mp_openGLVersionLbl = new wxTextCtrl( itemPanel366, ID_TEXTCTRL100, _("OPENGL VERSION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer368->Add(mp_openGLVersionLbl, 1, wxGROW, 5);

    wxStaticText* itemStaticText371 = new wxStaticText( itemPanel366, wxID_STATIC, _("OpenGL Extentions:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer367->Add(itemStaticText371, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    wxArrayString mp_openGLExtentionsListStrings;
    mp_openGLExtentionsList = new wxListBox( itemPanel366, ID_LISTBOX, wxDefaultPosition, wxDefaultSize, mp_openGLExtentionsListStrings, 0 );
    itemBoxSizer367->Add(mp_openGLExtentionsList, 1, wxGROW, 5);

    itemNotebook365->AddPage(itemPanel366, _("OpenGL Info."));

    wxPanel* itemPanel373 = new wxPanel( itemNotebook365, ID_PANEL16, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );

    itemNotebook365->AddPage(itemPanel373, _("DirectX Info."));

    itemBoxSizer364->Add(itemNotebook365, 1, wxGROW, 5);

    itemNotebook266->AddPage(itemPanel363, _("3D Card Info."));

    itemBoxSizer265->Add(itemNotebook266, 1, wxGROW, 5);

    itemNotebook3->AddPage(itemPanel264, _("Video Card Info."));

    wxPanel* itemPanel374 = new wxPanel( itemNotebook3, ID_PANEL17, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer375 = new wxBoxSizer(wxVERTICAL);
    itemPanel374->SetSizer(itemBoxSizer375);

    itemBoxSizer375->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer377 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer375->Add(itemBoxSizer377, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText378 = new wxStaticText( itemPanel374, ID_STATICTEXT35, _("Installed:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer377->Add(itemStaticText378, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer377->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 58);

    mp_installedSoundLbl = new wxTextCtrl( itemPanel374, ID_TEXTCTRL63, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer377->Add(mp_installedSoundLbl, 1, wxGROW, 5);

    itemBoxSizer377->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer382 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer375->Add(itemBoxSizer382, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText383 = new wxStaticText( itemPanel374, ID_STATICTEXT37, _("Volume Control:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer382->Add(itemStaticText383, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer382->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 26);

    mp_volumeControlLbl = new wxTextCtrl( itemPanel374, ID_TEXTCTRL64, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer382->Add(mp_volumeControlLbl, 1, wxGROW, 5);

    itemBoxSizer382->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer387 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer375->Add(itemBoxSizer387, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText388 = new wxStaticText( itemPanel374, ID_STATICTEXT96, _("Separate RL VolCtrl:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer387->Add(itemStaticText388, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer387->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 6);

    mp_RLVolumeLbl = new wxTextCtrl( itemPanel374, ID_TEXTCTRL65, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer387->Add(mp_RLVolumeLbl, 1, wxGROW, 5);

    itemBoxSizer387->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer392 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer375->Add(itemBoxSizer392, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText393 = new wxStaticText( itemPanel374, ID_STATICTEXT98, _("Company Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer392->Add(itemStaticText393, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer392->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 24);

    mp_companyNameLbl = new wxTextCtrl( itemPanel374, ID_TEXTCTRL66, _("COMPANY NAME"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer392->Add(mp_companyNameLbl, 1, wxGROW, 5);

    itemBoxSizer392->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer397 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer375->Add(itemBoxSizer397, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText398 = new wxStaticText( itemPanel374, ID_STATICTEXT100, _("Product Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer397->Add(itemStaticText398, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer397->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 32);

    mp_productNameLbl = new wxTextCtrl( itemPanel374, ID_TEXTCTRL67, _("PRODUCT NAME"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer397->Add(mp_productNameLbl, 1, wxGROW, 5);

    itemBoxSizer397->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel374, _("Sound Card Info."));

    wxPanel* itemPanel402 = new wxPanel( itemNotebook3, ID_PANEL18, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer403 = new wxBoxSizer(wxVERTICAL);
    itemPanel402->SetSizer(itemBoxSizer403);

    mp_hardDriveNoteBook = new wxNotebook( itemPanel402, ID_NOTEBOOK5, wxDefaultPosition, wxDefaultSize, wxNB_DEFAULT|wxNB_TOP );

    itemBoxSizer403->Add(mp_hardDriveNoteBook, 1, wxGROW, 5);

    itemNotebook3->AddPage(itemPanel402, _("Hard Drive Info."));

    wxPanel* itemPanel405 = new wxPanel( itemNotebook3, ID_PANEL19, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer406 = new wxBoxSizer(wxVERTICAL);
    itemPanel405->SetSizer(itemBoxSizer406);

    wxNotebook* itemNotebook407 = new wxNotebook( itemPanel405, ID_NOTEBOOK3, wxDefaultPosition, wxSize(200, 200), wxNB_DEFAULT|wxNB_TOP );

    wxPanel* itemPanel408 = new wxPanel( itemNotebook407, ID_PANEL20, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer409 = new wxBoxSizer(wxVERTICAL);
    itemPanel408->SetSizer(itemBoxSizer409);

    itemBoxSizer409->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer411 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer409->Add(itemBoxSizer411, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText412 = new wxStaticText( itemPanel408, ID_STATICTEXT102, _("Present:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer411->Add(itemStaticText412, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer411->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 23);

    mp_presentLbl = new wxTextCtrl( itemPanel408, ID_TEXTCTRL68, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer411->Add(mp_presentLbl, 1, wxGROW, 5);

    itemBoxSizer411->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer416 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer409->Add(itemBoxSizer416, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText417 = new wxStaticText( itemPanel408, ID_STATICTEXT104, _("Button swapped:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer416->Add(itemStaticText417, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer416->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_btnSwappedLbl = new wxTextCtrl( itemPanel408, ID_TEXTCTRL69, _("YES\\\\NO"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer416->Add(mp_btnSwappedLbl, 1, wxGROW, 5);

    itemBoxSizer416->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer421 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer409->Add(itemBoxSizer421, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText422 = new wxStaticText( itemPanel408, ID_STATICTEXT106, _("Threshold X:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer421->Add(itemStaticText422, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer421->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 13);

    mp_thresholdXLbl = new wxTextCtrl( itemPanel408, ID_TEXTCTRL70, _("THRESHOLD X"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer421->Add(mp_thresholdXLbl, 1, wxGROW, 5);

    itemBoxSizer421->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer426 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer409->Add(itemBoxSizer426, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText427 = new wxStaticText( itemPanel408, ID_STATICTEXT108, _("Threshold Y:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer426->Add(itemStaticText427, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer426->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 13);

    mp_thresholdYLbl = new wxTextCtrl( itemPanel408, ID_TEXTCTRL71, _("THRESHOLD Y"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer426->Add(mp_thresholdYLbl, 1, wxGROW, 5);

    itemBoxSizer426->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer431 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer409->Add(itemBoxSizer431, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText432 = new wxStaticText( itemPanel408, ID_STATICTEXT110, _("Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer431->Add(itemStaticText432, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer431->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 26);

    mp_speedLbl = new wxTextCtrl( itemPanel408, ID_TEXTCTRL72, _("SPEED"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer431->Add(mp_speedLbl, 1, wxGROW, 5);

    itemBoxSizer431->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook407->AddPage(itemPanel408, _("Mouse"));

    wxPanel* itemPanel436 = new wxPanel( itemNotebook407, ID_PANEL21, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer437 = new wxBoxSizer(wxVERTICAL);
    itemPanel436->SetSizer(itemBoxSizer437);

    itemBoxSizer437->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer439 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer437->Add(itemBoxSizer439, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText440 = new wxStaticText( itemPanel436, ID_STATICTEXT112, _("Repeat:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer439->Add(itemStaticText440, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer439->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_repeatLbl = new wxTextCtrl( itemPanel436, ID_TEXTCTRL73, _("REPEAT"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer439->Add(mp_repeatLbl, 1, wxGROW, 5);

    itemBoxSizer439->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer444 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer437->Add(itemBoxSizer444, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText445 = new wxStaticText( itemPanel436, ID_STATICTEXT114, _("Delay:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer444->Add(itemStaticText445, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer444->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 13);

    mp_delayLbl = new wxTextCtrl( itemPanel436, ID_TEXTCTRL74, _("DELAY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer444->Add(mp_delayLbl, 1, wxGROW, 5);

    itemBoxSizer444->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook407->AddPage(itemPanel436, _("Keyboard"));

    wxPanel* itemPanel449 = new wxPanel( itemNotebook407, ID_PANEL22, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer450 = new wxBoxSizer(wxVERTICAL);
    itemPanel449->SetSizer(itemBoxSizer450);

    itemBoxSizer450->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer452 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer450->Add(itemBoxSizer452, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText453 = new wxStaticText( itemPanel449, ID_STATICTEXT40, _("Number of Joystick:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer452->Add(itemStaticText453, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer452->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_joystickNumber = new wxTextCtrl( itemPanel449, ID_TEXTCTRL75, _("NUMBER OF JOYSTICKS"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer452->Add(mp_joystickNumber, 1, wxGROW, 5);

    itemBoxSizer452->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook407->AddPage(itemPanel449, _("Joystick"));

    itemBoxSizer406->Add(itemNotebook407, 1, wxGROW, 5);

    itemNotebook3->AddPage(itemPanel405, _("Input Info."));

    wxPanel* itemPanel457 = new wxPanel( itemNotebook3, ID_PANEL23, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer458 = new wxBoxSizer(wxVERTICAL);
    itemPanel457->SetSizer(itemBoxSizer458);

    itemBoxSizer458->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer460 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer460, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText461 = new wxStaticText( itemPanel457, ID_STATICTEXT116, _("Version:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer460->Add(itemStaticText461, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer460->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 47);

    mp_versionLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL76, _("VERSION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer460->Add(mp_versionLbl, 1, wxGROW, 5);

    itemBoxSizer460->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer465 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer465, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText466 = new wxStaticText( itemPanel457, ID_STATICTEXT118, _("Highest Ver:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer465->Add(itemStaticText466, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer465->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 27);

    mp_highestVersionLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL77, _("HIGHEST VERSION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer465->Add(mp_highestVersionLbl, 1, wxGROW, 5);

    itemBoxSizer465->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer470 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer470, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText471 = new wxStaticText( itemPanel457, ID_STATICTEXT120, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer470->Add(itemStaticText471, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer470->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 29);

    mp_descriptionLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL78, _("DESCRIPTION"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer470->Add(mp_descriptionLbl, 1, wxGROW, 5);

    itemBoxSizer470->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer475 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer475, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText476 = new wxStaticText( itemPanel457, ID_STATICTEXT122, _("System Status:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer475->Add(itemStaticText476, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer475->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 13);

    mp_systemStatusLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL79, _("SYSTEM STATUS"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer475->Add(mp_systemStatusLbl, 1, wxGROW, 5);

    itemBoxSizer475->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer480 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer480, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText481 = new wxStaticText( itemPanel457, ID_STATICTEXT124, _("Max:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer480->Add(itemStaticText481, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer480->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 62);

    mp_maxLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL80, _("MAX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer480->Add(mp_maxLbl, 1, wxGROW, 5);

    itemBoxSizer480->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer485 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer485, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText486 = new wxStaticText( itemPanel457, ID_STATICTEXT126, _("IP Address:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer485->Add(itemStaticText486, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer485->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 30);

    mp_addressLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL81, _("IP ADDRESS"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer485->Add(mp_addressLbl, 1, wxGROW, 5);

    itemBoxSizer485->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer490 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer490, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText491 = new wxStaticText( itemPanel457, ID_STATICTEXT128, _("Domain Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer490->Add(itemStaticText491, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer490->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 17);

    mp_domainNameLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL82, _("DOMAIN NAME"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer490->Add(mp_domainNameLbl, 1, wxGROW, 5);

    itemBoxSizer490->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer495 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer495, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText496 = new wxStaticText( itemPanel457, ID_STATICTEXT130, _("UDP Max:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer495->Add(itemStaticText496, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer495->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 39);

    mp_UDPLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL83, _("UDP MAX"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer495->Add(mp_UDPLbl, 1, wxGROW, 5);

    itemBoxSizer495->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer500 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer500, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText501 = new wxStaticText( itemPanel457, ID_STATICTEXT131, _("Computer Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer500->Add(itemStaticText501, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer500->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_computerNameLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL84, _("COMPUTER NAME"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer500->Add(mp_computerNameLbl, 1, wxGROW, 5);

    itemBoxSizer500->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer505 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer458->Add(itemBoxSizer505, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText506 = new wxStaticText( itemPanel457, ID_STATICTEXT133, _("User Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer505->Add(itemStaticText506, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer505->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 30);

    mp_userNameLbl = new wxTextCtrl( itemPanel457, ID_TEXTCTRL85, _("USER NAME"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer505->Add(mp_userNameLbl, 1, wxGROW, 5);

    itemBoxSizer505->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel457, _("Socket Info."));

    wxPanel* itemPanel510 = new wxPanel( itemNotebook3, ID_PANEL24, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer511 = new wxBoxSizer(wxVERTICAL);
    itemPanel510->SetSizer(itemBoxSizer511);

    itemBoxSizer511->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer513 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer513, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText514 = new wxStaticText( itemPanel510, ID_STATICTEXT135, _("Code Page:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer513->Add(itemStaticText514, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer513->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 56);

    mp_codePageLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL86, _("CODE PAGE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer513->Add(mp_codePageLbl, 1, wxGROW, 5);

    itemBoxSizer513->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer518 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer518, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText519 = new wxStaticText( itemPanel510, ID_STATICTEXT137, _("Calendar Type:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer518->Add(itemStaticText519, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer518->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 38);

    mp_calenderTypeLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL87, _("CALENDAR TYPE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer518->Add(mp_calenderTypeLbl, 1, wxGROW, 5);

    itemBoxSizer518->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer523 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer523, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText524 = new wxStaticText( itemPanel510, ID_STATICTEXT139, _("OEM Code Page:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer523->Add(itemStaticText524, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer523->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 31);

    mp_oemCodePageLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL88, _("OEM CODE PAGE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer523->Add(mp_oemCodePageLbl, 1, wxGROW, 5);

    itemBoxSizer523->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer528 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer528, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText529 = new wxStaticText( itemPanel510, ID_STATICTEXT141, _("Language:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer528->Add(itemStaticText529, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer528->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 61);

    mp_languageLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL89, _("LANGUAGE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer528->Add(mp_languageLbl, 1, wxGROW, 5);

    itemBoxSizer528->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer533 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer533, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText534 = new wxStaticText( itemPanel510, ID_STATICTEXT143, _("Date Format:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer533->Add(itemStaticText534, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer533->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 48);

    mp_dateFormatLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL90, _("DATE FORMAT"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer533->Add(mp_dateFormatLbl, 1, wxGROW, 5);

    itemBoxSizer533->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer538 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer538, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText539 = new wxStaticText( itemPanel510, ID_STATICTEXT145, _("Country:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer538->Add(itemStaticText539, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer538->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 69);

    mp_countryLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL91, _("COUNTRY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer538->Add(mp_countryLbl, 1, wxGROW, 5);

    itemBoxSizer538->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer543 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer543, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText544 = new wxStaticText( itemPanel510, ID_STATICTEXT147, _("Country Code:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer543->Add(itemStaticText544, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer543->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 41);

    mp_countryCodeLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL92, _("COUNTRY CODE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer543->Add(mp_countryCodeLbl, 1, wxGROW, 5);

    itemBoxSizer543->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer548 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer548, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText549 = new wxStaticText( itemPanel510, ID_STATICTEXT149, _("Time Format:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer548->Add(itemStaticText549, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer548->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 49);

    mp_timeFormatLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL93, _("TIME FORMAT"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer548->Add(mp_timeFormatLbl, 1, wxGROW, 5);

    itemBoxSizer548->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer553 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer553, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText554 = new wxStaticText( itemPanel510, ID_STATICTEXT151, _("Currency:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer553->Add(itemStaticText554, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer553->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 64);

    mp_currencyLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL94, _("CURRENCY"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer553->Add(mp_currencyLbl, 1, wxGROW, 5);

    itemBoxSizer553->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer558 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer558, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText559 = new wxStaticText( itemPanel510, ID_STATICTEXT153, _("Time Format Specifier:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer558->Add(itemStaticText559, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer558->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    mp_timeFormatSpecifierLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL95, _("TIME FORMAT SPECIFIER"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer558->Add(mp_timeFormatSpecifierLbl, 1, wxGROW, 5);

    itemBoxSizer558->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer563 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer563, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText564 = new wxStaticText( itemPanel510, ID_STATICTEXT155, _("Local Language:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer563->Add(itemStaticText564, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer563->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 34);

    mp_localLanguageLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL96, _("LOCAL LANGUAGE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer563->Add(mp_localLanguageLbl, 1, wxGROW, 5);

    itemBoxSizer563->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer568 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer511->Add(itemBoxSizer568, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText569 = new wxStaticText( itemPanel510, ID_STATICTEXT157, _("Time Zone:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer568->Add(itemStaticText569, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    itemBoxSizer568->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 59);

    mp_timeZoneLbl = new wxTextCtrl( itemPanel510, ID_TEXTCTRL97, _("TIME ZONE"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer568->Add(mp_timeZoneLbl, 1, wxGROW, 5);

    itemBoxSizer568->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel510, _("Locale Info."));

    wxPanel* itemPanel573 = new wxPanel( itemNotebook3, ID_PANEL25, wxDefaultPosition, wxSize(100, 80), wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer574 = new wxBoxSizer(wxVERTICAL);
    itemPanel573->SetSizer(itemBoxSizer574);

    itemBoxSizer574->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer576 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer574->Add(itemBoxSizer576, 0, wxGROW|wxALL, 1);
    wxStaticText* itemStaticText577 = new wxStaticText( itemPanel573, ID_STATICTEXT38, _("Number of CD Drives:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer576->Add(itemStaticText577, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    mp_cdDriveCountLbl = new wxTextCtrl( itemPanel573, ID_TEXTCTRL98, _("NUMBER OF CD DRIVES"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer576->Add(mp_cdDriveCountLbl, 1, wxGROW, 5);

    itemBoxSizer576->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel573, _("Misc. Info."));

    itemBoxSizer2->Add(itemNotebook3, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer580 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer580, 0, wxALIGN_RIGHT|wxLEFT|wxRIGHT, 5);

    mp_closeButton = new wxButton( itemDialog1, ID_BUTTON, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer580->Add(mp_closeButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end cSystemDetails content construction
}

/*!
 * wxEVT_CLOSE_WINDOW event handler for ID_DIALOG_cSystemDetails
 */

void cSystemDetails::OnCloseWindow( wxCloseEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1_cSystemDetails
 */

void cSystemDetails::CloseClick( wxCommandEvent& event )
{
    // Insert custom code here
	Close(TRUE);
    event.Skip();
}

/*!
 * Should we show tooltips?
 */

bool cSystemDetails::ShowToolTips()
{
    return TRUE;
}

/*!
 * Get bitmap resources
 */

wxBitmap cSystemDetails::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin cSystemDetails bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end cSystemDetails bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon cSystemDetails::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin cSystemDetails icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end cSystemDetails icon retrieval
}
