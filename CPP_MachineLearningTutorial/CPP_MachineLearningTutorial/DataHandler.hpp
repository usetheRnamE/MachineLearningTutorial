#ifndef __DATA_HANDLER_H
#define __DATA_HANDLER_H

#include <fstream>
#include "stdint.h"
#include "Data.hpp"
#include <vector>
#include <string>
#include <map>
#include <unordered_set>

class DataHandler
{
private:
	std::vector<Data*>* dataList;
	std::vector<Data*>* trainingData;
	std::vector<Data*>* testData;
	std::vector<Data*>* validationData;

	int numClasses;
	int featureVecSize;
	std::map<uint8_t, int> classMap;

	const double TRAIN_SET_PERCENT = .75;
	const double TEST_SET_PERCENT = .2;
	const double VALIDATION_PERCENT = .05;

public:
	DataHandler() : dataList(new std::vector<Data*>), testData(new std::vector<Data*>), trainingData(new std::vector<Data*>), validationData(new std::vector<Data*>) {}
	~DataHandler();

public:
	void ReadFeatureVector(std::string path);
	void ReadFeatureLabels(std::string path);
	void SplitData();
	void CountClasses();

public:
	uint32_t ConvertToEndian(const unsigned char* bytes);

public:
	std::vector<Data*>* GetTrainingData();
	std::vector<Data*>* GetTestData();
	std::vector<Data*>* GetValidationData();
};

#endif

