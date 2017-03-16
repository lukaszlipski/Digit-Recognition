#include "src/ImageRecognition.h"
#include "src/DataGenerator.h"
#include "src/SimpleWindow.h"
#include "src/SimpleUI.h"

int main()
{
	ImageRecognition nn;

	//DataGenerator dGen;
	//dGen.GenerateData("examples/","data/data.dat");
	//
	//nn.CreateNeuralNetwork(400, 20, 10, "data/data.dat");
	//nn.RandomizeSamples();
	//int64_t sec = nn.Train();
	//nn.SaveNeuralNetworkState("data/");
	//std::cout << "Training time: " << sec << std::endl;
	//getchar();
	//return 0;

	SimpleWindow::GetInstance().Startup();
	SimpleUI ui;
	nn.LoadNeuralNetworkState("data/");

	int32_t result;

	float good = 0;
	int32_t sum = 0;
	directory_iterator end_itr;
	for (directory_iterator itr("test/"); itr != end_itr; ++itr)
	{
		sum++;
		path a = itr->path();
		result = nn.CheckExampleFromFile(a.string());
		if (result == atof(a.filename().string().c_str()))
			good++;
	}
	std::cout << "Efficiency approximately: " << good / sum << std::endl;

	Font font;
	font.loadFromFile("fonts/NotoSans-Regular.ttf");

	std::vector<bool> BoardState(400);

	result = 0;
	while (!SimpleWindow::GetInstance().ShouldWindowClose())
	{
		SimpleWindow::GetInstance().Clear();

		// btn reset
		if (ui.Button(0, RECT{135, 200, 100, 50}, Color(41, 182, 246)))
		{
			for (int32_t i = 0; i < BoardState.size(); i++)
				BoardState[i] = false;
		}
		ui.Text(1, 155, 210, "Reset", 24, Color(224, 224, 224), &font);

		// panel
		if (ui.Panel(2, BOARD{350,75,25,25,20,20}, BoardState))
		{
			result = nn.CheckExampleFromVector(BoardState);
			std::cout << "It is probably number " << result << std::endl;
		}
		ui.Text(1, 50, 300, "It is probably number " + std::to_string(result), 24, Color(41, 182, 246), &font);

		SimpleWindow::GetInstance().Update();
	}

	return 0;
}
