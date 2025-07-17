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

#include <memory>
#include <string>
#include <vector>

#include <utki/shared_ref.hpp>

#include "../money.hpp"

namespace booh {

class account;

struct transaction_split {
	std::u32string desc;

	std::weak_ptr<booh::account> account;

	money amount;

	int64_t quantity = 0;

	transaction_split() = default;
};

struct transaction {
	std::vector<transaction_split> splits;

	// TODO: date

	std::u32string desc;
};

} // namespace booh
