/* 
 * File:   cHelper.h
 * Author: juia
 *
 * Created on 20. September 2015, 14:23
 */

#ifndef CHELPER_H
#define	CHELPER_H

#include <functional>
#include <sstream>
#include <iostream>


#define STREAMSTRING(STRMSG) [&]()->std::string{using namespace std; stringstream oStr023974tcnw0re; oStr023974tcnw0re << STRMSG; return oStr023974tcnw0re.str();}()
#define COUTSTRSTR(STRMSG) std::cout << STREAMSTRING(STRMSG)

class cHelper
{
public:
  cHelper();
  cHelper(const cHelper& orig);
  virtual ~cHelper();
private:

};

#endif	/* CHELPER_H */

