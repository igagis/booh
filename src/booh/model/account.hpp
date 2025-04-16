/*
booh - Double record bookkeeping application

Copyright (C) 2025 Ivan Gagis <igagis@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/* ================ LICENSE END ================ */

#pragma once

#include <cstdint>
#include <vector>

#include <utki/debug.hpp>

#include "transaction.hpp"

namespace booh {

using ledger = std::vector<utki::shared_ref<transaction>>;

class account_tree_node
{
public:
	std::u32string name;

	std::u32string description;

	bool is_reversed = false;

	virtual ~account_tree_node() = default;

	virtual bool is_group() const noexcept
	{
		return false;
	}

	virtual std::vector<utki::shared_ref<account_tree_node>>& get_children()
	{
		throw std::logic_error("children list requested from account_tree_node which cannot have children");
	}

	virtual ledger& get_ledger()
	{
		throw std::logic_error("ledger is requested from account_tree_node which cannot have ledger");
	}
};

class account_tree_node_group : public account_tree_node
{
	std::vector<utki::shared_ref<account_tree_node>> children_v;

public:
	virtual bool is_group() const noexcept override
	{
		return true;
	}

	virtual std::vector<utki::shared_ref<account_tree_node>>& get_children() override
	{
		return this->children_v;
	}
};

class account : public account_tree_node
{
	std::vector<utki::shared_ref<transaction>> ledger_v;

public:
	bool is_quantity = false;

	account() = default;

	ledger& get_ledger() override
	{
		return this->ledger_v;
	}
};

} // namespace booh
