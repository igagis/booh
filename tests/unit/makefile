include prorab.mk
include prorab-test.mk
include prorab-clang-format.mk

$(eval $(call prorab-config, ../../config))

this_name := tests

this_srcs := $(call prorab-src-dir, src)

this_cxxflags += -isystem ../../src/
this__libbooh := ../../src/out/$(c)/libbooh.a
this_ldlibs += $(this__libbooh)

this_ldlibs += -l tst -l utki -l papki

this_no_install := true

$(eval $(prorab-build-app))

this_test_cmd := $(prorab_this_name) --jobs=auto --junit-out=out/junit.xml
this_test_deps := $(prorab_this_name)
this_test_ld_path := ../../src/out/$(c)

$(eval $(prorab-test))

this_src_dir := src
$(eval $(prorab-clang-format))

$(eval $(call prorab-include, ../../src/makefile))
