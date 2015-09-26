/* (L)ittle (T)urnier (M)aker                                                                                                                                              
 * File:   main.cpp                                                                                                                                                        
 * Author: juia                                                                                                                                                            
 *                                                                                                                                                                         
 * Created on 18. September 2015, 20:51                                                                                                                                    
 */                                                                                                                                                                        
                                                                                                                                                                           
#include <cstdlib>                                                                                                                                                         
                                                                                                                                                                           
#include "cApplication.h"                                                                                                                                                  
#include "cRotationStrategy.h"                                                                                                                                             
                                                                                                                                                                           
int main(int argc, char** argv)                                                                                                                                            
{                                                                                                                                                                          
  cApplication oApp(argc, argv);                                                                                                                                           
                                                                                                                                                                           
  cRotationStrategy oRotStat(&oApp);                                                                                                                                       
                                                                                                                                                                           
  return 0;
}

