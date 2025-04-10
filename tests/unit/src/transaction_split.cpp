#include <booh/luid.hpp>
#include <booh/model/account.hpp>
#include <booh/model/transaction.hpp>
#include <tst/check.hpp>
#include <tst/set.hpp>

namespace {
const tst::set set("transaction_split", [](tst::suite& suite) {
	suite.add("constructor", []() {
		booh::account a;

		booh::transaction_split ts;

		// TODO: check something
	});
});
} // namespace