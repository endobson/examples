workspace(name = "bes_example")

new_http_archive(
  name = "googleapis",
  sha256 = "0421e89b76a6fa6f820c39ad365a5e490873ae4c7509c8a53f42671f1e53e1e8",
  urls = ["https://github.com/googleapis/googleapis/archive/220c359ac969c6bbab7a11077b32de2533cc7bad.tar.gz"],
  strip_prefix = "googleapis-220c359ac969c6bbab7a11077b32de2533cc7bad",
  build_file = "BUILD.googleapis",
  workspace_file = "WORKSPACE.googleapis",
)

http_archive(
  name = "com_google_protobuf",
  sha256 = "8b3a82704fbf5202c3bcfbbe6b2eb4d07d85bcb507876aaf60edff751c821854",
  strip_prefix = "protobuf-hack-wkt",
  urls = ["https://github.com/endobson/protobuf/archive/hack-wkt.tar.gz"]
)

http_archive(
  name = "com_google_protobuf_cc",
  sha256 = "8b3a82704fbf5202c3bcfbbe6b2eb4d07d85bcb507876aaf60edff751c821854",
  strip_prefix = "protobuf-hack-wkt",
  urls = ["https://github.com/endobson/protobuf/archive/hack-wkt.tar.gz"]
)


# Bind rules for grpc
bind(
    name = "protobuf",
    actual = "@com_google_protobuf//:protobuf",
)

bind(
    name = "protobuf_clib",
    actual = "@com_google_protobuf//:protoc_lib",
)

bind(
    name = "libssl",
    actual = "@boringssl//:ssl",
)

bind(
    name = "zlib",
    actual = "@zlib//:z",
)


http_archive(
  name = "grpc",
  sha256 = "f0143c99942f47986713a92fca43b2fe8441e46f30caea32c9430f31600a9808",
  strip_prefix = "grpc-1.6.0",
  urls = ["https://github.com/grpc/grpc/archive/v1.6.0.tar.gz"]
)

http_archive(
  name = 'boringssl',
  sha256 = "6186514a059ea7e111d8c7fac4bbe0b192cee518d739b369d43afc8d7c799e07",
  strip_prefix = "boringssl-74ffd81aa7ec3d0aa3d3d820dbeda934958ca81a",
  urls = ["https://github.com/google/boringssl/archive/74ffd81aa7ec3d0aa3d3d820dbeda934958ca81a.tar.gz"]
)

new_http_archive(
  name = 'zlib',
  sha256 = "629380c90a77b964d896ed37163f5c3a34f6e6d897311f1df2a7016355c45eff",
  strip_prefix = "zlib-1.2.11",
  urls = ["https://github.com/madler/zlib/archive/v1.2.11.tar.gz"],
  build_file = "@grpc//:third_party/zlib.BUILD"
)
