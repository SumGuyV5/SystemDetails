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
#include "General Card Info.hpp"

#include <SDL.h>
#include <wx/utils.h>
#include <wx/gdicmn.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

namespace System_Information 
{
	namespace Video_Card_Info
	{
		namespace General_Card_Info
		{
			///OpenGL
			const wxString Vender()
			{
				return (char *)glGetString(GL_VENDOR);
			}

			///OpenGL
			const wxString VideoCard()
			{
				return (char *)glGetString(GL_RENDERER);
			}

			const wxString VideoDrivers()
			{
				return "UNKNOW";
			}

			///SDL + wxWidgets
			const wxString TotalVideoMemory()
			{
				const SDL_VideoInfo* videoinfo = SDL_GetVideoInfo();
				unsigned long int temp = 0;
				SDL_PixelFormat* pixel = videoinfo->vfmt;
				unsigned char colour = pixel->BitsPerPixel;

				int width;
				int hight;
				wxDisplaySize(&width, &hight);

				temp = videoinfo->video_mem;
				temp += (((colour / 8) * (hight * width)) / 1024);
				temp /= 1024;

				return wxString::Format("%ld", temp) + " MB";
			}
			
			///SDL
			const wxString FreeVideoMemory()
			{
				const SDL_VideoInfo* videoinfo = SDL_GetVideoInfo();
				unsigned long int temp = 0;
				temp = videoinfo->video_mem;
				temp /= 1024;

				return wxString::Format("%i", temp) + " MB";
			}

			///wxWidgets
			const wxString ScreenResolution()
			{
				int width;
				int hight;
				wxDisplaySize(&width, &hight);

				return wxString::Format("%ld", width) + " x " + wxString::Format("%ld", hight);
			}

			const wxString ColourQuality()
			{
				const SDL_VideoInfo* videoinfo = SDL_GetVideoInfo();
				SDL_PixelFormat* pixel = videoinfo->vfmt;
				unsigned char colour = pixel->BitsPerPixel;
				
				return wxString::Format("%ld", colour) + " bit Colour.";
			}
		}
	}
}