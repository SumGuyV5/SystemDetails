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
#include "Mouse.hpp"

#ifdef __SysInfo__		///Tells the complier this is Windows only code
#	include "SysInfo.h"	///Used for System Information DLL by Paul Wendt.
#endif

#ifdef __SysInfo__
	extern SysInfo sysinfo;
#endif

namespace System_Information 
{
	namespace Input_Info
	{
		namespace Mouse
		{
			///SysInfo
			const wxString Present()
			{
				#ifdef __SysInfo__
					if (sysinfo.getMousePresent() == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString ButtonSwapped()
			{
				#ifdef __SysInfo__
					if (sysinfo.getMouseSwapped() == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString ThresholdX()
			{
				#ifdef __SysInfo__
					return wxString::Format("%ld", sysinfo.getMouseThresholdX());	
				#else
					return "UNKONW";
				#endif
			}

			///SysInfo
			const wxString ThresholdY()
			{
				#ifdef __SysInfo__
					return wxString::Format("%ld", sysinfo.getMouseThresholdY());	
				#else
					return "UNKONW";
				#endif
			}

			///SysInfo
			const wxString Speed()
			{
				#ifdef __SysInfo__
					return wxString::Format("%ld", sysinfo.getMouseSpeed());	
				#else
					return "UNKONW";
				#endif
			}
		}
	}
}
