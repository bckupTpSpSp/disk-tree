#include "headers.h"
#include "tree_Link.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace tree;

tree::Size Link::Size(bool bFollow, bool bRecursive) const
{
	if (!bFollow)
		return 0;

	auto ptr = _link.lock();
	return ptr ? ptr->Size(bFollow, bRecursive) : .0;
}

void Link::List(bool bFollow, bool bRecursive, const std::string & offset, std::ostream & out) const
{
	auto ptr = _link.lock();

	out << Name() << " -" << (ptr ? "-" : "X") << "-> " << _path;
	if (ptr && bFollow)
	{
		out << " // ";
		ptr->List(bFollow, bRecursive, offset, out);
	}
	else
	{
		out << std::endl;
	}
}

std::shared_ptr<Link> Link::Parse(rapidjson::Value & json)
{
	if (!json.HasMember("name") || !json.HasMember("link"))
		return nullptr;

	return std::shared_ptr<Link> { new Link(json["name"].GetString(), json["link"].GetString()) };
}	
