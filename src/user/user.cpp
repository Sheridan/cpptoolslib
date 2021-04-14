#include "user.h"
#include <stdexcept>
#include <sys/types.h>

namespace cppt
{
namespace user
{

CUser::CUser(const __uid_t &uid)
  : m_userID(uid),
    m_groupID(0),
    m_username(""),
    m_userhome("")
{
  load(m_userID);
}

CUser::CUser(const std::string &username)
  : m_username(username),
    m_userID(0),
    m_groupID(0),
    m_userhome("")
{
  load(m_username);
}

CUser::~CUser()
{}

const __uid_t &CUser::userID() const
{
  return m_userID;
}

const __gid_t &CUser::groupID() const
{
  return m_groupID;
}

const std::string &CUser::username() const
{
  return m_username;
}

const std::string &CUser::home() const
{
  return m_userhome;
}

const bool CUser::isRoot() const
{
  return m_userID == 0;
}

void CUser::load(const __uid_t &uid)
{
  struct passwd *pw = getpwuid(uid);
  if(pw)
  {
    m_username = std::string(pw->pw_name);
    m_userhome = std::string(pw->pw_dir);
    m_groupID  = pw->pw_gid;
    return;
  }
  throw std::runtime_error("Can not load user with id " + std::to_string(uid));
}

void CUser::load(const std::string &username)
{
  struct passwd *pw = getpwnam(username.c_str());
  if(pw)
  {
    m_userhome = std::string(pw->pw_dir);
    m_userID   = pw->pw_uid;
    m_groupID  = pw->pw_gid;
    return;
  }
  throw std::runtime_error("Can not load user with name " + username);
}

}
}
