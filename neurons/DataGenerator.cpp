#include "DataGenerator.h"

DataGenerator::DataGenerator()
	: m_Width(20), m_Height(20)
{
}

DataGenerator & DataGenerator::SetExampleSize(size_t width, size_t height)
{
	m_Width = width;
	m_Height = height;
	return *this;
}

bool DataGenerator::GenerateData(const std::string & folderSrcName, const std::string outputFile)
{
	if (!exists(folderSrcName) || !is_directory(folderSrcName))
	{
		std::cout << "Cannot find folder" << std::endl;
		std::cin.ignore(1);
		getchar();
		return false;
	}

	remove(outputFile);
	ofstream file(outputFile, ofstream::out | ofstream::app);

	directory_iterator end_itr;
	for (directory_iterator itr(folderSrcName); itr != end_itr; itr++)
	{
		path a = itr->path();
		InsertExampleToFile(a.string(), outputFile.c_str(), file);
	}

	file.close();
	return true;
}

bool DataGenerator::InsertExampleToFile(const std::string & imageFilePath, const char * destFile, ofstream & file)
{
	FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(imageFilePath.c_str(), 0), imageFilePath.c_str());
	if (!bitmap) return false;

	bitmap = FreeImage_ConvertTo24Bits(bitmap);
	bitmap = FreeImage_Rescale(bitmap, m_Width, m_Height);

	for (int32_t y = 0; y < m_Height; y++)
	{
		for (int32_t x = 0; x < m_Width; x++)
		{
			RGBQUAD pixel;
			FreeImage_GetPixelColor(bitmap, x, y, &pixel);
			int32_t value = (pixel.rgbBlue + pixel.rgbGreen + pixel.rgbRed) / 3;
			if (value < 250)
				value = 1;
			else
				value = 0;
			file << std::string(std::to_string(value) + " ").c_str();
		}
	}

	for (int32_t i = 0; i < 10; i++)
	{
		std::string a((path(imageFilePath).filename().string().c_str()));
		if (std::stoi(a) == i)
			file << std::string(std::to_string(1) + " ");
		else
			file << std::string(std::to_string(0) + " ");
	}

	file << '\n';

	FreeImage_Unload(bitmap);

	return true;
}
