#include <cstring>
#include <iostream>
#include <string.h>
#include "text.h"

Text::Text()
{
    this->text = new char[strlen("")+1];
    strcpy_s(this->text, strlen("")+1, "");
    this->size = 0;
}
Text::Text(const char* starting_text)
{
    this->text = new char[strlen(starting_text) + 1];
    strcpy_s(this->text, strlen(starting_text) + 1, starting_text);
    this->size = strlen(this->text);
}

Text::Text(const Text& copied) :size(copied.size)
{
    this->text = new char[strlen(copied.text) + 1];
    strcpy_s(this->text, strlen(copied.text) + 1, copied.text);
    this->size = strlen(this->text);
}

Text& Text::operator=(const Text& copied)
{
    if (this != &copied)
    {
        this->text = new char[strlen(copied.text) + 1];
        strcpy_s(this->text, strlen(copied.text) + 1, copied.text);
        this->size = strlen(this->text);
    }
    return *this;
}

char* Text::operator+(const Text& added)
{
    auto l1 = strlen(this->text);
    auto l2 = strlen(added.text);
    char* result = new char[l1 + l2 + 1];
    for (int i = 0; i < l1; i++) result[i] = this->text[i];
    for (int i = l1; i < l1 + l2; i++) result[i] = added.text[i - l1];
    result[l1 +l2] = '\0';

    return result;
}

bool Text::operator==(const Text& second)
{
    std::cout << "'" << this->text << "' == '" << second.text << "'\n";
    return (strcmp(this->text, second.text) == 0);
}

Text Text::operator()(int pos, size_t len)
{
    if (pos + len < this->size)
    {
        char* result = new char[len];
        
        for (int i = 0; i < len; i++)
        {
            result[i] = this->text[i+pos];
        }
        result[len] = '\0';
        Text newtext(result);
        return newtext;
    }
    else
    {
        std::cout << "\n" << "Index error\n";
    }
}

Text& Text::operator--(int)
{
    auto len = strlen(this->text);
    char* result = new char[len + 1];
    for (int i = 0; i < len; i++) result[i] = this->text[len - i -1];
    result[len] = '\0';
    this->text = result;
    return *this;
}