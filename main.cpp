/* (L)ittle (T)urnier (M)aker                                                                                                                                              
 * File:   main.cpp                                                                                                                                                        
 * Author: juia                                                                                                                                                            
 *                                                                                                                                                                         
 * Created on 18. September 2015, 20:51                                                                                                                                    
 */

#include <cstdlib>                                                                                                                                                         

#include "cGUICgi.h"
#include "cApplication.h"                                                                                                                                                  
#include "cRotationStrategy.h"

int main(int argc, char** argv)
{
  try
  {
    cGUICgi::Dispatch();
    return 0;
  }catch(std::exception& oEx){
    std::cout << "main() excpetion:" << oEx.what() << std::endl;
    return 0;
  }
 
  std::cout << cgicc::div();
  cApplication oApp(argc, argv);
  cRotationStrategy oRotStat(&oApp);
  oRotStat.CreateGame();
  std::cout << cgicc::div();
  
  return 0;
}

