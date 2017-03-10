#pragma once
#include <opennn/opennn.h>

using namespace OpenNN;

class ImageRecognition
{
private:
	DataSet m_Data;
	NeuralNetwork m_NeuralNetwork;
	LossIndex m_LossIndex;
	TrainingStrategy m_TrainingStrategy;
	size_t m_OutputSize;
	size_t m_InputSize;

public:
	ImageRecognition();

	ImageRecognition& CreateNeuralNetwork(int32_t input, int32_t hidden, int32_t output, const std::string& data);
	ImageRecognition& LoadNeuralNetworkFromFile(std::string path);
	ImageRecognition& SaveNeuralNetworkToFile(std::string path);
	ImageRecognition& SetData(std::string path);
	ImageRecognition& RandomizeSamples();
	bool Train();
	int32_t CheckExample(std::string path);

};