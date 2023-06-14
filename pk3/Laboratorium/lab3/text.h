#pragma once

class Text
{
private:
	char* text;
	unsigned int size;
public:
	Text();
	Text(const char* a);
	inline unsigned int get_size() const { return size; }
	inline char* get_text() const { return text; }
	Text(const Text& copied);
	~Text() { delete[] text; }

	Text& operator=(const Text& copied);
	Text& operator--(int);
	Text operator()(int pos, size_t len);
	char* operator+(const Text& copied);
	bool operator==(const Text& second);

};