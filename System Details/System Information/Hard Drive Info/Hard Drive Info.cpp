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
#include "Hard Drive Info.hpp"

#ifdef __SysInfo__		///Tells the complier this is Windows only code
#	include "SysInfo.h"	///Used for System Information DLL by Paul Wendt.
#endif

//extern SysInfo sysinfo;

#ifdef __SysInfo__
extern SysInfo sysinfo;
#endif

#include <vector>

using namespace std;

namespace System_Information 
{
	namespace Hard_Drive_Info
	{
		///SysInfo
		const bool GetHardDriveInfo(wxString& name, wxString& type, wxString& totalspace, wxString& freespace, wxString& filesystemtype)
		{
			bool return_var = false;	///false there is no hard drive.
			
			#ifdef __SysInfo__
				static bool firsttime = true;

				const static vector<DriveStats>& rv_DriveStats = sysinfo.getDriveStats();
				static vector<DriveStats>::const_iterator i;

				if (firsttime == true)
				{
					i = rv_DriveStats.begin();
					firsttime = false;
				}

				if (i == rv_DriveStats.end())
				{
					return_var = false;
					firsttime = true;
				}
				else
				{
					name = i->getName().c_str();
					type = i->getType().c_str();
					totalspace = i->getTotalSpace().c_str();
					freespace = i->getFreeSpace().c_str();
					filesystemtype = i->getFileSystemType().c_str();
					i++;
					return_var = true;
				}
			#endif

			
            return return_var;				
		}
	}
}