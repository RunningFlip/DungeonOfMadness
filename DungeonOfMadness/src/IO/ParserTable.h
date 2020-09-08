#pragma once
#include <map>
#include <vector>
#include <cassert>
#include "../Helper/StringHelper.h"


template<typename T>
class ParserTable
{
private:
	std::vector<T*>* vec;
	std::map<std::string, T*> table;

public:
	ParserTable()
	{
		vec = new std::vector<T*>();
	}

	~ParserTable()
	{
		delete vec;
	}

	const std::vector<T*>* GetAll() const
	{
		return vec;
	}

	T* Get(const std::string _key) const
	{
		if (table.contains(_key))
		{
			return table.at(_key);
		}
		else
		{
			return nullptr;
		}
	}

	bool ContainsKey(const std::string _key) const
	{
		return table.contains(StringHelper::ParseString(_key));
	}

	void Add(const std::string _key, T* _element)
	{
		assert(!table.contains(_key), "'" + _key + "' was already added to the table!");

		vec->push_back(_element);
		table.insert({ StringHelper::ParseString(_key), _element });
	}

	void Remove(const std::string _key, T* _element)
	{
		assert(table.contains(_key), "'" + _key + "' does not exists in the table!");

		vec->erase(std::remove(vec->begin(), vec->end(), _element), vec->end());
		table.erase(StringHelper::ParseString(_key));
	}
};