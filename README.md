[![Build Status](https://travis-ci.com/Sheridan/cpptoolslib.svg?branch=master)](https://travis-ci.com/Sheridan/cpptoolslib)

# cpptoolslib
Some simple methos for working with strings, networking, filesystem, etc...

# File system

* `std::string temp_path();` - Return temporaly path. Just generating, no create.
* `void create_path(const std::string &path);` - Creating path
* `void delete_path(const std::string &path);` - Deleting path
* `std::string extract_filename(const std::string &path);` - Extract filename from path
* `bool file_exists(const std::string &path);` - Check file exists

# Networking
* `std::string integerToIpAddr(const unsigned int &intIp);` - Convert integer ip address to string

# Shell
* `std::string exec(const std::string &command);` - Executing command in shell and returning result

# String

* `std::string rand_alnum_str(std::string::size_type sz);` - Generate random string
* `std::string replace_all(const std::string &str, const std::string &from, const std::string &to);` - Replaces all inclusions in a substring with another
* `bool contains(const std::string &str, const std::string &needle);` - Check string contain substring
* `std::string join(const std::vector<std::string> &strings, const std::string &delimiter = ", ");` - Join vector of string to single string
* `std::string formatted_current_datetime(const std::string &format);` - Returning formatted current datetime
