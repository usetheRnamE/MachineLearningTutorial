#include "DataHandler.hpp"

DataHandler::DataHandler()
{

}

DataHandler::~DataHandler()
{

}

void DataHandler::ReadFeatureVector(std::string path)
{
	uint32_t header[4]; //[MAGIC], [NUM IMAGES], [ROWSIZE], [COLSIZE]
	unsigned char bytes[4];
	FILE* file = fopen(path.c_str(), "r");

	if (file)
	{
		for (int i = 0; i < 4; i++)
			if (fread(bytes, sizeof(bytes), 1, file))
				header[i] = ConvertToEndian(bytes);

		printf("Done getting input file header. \n");

		int imageSize = header[2] * header[3];

		for (int i = 0; i < header[1]; i++)
		{
			Data* data = new Data();
			uint8_t element[1];
			for (int j = 0; j < sizeof(element); j++)
			{
				if (!fread(element, sizeof(element), 1, file))
					data->AppendToFeatureVector(element[0]);
				else
				{
					printf("Error: Cannot read from file. \n");
					exit(1);
				}
			}

			dataList->emplace_back(data);
		}
		printf("Succesfully read and store %lu feature vectores", dataList->size());
	}
	else
	{
		printf("Error: Cannot open file");
		exit(1);
	}
}

void DataHandler::ReadFeatureLabels(std::string path)
{
	uint32_t header[2]; //[MAGIC], [NUM IMAGES]
	unsigned char bytes[2];
	FILE* file = fopen(path.c_str(), "r");

	if (file)
	{
		for (int i = 0; i < 2; i++)
			if (fread(bytes, sizeof(bytes), 1, file))
				header[i] = ConvertToEndian(bytes);

		printf("Done getting label file header. \n");

		for (int i = 0; i < header[1]; i++)
		{	
			uint8_t element[1];
	
			if (!fread(element, sizeof(element), 1, file))
				dataList->at(i)->SetLabel(element[0]);
			else
			{
				printf("Error: Cannot read from file. \n");
				exit(1);
			}
		}
		printf("Succesfully read and store labels");
	}
	else
	{
		printf("Error: Cannot open file");
		exit(1);
	}
}

template<typename T>
void Split(T data, int size)
{
	int count = 0;

	while (count < size)
	{
		int randIndex = rand() % dataList->size();

		if (usedIndexes.find(randIndex) == usedIndexes.end())
		{
			data->emplace_back(dataList->at(randIndex));
			usedIndexes.insert(randIndex);
			count++;
		}
	}
}

void DataHandler::SplitData()
{
	std::unordered_set<int> usedIndexes;

	int trainSize = dataList->size() * TEST_SET_PERCENT;
	int testSize = dataList->size() * TEST_SET_PERCENT;
	int validSize = dataList->size() * VALIDATION_PERCENT;

	Split(trainingData, trainSize);
	Split(testData, testSize);
}

void DataHandler::CountClasses()
{
}

uint32_t DataHandler::ConvertToEndian(const unsigned char* bytes)
{
	return uint32_t();
}

std::vector<Data*>* DataHandler::GetTrainingData()
{
	return nullptr;
}

std::vector<Data*>* DataHandler::GetTestData()
{
	return nullptr;
}

std::vector<Data*>* DataHandler::GetValidationData()
{
	return nullptr;
}
