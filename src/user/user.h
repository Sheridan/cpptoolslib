#pragma once

#include <string>
#include <pwd.h>
#include <unistd.h>

namespace cppt
{
namespace user
{

class CUser
{
public:
  CUser(const __uid_t &uid = getuid());
  CUser(const std::string &username);
  virtual ~CUser();
  const __uid_t &userID() const;
  const __gid_t &groupID() const;
  const std::string &username() const;
  const std::string &home() const;
  const bool isRoot() const;

private:
  void load(const __uid_t &uid);
  void load(const std::string &username);
  __uid_t     m_userID;
  __gid_t     m_groupID;
  std::string m_username;
  std::string m_userhome;
};

}
}
