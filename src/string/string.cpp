#include "string.h"

#include <cstdlib>   // for rand()
#include <cctype>    // for isalnum()
#include <algorithm> // for back_inserter
#include <chrono>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstddef>

namespace cppt
{
namespace string
{


std::string rand_alnum_str(std::string::size_type sz)
{
  std::srand(std::time(nullptr));
  static const char alphanum[] =
          "0123456789"
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
          "abcdefghijklmnopqrstuvwxyz";
  std::string s;
  s.reserve(sz);
  generate_n(std::back_inserter(s), sz, []()
  {
    return alphanum[std::rand() % (sizeof(alphanum) - 1)];
  });
  return s;
}

std::string replace_all(const std::string &str, const std::string &from, const std::string &to)
{
  if(from.empty())
  {
    return str;
  }
  size_t start_pos = 0;
  std::string result = str;
  while((start_pos = result.find(from, start_pos)) != std::string::npos)
  {
    result.replace(start_pos, from.length(), to);
    start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
  }
  return result;
}

bool contains(const std::string &str, const std::string &needle)
{
  return str.find(needle) != std::string::npos;
}

std::string join(const std::vector<std::string> &strings, const std::string &delimiter)
{
  std::string result("");
  for(std::vector<std::string>::const_iterator it = strings.begin(); it != strings.end(); ++it)
  {
    result += (*it);
    if(it + 1 != strings.end())
    {
      result += delimiter;
    }
  }
  return result;
}

std::string formatted_current_datetime(const std::string &format)
{
  std::ostringstream oss;
  std::time_t dt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  oss << std::put_time(std::localtime(&dt), format.c_str());
  return oss.str();
}

std::string repeat(const std::string &str, const std::size_t &n)
{
  if(n == 0)                { return                     {}; }
  if(n == 1 || str.empty()) { return                    str; }
  if(str.size() == 1)       { return std::string(n, str[0]); }

  std::string result = str;
  result.reserve(str.size() * n);
  std::size_t m = 2;
  for(; m <= n; m *= 2) { result += result; }
  result.append(result.c_str(), (n-(m/2)) * str.size());
  return result;
}

}
}
