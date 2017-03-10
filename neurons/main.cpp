#include "ImageRecognition.h"
#include "DataGenerator.h"

int main()
{
	//DataGenerator dGen;
	//dGen.GenerateData("img/","data/data.dat");

	ImageRecognition nn;
	//nn.CreateNeuralNetwork(400, 20, 10, "data/data.dat");
	//nn.RandomizeSamples();
	//int64_t sec = nn.Train();
	//nn.SaveNeuralNetworkState("data/");
	//std::cout << "Training time: " << sec << std::endl;
	
	nn.LoadNeuralNetworkState("data/");

	int32_t result;
	
	for (int32_t i = 0; i < 10; i++)
	{
		result = nn.CheckExample("examples/test" + std::to_string(i) + ".png");
		std::cout << "It is probably number " << result << std::endl;
	}

	getchar();
	return 0;
}