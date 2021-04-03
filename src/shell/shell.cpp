#include "shell.h"
#include <iostream>
#include <stdio.h>

namespace cppt
{
namespace shell
{

std::string exec(const std::string &command)
{
  char buffer[128];
  std::string result = "";
  FILE *pipe = popen(command.c_str(), "r");
  if(pipe)
  {
    try
    {
      while(fgets(buffer, sizeof buffer, pipe) != NULL)
      {
        result += buffer;
      }
    }
    catch(...)
    {
      pclose(pipe);
      std::string message = "Executing failed: " + command;
      if(!result.empty())
      {
        message += ", output: " + result;
      }
      throw std::runtime_error(message);
    }
    pclose(pipe);
    return result;
  }
  throw std::runtime_error("Can not execute command: " + command);
}


}
}
