#pragma once
#include <iostream>
#include "TemplateArray.h"

class Testklasse :
	public TemplateArray<Testklasse>
{
public: 
	Testklasse();
	Testklasse(std::string random_name);
	~Testklasse();
	using TemplateArray<Testklasse>::m_name;

};

