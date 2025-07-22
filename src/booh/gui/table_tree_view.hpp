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

#include <ruis/widget/container.hpp>
#include <ruis/widget/group/tree_view.hpp>

namespace booh {

class table_tree_view :
	virtual public ruis::widget, //
	private ruis::container
{
public:
	struct all_parameters {
		ruis::layout_parameters layout_params;
		ruis::widget::parameters widget_params;
	};

	table_tree_view(
		utki::shared_ref<ruis::context> context, //
		all_parameters params
	);

	class provider : protected ruis::tree_view::provider
	{
	public:
		provider(utki::shared_ref<ruis::context> context);

		virtual ruis::widget_list get_widgets(
			utki::span<const size_t> index, //
			bool is_collapsed
		) = 0;
	};
};

} // namespace booh