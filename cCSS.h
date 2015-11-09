/* 
 * File:   cCSS.h
 * Author: wmk
 *
 * Created on 9. November 2015, 14:39
 */

#ifndef CCSS_H
#define	CCSS_H

#include <boost/shared_ptr.hpp>

/** Helper class for css definitions
 */
class cCSS
{
public:
  typedef boost::shared_ptr<cCSS> cCssPtr;
  
  cCSS();
  cCSS(const cCSS& orig);
  virtual ~cCSS();
  
  static cCssPtr CreateCssDefinition();
  
  std::string GetSimpleCssStyles();
  
private:
  
  std::string m_strCssSimple;
  
};



#endif	/* CCSS_H */

