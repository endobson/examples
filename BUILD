load("//:rules.bzl", base_rule = "my_rule")
load("@my_workspace//:rules.bzl", remote_rule = "my_rule")


base_rule(
  name = "base1",
)

base_rule(
  name = "base2",
  deps = ["base1"],
)

remote_rule(
  name = "remote1",
)

remote_rule(
  name = "remote2",
  deps = ["remote1"],
)

remote_rule(
  name = "remote3",
  deps = ["base1"],
)

base_rule(
  name = "base3",
  deps = ["remote1"],
)
