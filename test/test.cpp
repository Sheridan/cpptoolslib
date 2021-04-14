#include "test.h"
#include <cppt/fs.h>
#include <cppt/shell.h>
#include <cppt/string.h>
#include <cppt/user.h>

int main(void)
{
  logger = new CLogger();

  LL_LOG_NFO(cppt::shell::exec("ls"));
  LL_LOG_NFO(cppt::fs::file_exists("/tmp"));

  LL_LOG_NFO(cppt::string::contains("apple", "app"));
  LL_LOG_NFO(cppt::string::contains("apple", "foo"));

  LL_LOG_NFO(cppt::string::replace_all("apple", "p", "_foo_"));
  LL_LOG_NFO(cppt::string::rand_alnum_str(50));

  cppt::user::CUser user;
  LL_LOG_NFO("User name: " << user.username() << " with uid:gid " << user.userID() << ":" << user.groupID() << " and home in " << user.home());

  delete logger;
}
