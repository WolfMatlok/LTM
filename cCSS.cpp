/* 
 * File:   cCSS.cpp
 * Author: wmk
 * 
 * Created on 9. November 2015, 14:39
 */

#include "cCSS.h"

cCSS::cCSS()
{

  m_strCssSimple = "<script src=\"http://code.jquery.com/jquery-1.4.4.min.js\" type=\"text/javascript\" charset=\"utf-8\"></script> \
    <link rel=\"stylesheet\" href=\"http://matlok.de/css/fonts/stylesheet.css\" type=\"text/css\" title=\"no title\" charset=\"utf-8\"> \
    <link href=\"http://matlok.de/css/common.css\" rel=\"stylesheet\" type=\"text/css\">";

}

cCSS::cCSS(const cCSS& orig)
{
  m_strCssSimple = orig.m_strCssSimple;
}

cCSS::~cCSS()
{
}

std::string cCSS::GetSimpleCssStyles()
{
  return m_strCssSimple;
}

