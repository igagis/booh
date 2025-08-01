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

#include "table_tree_view.hpp"

using namespace booh;

namespace {
utki::shared_ref<ruis::container> make_headers_widget(
	const utki::shared_ref<ruis::context>& c, //
	ruis::widget_list column_headers
)
{
	// clang-format off
    return ruis::make::row(c,
        {
            .layout_params{
                .dims = {ruis::dim::fill, ruis::dim::max}
            }
        },
        std::move(column_headers)
    );
	// clang-format on
}
} // namespace

table_tree_view::table_tree_view(
	utki::shared_ref<ruis::context> context, //
	all_parameters params
) :
	ruis::widget(
		std::move(context), //
		std::move(params.layout_params),
		std::move(params.widget_params)
	),
	// clang-format off
    ruis::container(
        this->context,
        {
            .container_params{
                .layout = ruis::layout::column
            }
        },
        {
            make_headers_widget(this->context,
                std::move(params.table_tree_view_params.column_headers)
            ),
            ruis::make::tree_view(this->context,
                {
                    .layout_params{
                        .dims = {ruis::dim::fill, ruis::dim::fill},
                        .weight = 1
                    }
                }
            )
        }
    )
// clang-format on
{}

utki::shared_ref<booh::table_tree_view> make::table_tree_view(
	utki::shared_ref<ruis::context> context, //
	booh::table_tree_view::all_parameters params
)
{
	return utki::make_shared<booh::table_tree_view>(
		std::move(context), //
		std::move(params)
	);
}
