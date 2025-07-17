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

#include "book.hpp"

#include <utki/unicode.hpp>

#include "../util.hpp"

using namespace std::string_view_literals;

using namespace booh;

book book::load(const papki::file& fi)
{
	return load(tml::read(fi));
}

book book::load(const tml::forest& desc)
{
	if (desc.empty()) {
		throw std::invalid_argument("book::load(forest): given book description is empty");
	}

	auto i = desc.begin();

	// check booh tag
	{
		ASSERT(i != desc.end())
		if (i->value != "booh") {
			throw std::invalid_argument(
				"booh::load(forest): given book description does not have 'booh' as its first element"
			);
		}
	}

	++i;

	// check version
	{
		ASSERT(i != desc.end())
		if (i->value != "version"sv) {
			throw std::invalid_argument(
				"book::load(forest): given book description does not have 'version' as first element"
			);
		}

		auto ver = get_tml_property_value(*i);
		if (ver != "0"sv) {
			throw std::invalid_argument(
				utki::cat(
					"book::load(forest): unsupported file format version: ", //
					ver.string
				)
			);
		}
	}

	++i;

	book ret;

	// accounts
	{
		if (i->value != "accounts"sv) {
			throw std::invalid_argument(
				utki::cat(
					"unexpected tml node. expected: accounts. found: ", //
					i->value.string
				)
			);
		}

		ret.add_accounts(i->children);
	}

	++i;

	// accounts_tree
	{
		if (i->value != "accounts_tree"sv) {
			throw std::invalid_argument(
				utki::cat(
					"unexpected tml node. expected: accounts_tree. found: ", //
					i->value.string
				)
			);
		}

		ret.add_accounts_tree(i->children);
	}

	// TODO:

	return ret;
}

void book::save(papki::file& fi) const
{
	// TODO:
}

void book::add_accounts(const tml::forest& desc)
{
	ASSERT(this->accounts.empty())

	for (const auto& a : desc) {
		if (a.value != "a"sv) {
			throw std::invalid_argument("unexpected account node");
		}

		this->add_account(a.children);
	}
}

bool fill_account_tree_node_values(const tml::tree& prop, account_tree_node& atn)
{
	if (prop == "name"sv) {
		atn.name = utki::to_utf32(get_tml_property_value(prop).string);
	} else if (prop == "desc"sv) {
		atn.description = utki::to_utf32(get_tml_property_value(prop).string);
	} else if (prop == "reversed"sv) {
		atn.is_reversed = get_tml_property_value(prop).to_bool();
	} else {
		return false;
	}

	return true;
}

void book::add_account(const tml::forest& desc)
{
	auto acc = utki::make_shared<account>();

	auto& a = acc.get();

	for (const auto& e : desc) {
		if (fill_account_tree_node_values(e, a)) {
			continue;
		}

		if (e == "quantity"sv) {
			a.is_quantity = get_tml_property_value(e).to_bool();
		}
	}

	this->accounts.push_back(std::move(acc));
}

utki::shared_ref<account_tree_node> book::read_account_tree_node(const tml::tree& desc)
{
	if (desc.value == "a"sv) {
		auto index = get_tml_property_value(desc).to_uint32();
		return this->accounts.at(index);
	} else if (desc.value == "g"sv) {
		return this->read_account_tree_node_group(desc.children);
	}

	throw std::invalid_argument(
		utki::cat("book::read_account_tree_node(): unknown account tree node type: ", desc.value.string)
	);
}

utki::shared_ref<account_tree_node_group> book::read_account_tree_node_group(const tml::forest& desc)
{
	auto ret = utki::make_shared<account_tree_node_group>();

	for (const auto& n : desc) {
		if (fill_account_tree_node_values(n, ret.get())) {
			continue;
		}

		if (n == "children"sv) {
			auto& children = ret.get().get_children();
			for (const auto& c : n.children) {
				children.push_back(this->read_account_tree_node(c));
			}
		}
	}

	return ret;
}

void book::add_accounts_tree(const tml::forest& desc)
{
	ASSERT(this->root_accounts.is_group())
	ASSERT(this->root_accounts.get_children().empty())

	for (const auto& node : desc) {
		this->root_accounts.get_children().push_back(read_account_tree_node(node));
	}
}
