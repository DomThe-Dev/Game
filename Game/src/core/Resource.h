#pragma once
#include <String>

class Resource
{
public:
	virtual ~Resource() = default; // Even if map of Resource is used, the child destructors will be called
	const std::string& GetPath() const { return file_path; }
protected:
	std::string file_path;
};