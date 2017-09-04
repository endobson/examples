load(":test.bzl", "test_rule")

cc_library(
  name = "bar",
  srcs = ["bar.c"]
)

test_rule(
  name = "test",
  deps = ["@other//:foo"]
)

test_rule(
  name = "test2",
  deps = ["//:bar"]
)


