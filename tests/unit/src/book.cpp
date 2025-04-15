#include <booh/model/book.hpp>
#include <papki/fs_file.hpp>
#include <tst/check.hpp>
#include <tst/set.hpp>

namespace {
const tst::set set("book", [](tst::suite& suite) {
	suite.add("load__basic", []() {
		auto b = booh::book::load(papki::fs_file("samples/book/basic.booh"));

		tst::check_eq(b.get_num_accounts(), size_t(3), SL);
	});
});
} // namespace