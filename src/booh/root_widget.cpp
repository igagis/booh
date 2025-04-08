#include "root_widget.hpp"

#include <ruis/widget/container.hpp>

#include "style.hpp"

using namespace booh;

utki::shared_ref<ruis::widget> booh::make_root_widget(const utki::shared_ref<ruis::context>& c)
{
	// TODO:
	return m::container(c, {}, {});
}
