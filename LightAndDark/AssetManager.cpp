#include "AssetManager.h"

bool texture::loadAsset()
{
	return 0;
}

bool sound::loadAsset()
{
	
	return 0;
}

bool font::loadAsset()
{
	FontAsset::Register(L"normal_30", 30);
	FontAsset::Register(L"normal_20", 20);
	FontAsset::Register(L"normal_10", 10);
	return 0;
}