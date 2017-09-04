
def _test_impl(ctx):
  file = ctx.attr.deps[0].files.to_list()[0]
  print(file.path)
  print(file.root.path)
  print(file.short_path)
  pass


test_rule = rule(
  implementation = _test_impl,
  attrs = {
    "deps": attr.label_list()
  }
)
