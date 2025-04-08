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

namespace booh {

class account_tree_node
{
protected:
	account_tree_node() = default;

public:
	const uint32_t id;

	account_tree_node(uint32_t id);
};

class account_group : public account_tree_node
{
    std::vector<account_tree_node> children;
public:
	account_group(uint32_t id);
};

class account : public account_tree_node
{
public:
	account(uint32_t id);
};
} // namespace booh