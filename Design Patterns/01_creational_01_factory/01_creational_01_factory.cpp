#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Document
{
public:
	Document(const string& name) : m_name(name)
	{
		cout << "Created new document with name " << m_name << endl;
	}
protected:
	string m_name;
};

class TextDocument : public Document
{
public:
	TextDocument(const string& name) : Document(name) {}
};

class WordDocument : public Document
{
public:
	WordDocument(const string& name) : Document(name) {}
};

class PdfDocument : public Document
{
public:
	PdfDocument(const string& name) : Document(name) {}
};


int main()
{

	getchar();
    return 0;
}
