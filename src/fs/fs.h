#pragma once
#include <string>

namespace cppt
{
namespace fs
{

std::string temp_path();
void create_path(const std::string &path);
void delete_path(const std::string &path);
std::string extract_filename(const std::string &path);
bool file_exists(const std::string &path);

}
}
