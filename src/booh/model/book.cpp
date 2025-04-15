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

#include "book.hpp"

using namespace std::string_view_literals;

using namespace booh;

book book::load(const papki::file& fi)
{
	return load(tml::read(fi));
}

book book::load(const tml::forest& desc)
{
	if (desc.empty()) {
		throw std::invalid_argument("book::load(forest): given book description is empty");
	}

	auto i = desc.begin();

	// check booh tag
	{
		ASSERT(i != desc.end())
		if (i->value != "booh") {
			throw std::invalid_argument(
				"booh::load(forest): given book description does not have 'booh' as its first element"
			);
		}
	}

	++i;

	// check version
	{
		ASSERT(i != desc.end())
		if (i->value != "version"sv) {
			throw std::invalid_argument(
				"book::load(forest): given book description does not have 'version' as first element"
			);
		}

		// auto ver = get_property_value
	}

	// TODO:
	return book();
}

void book::save(papki::file& fi) const
{
	// TODO:
}
