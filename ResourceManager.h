#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

template <typename D, class T>
class ResourceManager
{
public:
	ResourceManager(string& FileName)
	{
		PopulateStorage(FileName);
	}

	bool AddResource(const string& ResourceName)
	{
		auto res = Find(ResourceName);
		if (res)
		{
			++res->second;
			return true;
		}

		auto FilePath = FileMap.find(ResourceName);

		if (FilePath == FileMap.end())
			return false;

		T* Resource = Load(FilePath->second);
		if (!Resource)
			return false;

		ResourceMap.emplace(ResourceName, make_pair(Resource, 1));
		return true;
	}

	T* GetResource(const string& ResourceName)
	{
		auto res = Find(ResourceName);

		if (res)
			return res->first;
		else
			return nullptr;
	}

	bool RealeseResource(const string& ResourceName)
	{
		auto res = Find(ResourceName);

		if (!res)
			return false;
		--res->second;

		if (!res->second)
			Unload(ResourceName);

		return true;
	}

	void KillResources()
	{
		while (ResourceMap.begin() != ResourceMap.end())
		{
			delete ResourceMap.begin()->second.first;
			ResourceMap.erase(ResourceMap.begin());
		}
	}

	~ResourceManager()
	{
		KillResources();
	}

	T* Load(const string& Path)
	{
		return static_cast<D*>(this)->Load(Path);
	}

private:
	unordered_map<string, pair<T*, int>> ResourceMap;
	unordered_map<string, string> FileMap;

	pair<T*, int>* Find(const string& ResourceName)
	{
		auto itr = ResourceMap.find(ResourceName);

		if (itr != ResourceMap.end())
			return &itr->second;
		else
			return nullptr;
	}

	void Unload(const string& ResourceName)
	{
		auto itr = ResourceMap.find(ResourceName);

		if (itr == ResourceMap.end())
		{
			cerr << "FAIL" << endl;
			return;
		}

		delete itr->second.first;
		ResourceMap.erase(itr);
	}

	void PopulateStorage(const string& FileName)
	{
		ifstream paths(FileName);
		
		if (paths.is_open())
		{
			string PathName;
			string Path;

			while (!paths.eof())
			{
				paths >> PathName >> Path;
				FileMap.emplace(PathName, Path);
			}

			paths.close();
			return;
		}

		cerr << "FAIL" << endl;
	}
};