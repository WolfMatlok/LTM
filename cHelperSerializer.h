/* 
 * File:   cHelperSerializer.h
 * Author: juia
 *
 * Created on 18. November 2015, 21:46
 */

#ifndef CHELPERSERIALIZER_H
#define	CHELPERSERIALIZER_H

#include "cHelper.h"

template<typename TYPE_STREAM, typename TYPE_SERIALIZER>
class cHelperSerializer : public cHelper
{
public:

  cHelperSerializer(std::string p_strFileName)
  : m_oStream(STREAMSTRING(m_strDirSandbox << "serialized/" << p_strFileName))
  , m_oArchive(m_oStream)
  {
  }

  virtual ~cHelperSerializer()
  {
  }

protected:
  TYPE_STREAM m_oStream;
  TYPE_SERIALIZER m_oArchive;
};

typedef cHelperSerializer<std::ofstream, boost::archive::text_oarchive> _cHelperSerializer;
typedef cHelperSerializer<std::ifstream, boost::archive::text_iarchive> _cHelperDeserializer;

class cSerializer : public _cHelperSerializer
{
public:
  cSerializer(std::string p_strFileName):_cHelperSerializer(p_strFileName){}
  
  template<typename TYPE_TO_SERIALIZE>
  void Do(TYPE_TO_SERIALIZE& p_iNumber)
  {
    // create and open a character archive for output
    m_oArchive << p_iNumber;
  }
};

class cDeserializer : public _cHelperDeserializer
{
public:
  cDeserializer(std::string p_strFileName):_cHelperDeserializer(p_strFileName){}
  
  template<typename TYPE_TO_SERIALIZE>
  void Do(TYPE_TO_SERIALIZE& p_iNumber)
  {
    // create and open a character archive for output
    m_oArchive >> p_iNumber;
  }
};

#endif	/* CHELPERSERIALIZER_H */

