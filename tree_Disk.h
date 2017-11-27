#pragma once

#include "tree_Folder.h"

namespace tree
{
	std::shared_ptr<tree::Folder> ParseDisk(rapidjson::Value & json);
}
