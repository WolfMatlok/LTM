/* 
 * File:   iRenderable.h
 * Author: juia
 *
 * Created on 22. Oktober 2015, 21:08
 */

#ifndef IRENDERABLE_H
#define	IRENDERABLE_H

#include "iRenderer.h"


class iRenderable
{
public:
  virtual void accept(iRenderer* p_poRendrer) = 0;
private:

};

#endif	/* IRENDERABLE_H */

