#pragma once

#include <ruis/widget/widget.hpp>

namespace booh {

utki::shared_ref<ruis::widget> make_root_widget(const utki::shared_ref<ruis::context>& c);

} // namespace booh
