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

#include "More CPU Extensions.hpp"

#ifdef __SysInfo__		///Tells the complier this is Windows only code
#	include "SysInfo.h"	///Used for System Information DLL by Paul Wendt.
#endif

#ifdef __SysInfo__
	extern SysInfo sysinfo;
#endif

namespace System_Information 
{
	namespace CPU_Details
	{
		namespace More_CPU_Extensions
		{
			///SysInfo
			const wxString FPU()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(FPU_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString VME()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(VME_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString DE()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(DE_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString PSE()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(PSE_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString TSC()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(TSC_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString MSR()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(MSR_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString PAE()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(PAE_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString MCE()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(MCE_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString CX8()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(CX8_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString APIC()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(APIC_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString SEP()	
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(SEP_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString MTRR()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(MTRR_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}
			
			///SysInfo
			const wxString PGE()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(PGE_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString MCA()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(MCA_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString CMOV()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(CMOV_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

            ///SysInfo
			const wxString PAT()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(PAT_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString PSE36()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(PSE36_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString PSNUM()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(PSNUM_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString CLFLUSH()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(CLFLUSH_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString DTS()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(DTS_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString ACPI()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(ACPI_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString FXSR()
				{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(FXSR_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString SS()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(SS_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}

			///SysInfo
			const wxString TM()
			{
				#ifdef __SysInfo__
					if (sysinfo.getFeature(TM_FLAG) == true)
						return "YES";
					else
						return "NO";
				#else
					return "UNKNOW";
				#endif
			}
		}
	}
}