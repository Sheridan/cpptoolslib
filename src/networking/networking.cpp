#include "networking.h"
#include <arpa/inet.h>

namespace cppt
{
namespace networking
{

std::string integerToIpAddr(const unsigned int &intIp)
{
  std::string result;
  result = std::to_string(intIp        & 0xFF);
  result = std::to_string((intIp >> 8) & 0xFF) + "." + result;
  result = std::to_string((intIp >> 16) & 0xFF) + "." + result;
  result = std::to_string((intIp >> 24) & 0xFF) + "." + result;
  return result;
}


}
}
