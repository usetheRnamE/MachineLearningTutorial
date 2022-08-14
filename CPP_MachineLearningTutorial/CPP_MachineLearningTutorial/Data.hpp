#ifndef __DATA_H
#define __DATA_H

#include <vector>
#include <stdint.h>
#include <stdio.h>

class Data
{
private:
	std::vector<uint8_t>* featureVector;
	uint8_t label;
	int enumLabel;

public:
	Data() : featureVector(new std::vector<uint8_t>) {}
	~Data();

public:
	void SetFeatureVector(std::vector<uint8_t>*);
	void AppendToFeatureVector(uint8_t);
	void SetLabel(uint8_t);
	void SetEnumLabel(int);

public:
	int GetFeatureVecSize();
	uint8_t GetLabel();
	uint8_t GetEnumLabel();

public:
	std::vector<uint8_t>* GetFeatureVec();
};

#endif