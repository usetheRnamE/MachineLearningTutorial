#include "Data.hpp"

Data::Data()
{
}

Data::~Data()
{
}

void Data::SetFeatureVector(std::vector<uint8_t>* vec)
{
	featureVector = vec;
}

void Data::AppendToFeatureVector(uint8_t val)
{
	featureVector->emplace_back(val);
}

void Data::SetLabel(uint8_t val)
{
	label = val;
}

void Data::SetEnumLabel(int val)
{
	enumLabel = val;
}

int Data::GetFeatureVecSize()
{
	return featureVector->size();
}

uint8_t Data::GetLabel()
{
	return label;
}

uint8_t Data::GetEnumLabel()
{
	return enumLabel;
}

std::vector<uint8_t>* Data::GetFeatureVec()
{
	return featureVector;
}
