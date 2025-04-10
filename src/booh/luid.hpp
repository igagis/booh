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
	underlying_type id;

	luid(underlying_type id) :
		id(id)
	{}

public:
	underlying_type get() const noexcept
	{
		return this->id;
	}
};

template <typename underlying_type = uint32_t>
class luid_generator
{
	underlying_type tip = 0;

public:
	luid<underlying_type> make()
	{
		return this->tip++;
	}

	luid<underlying_type> make(underlying_type id)
	{
		// TODO:
		utki::assert(false, SL);
		return {id};
	}
};

} // namespace booh
