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

#include "root_widget.hpp"

#include <ruis/widget/group/tabbed_book.hpp>
#include <ruis/widget/label/text.hpp>

#include "accounts_page.hpp"
#include "style.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;

using namespace booh;

utki::shared_ref<ruis::widget> booh::make_root_widget(const utki::shared_ref<ruis::context>& c)
{
	// clang-format off
	return m::tabbed_book(c,
		{},
		{
			{
				m::tab(c,
					{},
					{
						m::text(c, {}, c.get().loc().get("tab.accounts"sv))
					}
				),
				booh::make::accounts_page(c)
			}
		}
	);
	// clang-format on
}
