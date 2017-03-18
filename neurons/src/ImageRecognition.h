#pragma once
#include <opennn/opennn.h>
#include <chrono>

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
	ImageRecognition& LoadNeuralNetworkState(std::string dir);
	ImageRecognition& SaveNeuralNetworkState(std::string dir);
	ImageRecognition& SetData(std::string path);
	ImageRecognition& RandomizeSamples();
	int64_t Train(size_t maxIterations=1000, double maxTimeInSec=1000);
	int32_t CheckExampleFromFile(std::string path) const;
	int32_t CheckExampleFromVector(const std::vector<bool>& vector, int32_t val=0) const;
	int32_t GetOutputNumber() const { return static_cast<int32_t>(m_NeuralNetwork.get_outputs_number()); }
};
