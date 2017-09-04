def _my_rule_impl(ctx):
  out_file = ctx.actions.declare_file(ctx.label.name)

  args = ctx.actions.args()

  ctx.actions.run_shell(
    outputs = [out_file],
    arguments = args,
    command = 'echo "foo" > %s'
      % (out_file.path),
  )

  return [DefaultInfo(files=depset([out_file]))]

my_rule = rule(
  implementation = _my_rule_impl,
  attrs = {}
)
