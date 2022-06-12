#include <iostream>
#include <cstring>

#include "Page.h"
#pragma warning(disable : 4996)

Page::Page()
{
	pageContent = nullptr;
	pageNumber = 1;
}
Page::Page(const Page& other)
{
	copyFrom(other);
}

Page::Page(const char* pageContent)
{
	this->pageContent = new char[strlen(pageContent) + 1];
	strcpy(this->pageContent, pageContent);

	pageNumber = 1;
}

Page& Page::operator=(const Page& other)
{
	free();

	if (this != &other)
	{
		copyFrom(other);
	}

	return *this;
}

Page::~Page()
{
	free();
}

const char* Page::getPageContent() const
{
	return pageContent;
}

int Page::getPageNumber() const
{
	return pageNumber;
}

void Page::setPageContent(const char* pageContent)
{
	delete[] this->pageContent;
	this->pageContent = new char[strlen(pageContent) + 1];
	strcpy(this->pageContent, pageContent);
}

void Page::setPageNumber(const int pageNumber)
{
	this->pageNumber = pageNumber;
}

void Page::free()
{
	delete[] pageContent;
	pageNumber = 1;
}

void Page::copyFrom(const Page& other)
{
	pageContent = other.pageContent;
	pageNumber = other.pageNumber;
}