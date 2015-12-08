/* 
 * File:   cHelperSerializer.h
 * Author: juia
 *
 * Created on 18. November 2015, 21:46
 */

#ifndef CHELPERSERIALIZER_H
#define	CHELPERSERIALIZER_H

#include "cHelper.h"

class cHelperSandboxSerialize : public cHelperSandBox
{
public:
  cHelperSandboxSerialize()
  {
    m_strDirSandbox = STREAMSTRING(m_strDirSandbox << "serialized/");
  };
  
  virtual ~cHelperSandboxSerialize(){}
  
protected:
  
};

template<typename TYPE_STREAM, typename TYPE_SERIALIZER>
class cHelperSerializer : public cHelperSandboxSerialize
{
public:

  cHelperSerializer(std::string p_strFileName)
  : m_oStream(STREAMSTRING(m_strDirSandbox << p_strFileName << ".ltm"))
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
  void Write(TYPE_TO_SERIALIZE& p_oObject)
  {
    // create and open a character archive for output
    m_oArchive << p_oObject;
  }
};

class cDeserializer : public _cHelperDeserializer
{
public:
  cDeserializer(std::string p_strFileName):_cHelperDeserializer(p_strFileName){}
  
  template<typename TYPE_TO_SERIALIZE>
  void Read(TYPE_TO_SERIALIZE& p_iObject)
  {
    // create and open a character archive for output
    m_oArchive >> p_iObject;
  }
};

#endif	/* CHELPERSERIALIZER_H */

