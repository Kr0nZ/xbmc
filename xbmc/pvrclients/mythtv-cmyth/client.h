#pragma once
/*
 *      Copyright (C) 2005-2009 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#ifndef CLIENT_H
#define CLIENT_H

#include "utils/StdString.h"
#include "../../../addons/library.xbmc.addon/libXBMC_addon.h"
#include "../../../addons/library.xbmc.pvr/libXBMC_pvr.h"
#include "libcmyth.h"

#define DEFAULT_HOST          "127.0.0.1"
#define DEFAULT_EXTRA_DEBUG          false
#define DEFAULT_PORT 6543
#define DEFAULT_DB_USER "mythtv"
#define DEFAULT_DB_PASSWORD "mythtv"
#define DEFAULT_DB_NAME "mythconverg"

extern bool         g_bCreated;           ///< Shows that the Create function was successfully called
extern int          g_iClientID;          ///< The PVR client ID used by XBMC for this driver
extern CStdString   g_szUserPath;         ///< The Path to the user directory inside user profile
extern CStdString   g_szClientPath;       ///< The Path where this driver is located

/* Client Settings */
extern CStdString   g_szHostname;         ///< The Host name or IP of the mythtv server
extern int          g_iMythPort;       ///< The mythtv Port (default is 6543)
extern CStdString   g_szMythDBuser;       ///< The mythtv sql username (default is mythtv)
extern CStdString   g_szMythDBpassword;       ///< The mythtv sql password (default is mythtv)
extern CStdString   g_szMythDBname;       ///< The mythtv sql database name (default is mythconverg)
extern bool         g_bExtraDebug; 

extern ADDON::CHelper_libXBMC_addon *XBMC;
extern CHelper_libXBMC_pvr   *PVR;
extern CHelper_libcmyth *CMYTH;

#endif /* CLIENT_H */
