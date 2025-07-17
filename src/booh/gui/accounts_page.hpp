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

#include <ruis/widget/group/book.hpp>

namespace booh {

// NOLINTNEXTLINE(bugprone-incorrect-enable-shared-from-this, "shared_from_this is accessible via publicly inherited page")
class accounts_page :
	public ruis::page, //
	private ruis::container
{
public:
	accounts_page(utki::shared_ref<ruis::context> context);
};

namespace make {
utki::shared_ref<booh::accounts_page> accounts_page(utki::shared_ref<ruis::context> context);
} // namespace make

} // namespace booh
