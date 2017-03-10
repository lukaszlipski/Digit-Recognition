#include "ImageRecognition.h"
#include "DataGenerator.h"

int main()
{
	DataGenerator dGen;
	dGen.GenerateData("img/","data/data.dat");

	ImageRecognition a;
	//a.CreateNeuralNetwork(400, 10, 10, "data/test.dat");
	//a.RandomizeSamples();
	//a.Train();
	
	a.LoadNeuralNetworkFromFile("data/nn.xml");

	int32_t result = a.CheckExample("examples/test5.png");
	std::cout << "It is probably number " << result;
	
	getchar();
	return 0;
}