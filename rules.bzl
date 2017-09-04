
my_provider = provider()

def _my_rule_impl(ctx):
  return [my_provider()]

my_rule = rule(
  implementation = _my_rule_impl,
  attrs = {
    "deps": attr.label_list(
      providers = [my_provider]
    )
  }
)
