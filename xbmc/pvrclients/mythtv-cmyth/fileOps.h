#ifndef __FILEOPS_H
#define __FILEOPS_H
//#include "client.h"

#include "utils/StdString.h"
#include <vector>
#include "cppmyth/MythConnection.h"

#include <map>
#include "addons/include/xbmc_pvr_types.h"

class MythConnection;

typedef enum
  {
    FILE_OPS_GET_COVERART   = 0,
    FILE_OPS_GET_FANART     = 1, /*!< @brief the timer is scheduled for recording */
    FILE_OPS_GET_CHAN_ICONS = 2, /*!< @brief the timer is currently recordings */
  } FILE_OPTIONS;
  
class fileOps
{
public:
  fileOps();
  fileOps(CStdString mythServer,int mythPort);
  
  bool checkDirectory(CStdString dirPath, bool hasFilename = false);
  std::vector< CStdString > getADirectoryList(CStdString dirPath);
  bool writeToFile( CStdString filePath, char* writeBuffer, int writeLength );
  void saveSGList (std::vector<CStdString> sgFileList, CStdString sgToSaveAs);
  bool updateLocalFilesList (CStdString localFolder);
  CStdString convSpecialPath (CStdString thePath, bool toRegular=true);
  bool storeFileInSG( char* saveBuffer, int buffLength, CStdString flSaveName, CStdString sgToSaveIn );
  std::vector<CStdString> missingSGFiles ( std::vector<CStdString> hayStack, std::vector<CStdString> needle );
  CStdString getArtworkPath(CStdString title,FILE_OPTIONS Get_What);
  CStdString checkFolderForTitle(CStdString title,CStdString awGroup);
  void syncSGCache(CStdString awGroup);
  CStdString GetFileFromBackend ( CStdString filenameToGet, CStdString fromStorageGroup );
  void checkRecordings (PVR_HANDLE handle);
  
  
private:
  CStdString myth_server;
  int myth_port;
  
  std::map< CStdString, std::vector< CStdString > > SGFilelist;
  std::map< CStdString, std::vector< CStdString > > LocalFilelist;
  CStdString baseLocalCachepath;
  std::map< CStdString, int > lastSGupdate;
  MythConnection mythConP;
  bool isMyth;
};

#endif