load("//:libnas-cpp.bzl", "extract_binary_names")

# build library

cc_library(
    name = "nascodec-cpp",
    srcs = glob(["src/**/*.cpp"]),
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
)


# build examples

[ cc_binary(
    name = files[1],
    srcs = [files[0]],
    deps = [":nascodec-cpp"]
        )
for files in extract_binary_names(glob(["example/**/*.cpp"])) ]

# test examples

[ sh_test(
    name = files[1] + "_test",
    srcs = [ ":" + files[1]],
) for files in extract_binary_names(glob(["example/**/*.cpp"])) ]