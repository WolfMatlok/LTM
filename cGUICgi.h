/* 
 * File:   cGUICgi.h
 * Author: juia
 *
 * Created on 13. Oktober 2015, 20:03
 */

#ifndef CGUICGI_H
#define	CGUICGI_H

#include "cRendererCGI.h"

#include <iostream>
#include <vector>
#include <string>

class cGUICgi : public cCGIHelper
{
public:
  cGUICgi();
  virtual ~cGUICgi();

  /* Dispatches calls from sourrounding cgi framewrk.
   */
  static void Dispatch(int p_iAgrc, char** p_p2Argv);
  
private:
};

#endif	/* CGUICGI_H */

