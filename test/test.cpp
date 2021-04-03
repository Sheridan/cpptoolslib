#include "test.h"
#include "fs.h"
#include "shell.h"
#include "string.h"

int main(void)
{
  logger = new ll::CLogger();

  LL_LOG_NFO(cppt::shell::exec("ls"));
  LL_LOG_NFO(cppt::fs::file_exists("/tmp"));

  LL_LOG_NFO(cppt::string::contains("apple", "app"));
  LL_LOG_NFO(cppt::string::contains("apple", "foo"));

  LL_LOG_NFO(cppt::string::replace_all("apple", "p", "_foo_"));
  LL_LOG_NFO(cppt::string::rand_alnum_str(50));


  delete logger;
}
