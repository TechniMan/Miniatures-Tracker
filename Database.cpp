#include "Database.hpp"



Database::Database()
{
	_miniatures = std::vector<Miniature>();
}



bool Database::Get(std::string& name, const Miniature* miniature) const noexcept
{
	bool found = false;
	for (auto mini = _miniatures.begin(); mini != _miniatures.end(); ++mini)
	{
		if ((*mini).name == name)
		{
			miniature = &*mini;
			found = true;
			break;
		}
	}
	return found;
}



bool Database::Insert(Miniature& miniature) noexcept
{
	return false;
}



bool Database::Load(void)
{
	return false;
}

bool Database::Save(void) const
{
	return false;
}
