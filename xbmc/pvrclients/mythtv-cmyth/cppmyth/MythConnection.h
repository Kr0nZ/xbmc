#pragma once

#include "libcmyth.h"
#include "utils/StdString.h"
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include "MythPointer.h"

class MythRecorder;
class MythFile;
class MythProgramInfo;
class MythEventHandler;


class MythConnection 
{
public:
  MythConnection();
  MythConnection(CStdString server,unsigned short port);
  MythRecorder GetFreeRecorder();
  MythRecorder GetRecorder(int n);
  MythEventHandler CreateEventHandler();
  boost::unordered_map< CStdString, MythProgramInfo > GetRecordedPrograms();
  boost::unordered_map< CStdString, MythProgramInfo > GetPendingPrograms();
  boost::unordered_map< CStdString, MythProgramInfo > GetScheduledPrograms();
  bool DeleteRecording(MythProgramInfo &recording);
  bool IsConnected();
  CStdString GetServer();
  int GetProtocolVersion();
  bool GetDriveSpace(long long &total,long long &used);
  bool UpdateSchedules(int id);
  MythFile ConnectFile(MythProgramInfo &recording);
  bool IsNull();
  void Lock();
  void Unlock();
private:
  boost::shared_ptr< MythPointerThreadSafe< cmyth_conn_t > > m_conn_t;
  CStdString m_server;
  unsigned short m_port;
};