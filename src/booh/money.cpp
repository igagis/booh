#include "money.hpp"

using namespace booh;

money money::make_cents(int64_t cents)
{
	return money(cents);
}
