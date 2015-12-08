/* 
 * File:   cHelper.cpp
 * Author: juia
 * 
 * Created on 20. September 2015, 14:23
 */

#include "cHelper.h"
#include "boost/algorithm/string/replace.hpp"

cHelperSandBox::cHelperSandBox()
: m_strDirSandbox("/home/pi/sandbox/")
{
}

cHelperSandBox::cHelperSandBox(const cHelperSandBox& orig)
: m_strDirSandbox(orig.m_strDirSandbox)
{
}

cHelperSandBox::~cHelperSandBox()
{
}

const std::string cHelperSandBox::GetStrDirSandbox() const
{
  return m_strDirSandbox;
}

std::vector<std::string> cHelperSandBox::GetFilesOfSandbox(const std::string p_strFileExtension)
{
  using namespace std;
  using namespace boost::filesystem;

  path oPath(m_strDirSandbox);

  //*** get a list of all tournaments within the sandbox ***
  std::vector<std::string> oListOfTournaments;

  for (directory_iterator oDir(oPath); oDir != directory_iterator(); oDir++)
  {
    if (is_regular_file(oDir->path()))
    {
      std::string strCurrFile = oDir->path().filename().string();
      std::string strExtension = oDir->path().filename().extension().string();
      
      if(p_strFileExtension == strExtension)
      {
        strCurrFile = boost::replace_all_copy(strCurrFile, "\"", "");
        oListOfTournaments.push_back(strCurrFile);
      }
    }
  }
  
  return oListOfTournaments;
}
