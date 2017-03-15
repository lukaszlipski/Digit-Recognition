#pragma once
#include <FreeImage.h>
#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

class DataGenerator
{
private:
	size_t m_Width;
	size_t m_Height;

public:
	DataGenerator();

	DataGenerator& SetExampleSize(size_t width, size_t height);
	bool GenerateData(const std::string & folderSrcName, const std::string outputFile);
	bool InsertExampleToFile(const std::string& imageFilePath, const char* destFile, ofstream& file);
};