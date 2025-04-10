#include <booh/luid.hpp>
#include <tst/check.hpp>
#include <tst/set.hpp>

namespace {
const tst::set set("luid", [](tst::suite& suite) {
	suite.add("luid_generator__make", []() {
		booh::luid_generator gen;

		auto id0 = gen.make();

		tst::check_eq(id0.get(), uint32_t(0), SL);

		auto id1 = gen.make();

		tst::check_eq(id1.get(), uint32_t(1), SL);

		auto id2 = gen.make();

		tst::check_eq(id2.get(), uint32_t(2), SL);
	});
});
} // namespace