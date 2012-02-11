#pragma once
class BrowserInfo {
public:
  BrowserInfo(void){}
  BrowserInfo(const BrowserInfo& src){ *this = src; }
  ~BrowserInfo(void){}
  const BrowserInfo& operator =(const BrowserInfo& src) {
    _installer = src._installer;
    _exe = src._exe;
    return src;
  }
  
  CString _installer;
  CString _exe;
};

class SoftwareUpdate
{
public:
  SoftwareUpdate(void);
  ~SoftwareUpdate(void);
  void LoadSettings(CString settings_ini);
  bool UpdateSoftware(void);

protected:
  CAtlList<BrowserInfo> _browsers;
  CString           _software_url;
  CString           _directory;
  LARGE_INTEGER     _last_update_check;
  LARGE_INTEGER     _perf_frequency_minutes;

  bool UpdateBrowsers(void);
  bool InstallSoftware(CString browser, CString file_url, CString md5,
           CString version, CString command, DWORD update, CString check_file);
  bool TimeToCheck(void);
};

