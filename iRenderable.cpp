/* 
 * File:   iRenderable.cpp
 * Author: juia
 * 
 * Created on 22. Oktober 2015, 21:08
 */

#include "iRenderable.h"
#include "iRenderer.h"

void iRenderable::accept(iRenderer* p_poRendrer)
{
  if(p_poRendrer)
    p_poRendrer->Render(this);
}
