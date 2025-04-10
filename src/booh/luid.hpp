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

#include <utki/debug.hpp>

namespace booh {

// TODO: make concept to accept only unsigned integral types
template <typename underlying_type = uint32_t>
class luid
{
	static_assert(std::is_integral_v<underlying_type>, "underlying type must be integral");
	static_assert(std::is_unsigned_v<underlying_type>, "underlying type must be unsigned");

	template <typename, bool>
	friend class luid_generator;

	underlying_type id;

	explicit luid(underlying_type id) :
		id(id)
	{}

public:
	underlying_type get() const noexcept
	{
		return this->id;
	}
};

// TODO: make concept to accept only unsigned integral types
template <typename underlying_type = uint32_t, bool reuse = false>
class luid_generator
{
	static_assert(std::is_integral_v<underlying_type>, "underlying type must be integral");
	static_assert(std::is_unsigned_v<underlying_type>, "underlying type must be unsigned");

	struct variables_no_reuse {
		underlying_type next_free_id = 0;
	};

	struct variables_reuse : public variables_no_reuse {
		std::vector<underlying_type> free_ids;
	};

	std::conditional_t<
		reuse, //
		variables_reuse,
		variables_no_reuse //
		>
		vars;

public:
	luid<underlying_type> make()
	{
		if constexpr (reuse) {
			// TODO: pick from free ids if possible
		}
		return luid<underlying_type>(this->vars.next_free_id++);
	}

	// TODO: enable only for reuse
	luid<underlying_type> make(underlying_type id)
	{
		if (id == this->vars.next_free_id) {
			return this->make();
		}

		if constexpr (reuse) {
			// TODO: pick from free ids if possible
		}

		return luid<underlying_type>(id);
	}

	// TODO: enable only for reuse
	void free(luid<underlying_type> id)
	{
		// TODO:
	}
};

} // namespace booh
