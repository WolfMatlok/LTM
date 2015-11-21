/* 
 * File:   cHelper.h
 * Author: juia
 *
 * Created on 20. September 2015, 14:23
 */

#ifndef CHELPER_H
#define	CHELPER_H

#include <typeinfo>

#include <functional>
#include <sstream>
#include <iostream>
#include <fstream>

// include headers that implement a archive in simple text format
#include "boost/archive/text_oarchive.hpp"
#include "boost/archive/text_iarchive.hpp"
#include <boost/archive/tmpdir.hpp>

#include <boost/serialization/shared_ptr.hpp>
#include "boost/serialization/vector.hpp"
#include "boost/serialization/map.hpp"

#include "boost/program_options/variables_map.hpp"
#include "boost/program_options/options_description.hpp"
#include "boost/program_options/parsers.hpp"
#include "boost/program_options/cmdline.hpp"

namespace po = boost::program_options;

#include "boost/uuid/uuid.hpp"            // uuid class
#include "boost/uuid/uuid_generators.hpp" // generators
#include "boost/uuid/uuid_io.hpp"         // streaming operators etc.



#define STREAMSTRING(STRMSG) [&]()->std::string{using namespace std; stringstream oStr023974tcnw0re; oStr023974tcnw0re << STRMSG; return oStr023974tcnw0re.str();}()
#define COUTSTRSTR(STRMSG) std::cout << STREAMSTRING(STRMSG)
#define LOGSTRSTR(STRMSG) std::cerr << STREAMSTRING(STRMSG)
#define LOGSTRSTR_ERROR(STRMSG) std::cerr << STREAMSTRING(STRMSG)

class cHelper
{
public:
  cHelper();
  cHelper(const cHelper& orig);
  virtual ~cHelper();

  const std::string GetStrDirSandbox() const;

protected:
  const std::string m_strDirSandbox;
};

template<class T>
void SERIALIZE_TO_FILE(T& p_oObject, std::string p_strFileName = "")
{
  // create and open a character archive for output
  std::string strFileNameDest = STREAMSTRING(cHelper().GetStrDirSandbox() << "serialized/" << (p_strFileName == "") ? typeid (T).name() : p_strFileName);
  std::ofstream ofs(strFileNameDest);
  boost::archive::text_oarchive oa(ofs);
  oa << p_oObject;
}

template<class T>
void DESERIALIZE_FROM_FILE(T& p_oObject, std::string p_strFileName = "")
{
  std::string strFileNameSrc = STREAMSTRING(cHelper().GetStrDirSandbox() << "serialized/" << (p_strFileName == "") ? typeid (T).name() : p_strFileName);
  // create and open an archive for input
  std::ifstream ifs(strFileNameSrc);
  boost::archive::text_iarchive ia(ifs);
  // read class state from archive
  ia >> p_oObject;
  // archive and stream closed when destructors are called
}

#endif	/* CHELPER_H */

