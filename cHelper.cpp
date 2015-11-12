/* 
 * File:   cHelper.cpp
 * Author: juia
 * 
 * Created on 20. September 2015, 14:23
 */

#include "cHelper.h"

cHelper::cHelper()
: m_strDirSandbox("/home/pi/sandbox/")
{
}

cHelper::cHelper(const cHelper& orig)
: m_strDirSandbox(orig.m_strDirSandbox)
{
}

cHelper::~cHelper()
{
}

const std::string cHelper::GetStrDirSandbox() const
{
  return m_strDirSandbox;
}

