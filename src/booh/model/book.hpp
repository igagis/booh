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

#include <vector>

#include <tml/tree.hpp>
#include <utki/shared_ref.hpp>

#include "account.hpp"

namespace booh {
class book
{
	std::vector<utki::shared_ref<account>> accounts;

	std::vector<std::weak_ptr<transaction>> transactions;

	std::vector<utki::shared_ref<account_tree_node>> accounts_tree;

public:
	size_t get_num_accounts() const noexcept
	{
		return this->accounts.size();
	}

	static book load(const tml::forest& desc);
	static book load(const papki::file& fi);

	void save(papki::file& fi) const;

private:
	void read_accounts(const tml::forest& accounts_forest);
	void add_account(const tml::forest& desc);
};
} // namespace booh