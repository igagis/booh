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

#include "accounts_page.hpp"

#include <ruis/widget/label/text.hpp>

#include "style.hpp"

using namespace std::string_literals;
using namespace booh;

accounts_page::accounts_page(utki::shared_ref<ruis::context> context) :
	ruis::widget(std::move(context), {}, {}),
	ruis::page(this->context, {}),
	// clang-format off
	ruis::container(this->context,
		{
			.container_params{
				.layout = ruis::layout::pile
			}
		},
		{
			m::text(this->context, {}, U"accounts page"s)
		}
	)
	// clang-format on
{}

utki::shared_ref<booh::accounts_page> booh::make::accounts_page(utki::shared_ref<ruis::context> context)
{
	return utki::make_shared<booh::accounts_page>(std::move(context));
}
