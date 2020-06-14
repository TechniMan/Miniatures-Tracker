#pragma once
#ifndef _DATABASE_HPP_
#define _DATABASE_HPP_

#include <vector>

#include "Miniature.hpp"

/// <summary>
/// Usage:
/// Use `Insert` for adding new records.
/// Use `Get` to attempt to get a record out of the database.
/// Then use `Insert` to put back the updated record.
/// </summary>
class Database
{
private:
	std::vector<Miniature> _miniatures;

public:
	Database();

	/// <summary>
	/// Returns whether a miniature was found. Returns pointer to found item.
	/// </summary>
	/// <param name="name">Exact name to find</param>
	/// <param name="miniature">(out) Pointer to miniature</param>
	/// <returns>True if a miniature was found</returns>
	bool Get(std::string& name, const Miniature* miniature) const noexcept;
	
	/// <summary>
	/// [NOT IMPLEMENTED] Returns whether a new record was created.
	/// </summary>
	/// <param name="miniature">Record to insert</param>
	/// <returns>True if a new record was created</returns>
	bool Insert(Miniature& miniature) noexcept;

	bool Load(void);
	bool Save(void) const;
};

#endif
