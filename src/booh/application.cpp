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

#include "application.hpp"

#include <iomanip>

#include <clargs/parser.hpp>
#include <papki/fs_file.hpp>
#include <utki/debug.hpp>

using namespace std::string_literals;
using namespace std::string_view_literals;

using namespace booh;

application::application(bool window, std::string_view res_path)
    : ruisapp::application( //
          "booh"s,
          []() {
            // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
            ruisapp::window_params wp(r4::vector2<unsigned>(1024, 600));
            return wp;
          }()),
      res_path(papki::as_dir(res_path))
{
	this->set_fullscreen(!window);

	this->gui.init_standard_widgets(*this->get_res_file());

	this->gui.context.get().loader().mount_res_pack(*this->get_res_file(this->res_path));

	// auto c = make_root_widget(this->gui.context);
	// this->gui.set_root(c);
}

std::unique_ptr<application> booh::make_application(
	std::string_view executable, //
	utki::span<const char*> args
)
{
	bool window = false;
	bool help = false;

	std::string res_path = []() {
		papki::fs_file local_share("/usr/local/share/booh/"sv);

		if (local_share.exists()) {
			return local_share.path();
		}

		return "/usr/share/booh/"s;
	}();

	clargs::parser p;

	p.add("help"s, "print command line interface help"s, [&]() {
		help = true;
	});

	p.add("window", "run in window mode", [&]() {
		window = true;
	});

	p.add("res-path", "resources path, default = /usr/share/booh/", [&](std::string_view v) {
		res_path = v;
	});

	p.parse(args);

	if (help) {
		std::cout << p.description() << std::endl;
		return nullptr;
	}

	return std::make_unique<application>(window, res_path);
}
