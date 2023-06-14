#pragma once
#include <iostream>
#include <list>
#include <string>


class Sorting {
public:
	virtual void sort(const char* src, char* dst, size_t srcSize) = 0;
	virtual ~Sorting() {}
};

class PrzezWybor:public Sorting
{
	virtual void sort(const char* src, char* dst, size_t srcSize) override
	{
		std::cout << "Przez wybor\n";
	}
};

class Babelkowe :public Sorting
{
	virtual void sort(const char* src, char* dst, size_t srcSize) override
	{
		std::cout << "Babelkowe\n";
	}
};

class List {

	std::shared_ptr<Sorting> algo;

public:
	void setAlgo(const std::shared_ptr<Sorting>& algo) {
		this->algo = algo;
	}

	void sort(const std::string& inFile, const std::string& outFile) {
		algo->sort(nullptr, nullptr, 0);
	}
};


