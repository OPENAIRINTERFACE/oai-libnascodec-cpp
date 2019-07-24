cc_library(
    name = "nascodec-cpp",
    srcs = glob(["src/**/*.cpp"]),
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
)

cc_binary(
    name = "example",
    srcs = ["example/example.cpp"],
    deps = [":nascodec-cpp"],
)
