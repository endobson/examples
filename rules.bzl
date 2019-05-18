
def _my_rule_impl(ctx):
  runfiles_var = "bogus"
  return [DefaultInfo(data_runfiles=runfiles_var)]

my_rule = rule(
  implementation = _my_rule_impl,
)
